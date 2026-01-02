package test

type Category struct {
	Name       string   `json:"name"`
	TestFiles  []string `json:"test_files"`
	Categories string   `json:"categories"`
}
