package main

import (
	"bytes"
)

func removeDup(s string) string {
	var ret bytes.Buffer
	last := s[0]
	ret.WriteByte(last)
	for _, c := range s {
		if byte(c) != last {
			last = byte(c)
			ret.WriteByte(last)
		}
	}
	return ret.String()
}

func strangePrinter(s string) int {
	s = removeDup(s)
	mem := make([][]int, len(s))
	for i := 0; i < len(s); i++ {
		mem[i] = make([]int, len(s))
	}
	for i := 0; i < len(s); i++ {
		mem[i][i] = 1
	}
	for i := 0; i < len(s); i++ {
		for k := 0; k < i; k++ {

		}
	}
	return 1
}

func main() {
}
