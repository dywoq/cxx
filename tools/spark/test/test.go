package test

import (
	"encoding/json"
	"io"
	"os"
)

type Standard string

type Type string

type Test struct {
	Name            string   `json:"name"`
	Path            string   `json:"path"`
	Standard        Standard `json:"standard"`
	AdditionalFlags []string `json:"additional_flags"`
	Type            Type     `json:"type"`
}

// WithReader populates the Test by decoding JSON data from r.
// It expects r to contain a valid JSON object matching the Test schema.
// Any existing fields in the Test may be overwritten.
func (t *Test) WithReader(r io.Reader) error {
	err := json.NewDecoder(r).Decode(t)
	return err
}

// WithFilepath opens the file at path and populates the Test by decoding
// its JSON contents. The file must contain a valid JSON object matching
// the Test schema.
func (t *Test) WithFilepath(path string) error {
	f, err := os.Open(path)
	if err != nil {
		return err
	}
	defer f.Close()
	return t.WithReader(f)
}

const (
	StandardCxx20 Standard = "cxx20"
)

const (
	TypeCompilePass Type = "compile-pass"
	TypeCompileFail Type = "compile-fail"
	TypePass        Type = "pass"
	TypeFail        Type = "fail"
)
