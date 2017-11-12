package main

import (
	"encoding/xml"
	"flag"
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"path"
	"strings"
)

type fieldDefinition struct {
	Name  string `xml:"name,attr"`
	Type  string `xml:"type,attr"`
	Array int    `xml:"array,attr"`
}

type structDefinition struct {
	Name   string            `xml:"name,attr"`
	Fields []fieldDefinition `xml:"field"`
}

type chrDefinition struct {
	XMLName xml.Name           `xml:"chr"`
	Structs []structDefinition `xml:"structs>struct"`
	Fields  []fieldDefinition  `xml:"fields>field"`
}

type chrWriter interface {
	RootBegin(f *os.File)
	RootEnd(f *os.File)

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
	outDir := flag.String("o", ".", "output to the dir")
	flag.Parse()

	if *chrDefXML == "" || *outDir == "" {
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

	log.Println("XMLLName:", chrDef.XMLName)

	(&chrDef).save(*outDir)
}

func (c *chrDefinition) save(dir string) {
	structFile := path.Join(dir, "chr_mmtel.inc")
	encodeFile := path.Join(dir, "chr_encode_mmtel.inc")

	var sw chrStructWriter
	var ew chrEncoderWriter

	c.writeToFile(&sw, structFile, "chr_mmtel")
	c.writeToFile(&ew, encodeFile, "")
}

func (c *chrDefinition) writeToFile(w chrWriter, file string, structName string) error {
	f, err := os.Create(file)
	if err != nil {
		return err
	}
	defer f.Close()

	for _, sd := range c.Structs {
		sd.writeToFile(w, f)
		f.WriteString("\n")
	}

	w.RootBegin(f)

	for _, fd := range c.Fields {
		fd.writeToFile(w, f)
	}

	w.RootEnd(f)

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

func (w *chrStructWriter) RootBegin(f *os.File) {
	f.WriteString("typedef struct chr_mmtel" + "\n")
	f.WriteString("{\n")
}

func (w *chrStructWriter) RootEnd(f *os.File) {
	f.WriteString("} " + strings.ToUpper("chr_mmtel") + ";\n")
}

func (w *chrStructWriter) StructBegin(f *os.File, s *structDefinition) {
	f.WriteString("typedef struct " + s.Name + "\n")
	f.WriteString("{\n")
}

func (w *chrStructWriter) StructEnd(f *os.File, sd *structDefinition) {
	f.WriteString("} " + sd.Name + ";\n")
}

func (w *chrStructWriter) WriteField(f *os.File, fd *fieldDefinition) {
	out := fmt.Sprintf("%s%-16s%s%s", "    ", fd.Type, "    ", fd.Name)

	if fd.Array > 0 {
		out = fmt.Sprintf("%s[%d]", out, fd.Array)
	}

	out += ";\n"

	f.WriteString(out)
}

func (w *chrEncoderWriter) RootBegin(f *os.File) {
	f.WriteString("CHR_ENC_BEGIN(ptChrMsg, ptJson)" + "\n")
}

func (w *chrEncoderWriter) RootEnd(f *os.File) {
	f.WriteString("CHR_ENC_END()\n")
}

func (w *chrEncoderWriter) StructBegin(f *os.File, s *structDefinition) {
	out := fmt.Sprintf("CHR_ENC_STRUCT_BEGIN(%s)\n", s.Name)
	f.WriteString(out)
}

func (w *chrEncoderWriter) StructEnd(f *os.File, sd *structDefinition) {
	f.WriteString("CHR_ENC_STRUCT_END()\n")
}

func (w *chrEncoderWriter) WriteField(f *os.File, fd *fieldDefinition) {
	out := fd.Name + "\n"

	f.WriteString(out)
}

func getJSONType(ctype string) string {
	jsontype, find := jsonTypeDict[ctype]
	if find {
		return jsontype
	}

	return "OBJECT"
}
