package main

import (
	"encoding/xml"
	"flag"
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"path/filepath"
	"strings"
)

type fieldDefinition struct {
	Name      string `xml:"name,attr"`
	Type      string `xml:"type,attr"`
	Array     int    `xml:"array,attr"`
	IsPadding bool   `xml:"ispadding,attr"`
	Comment   string `xml:"comment,attr"`
}

type structDefinition struct {
	Name   string            `xml:"name,attr"`
	Fields []fieldDefinition `xml:"field"`
}

type chrDefinition struct {
	XMLName xml.Name           `xml:"chr"`
	Name    string             `xml:"name,attr"`
	Structs []structDefinition `xml:"structs>struct"`
	Fields  []fieldDefinition  `xml:"fields>field"`
}

type chrWriter interface {
	PreWrite(f *os.File, cd *chrDefinition)
	PostWrite(f *os.File, cd *chrDefinition)

	RootBegin(f *os.File, cd *chrDefinition)
	RootEnd(f *os.File, cd *chrDefinition)

	StructBegin(f *os.File, s *structDefinition)
	StructEnd(f *os.File, s *structDefinition)

	WriteField(f *os.File, field *fieldDefinition)
}

type chrStructWriter struct {
	chrWriter
}

type chrEncoderWriter struct {
	chrWriter
}

var jsonTypeDict = map[string]string{"BYTE": "NUMBER", "WORD16": "NUMBER", "WORD32": "NUMBER", "CHAR": "STRING"}

func main() {
	chrDefXML := flag.String("if", "", "chr definition xml")
	outStructFile := flag.String("struct", ".", "output to the struct definition file")
	outEncodeFile := flag.String("encode", ".", "output to the encode source file")
	flag.Parse()

	if *chrDefXML == "" || *outStructFile == "" || *outEncodeFile == "" {
		flag.Usage()
		return
	}

	var chrDef chrDefinition

	content, err := ioutil.ReadFile(*chrDefXML)
	if err != nil {
		log.Fatal("read chr def xml failed, error:", err.Error())
		return
	}

	//log.Println("chr def xml:", string(content))

	err = xml.Unmarshal(content, &chrDef)
	if err != nil {
		log.Fatal("decode chr def xml file failed, error:", err.Error())
		return
	}

	log.Println("XMLLName:", chrDef.XMLName, ",chr name:", chrDef.Name)

	(&chrDef).save(*outStructFile, *outEncodeFile)
}

func (c *chrDefinition) save(structFile string, encodeFile string) {
	var sw chrStructWriter
	var ew chrEncoderWriter

	c.writeToFile(&sw, structFile)
	c.writeToFile(&ew, encodeFile)
}

func (c *chrDefinition) writeToFile(w chrWriter, file string) error {
	f, err := os.Create(file)
	if err != nil {
		return err
	}
	defer f.Close()

	w.PreWrite(f, c)

	for _, sd := range c.Structs {
		sd.writeToFile(w, f)
		f.WriteString("\n")
	}

	w.RootBegin(f, c)

	for _, fd := range c.Fields {
		fd.writeToFile(w, f)
	}

	w.RootEnd(f, c)

	w.PostWrite(f, c)

	return nil
}

func (sd *structDefinition) writeToFile(w chrWriter, f *os.File) {
	w.StructBegin(f, sd)

	for _, fd := range sd.Fields {
		fd.writeToFile(w, f)
	}
	w.StructEnd(f, sd)
}

func (fd *fieldDefinition) writeToFile(w chrWriter, f *os.File) {
	w.WriteField(f, fd)
}

func (w *chrStructWriter) PreWrite(f *os.File, cd *chrDefinition) {
	fileName := filepath.Base(f.Name())
	log.Println("fileName:", fileName)

	macro := strings.ToUpper(strings.Replace(fileName, ".", "_", -1))
	out := fmt.Sprintf("#ifndef %s\n", macro)
	out += fmt.Sprintf("#define %s\n", macro)
	out += "\n"

	out += fmt.Sprintf("/* %s */\n", fileName)
	out += "/* 本文件是通过工具自动生成，请勿手工修改 */\n\n"
	out += `#include "tulip.h"`
	out += "\n\n\n"

	f.WriteString(out)
}

func (w *chrStructWriter) PostWrite(f *os.File, cd *chrDefinition) {
	out := "\n\n\n"

	fileName := filepath.Base(f.Name())
	macro := strings.ToUpper(strings.Replace(fileName, ".", "_", -1))
	out += fmt.Sprintf("#endif /* %s */\n", macro)
	out += "\n"

	out += "/* The End Of The File. */\n\n"

	f.WriteString(out)
}

func (w *chrStructWriter) RootBegin(f *os.File, cd *chrDefinition) {
	out := fmt.Sprintf("typedef struct %s\n", cd.Name)
	out += "{\n"

	f.WriteString(out)
}

func (w *chrStructWriter) RootEnd(f *os.File, cd *chrDefinition) {
	f.WriteString("} " + strings.ToUpper(cd.Name) + ";\n")
}

func (w *chrStructWriter) StructBegin(f *os.File, s *structDefinition) {
	f.WriteString("typedef struct " + s.Name + "\n")
	f.WriteString("{\n")
}

func (w *chrStructWriter) StructEnd(f *os.File, sd *structDefinition) {
	f.WriteString("} " + sd.Name + ";\n")
}

func (w *chrStructWriter) WriteField(f *os.File, fd *fieldDefinition) {
	out := fmt.Sprintf("%s%-24s%s%s", "    ", fd.Type, "    ", fd.Name)

	if fd.Array > 0 {
		out = fmt.Sprintf("%s[%d]", out, fd.Array)
	}

	out += ";"

	if fd.Comment != "" {
		out += "    /* " + fd.Comment + " */"
	}

	out += "\n"

	f.WriteString(out)
}

func (w *chrEncoderWriter) PreWrite(f *os.File, cd *chrDefinition) {
	fileName := filepath.Base(f.Name())
	out := fmt.Sprintf("/* %s */\n", fileName)
	out += "/* 本文件是通过工具自动生成，请勿手工修改 */"
	out += "\n\n\n"

	f.WriteString(out)
}

func (w *chrEncoderWriter) PostWrite(f *os.File, cd *chrDefinition) {
	out := "\n\n\n"
	out += "/* The End Of The File. */\n\n"

	f.WriteString(out)
}

func (w *chrEncoderWriter) RootBegin(f *os.File, cd *chrDefinition) {
	f.WriteString("CHR_ENC_MMTEL_BEGIN(ptChrData, ptJson)" + "\n")
}

func (w *chrEncoderWriter) RootEnd(f *os.File, cd *chrDefinition) {
	f.WriteString("CHR_END_MMTEL_END\n")
}

func (w *chrEncoderWriter) StructBegin(f *os.File, s *structDefinition) {
	out := fmt.Sprintf("CHR_ENC_STRUCT_BEGIN(ptChrData, %s, ptJson)\n", s.Name)
	f.WriteString(out)
}

func (w *chrEncoderWriter) StructEnd(f *os.File, sd *structDefinition) {
	f.WriteString("CHR_ENC_STRUCT_END\n")
}

func (w *chrEncoderWriter) WriteField(f *os.File, fd *fieldDefinition) {
	if fd.IsPadding {
		return
	}

	out := "    "
	jsonType := getJSONType(fd.Type)
	if fd.Array > 0 && fd.Type != "CHAR" {
		numField := fd.Name + "Num"
		if jsonType == "OBJECT" {
			out += fmt.Sprintf("CHR_ENC_STRUCT_ARRAY(ptChrData, %s, %s, %d, %s, ptJson)", fd.Name, fd.Type, fd.Array, numField)
		} else {
			out += fmt.Sprintf("CHR_ENC_ARRAY(ptChrData, %s, %s, %d, %s, ptJson)", fd.Name, jsonType, fd.Array, numField)
		}
	} else {
		if jsonType == "OBJECT" {
			out += fmt.Sprintf("CHR_ENC_STRUCT(ptChrData, %s, %s, ptJson)", fd.Name, fd.Type)
		} else {
			out += fmt.Sprintf("CHR_ENC_ITEM(ptChrData, %s, %s, ptJson)", fd.Name, jsonType)
		}
	}

	out += "\n"

	f.WriteString(out)
}

func getJSONType(ctype string) string {
	jsontype, find := jsonTypeDict[ctype]
	if find {
		return jsontype
	}

	return "OBJECT"
}
