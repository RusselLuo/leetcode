package main

import (
	"fmt"
)

type grid struct {
	row  int
	col  int
	step int
}

func knightProbability(N int, K int, r int, c int) float64 {
	m := make(map[grid]float64)
	var helper func(int, int, int) float64
	helper = func(row, col, step int) float64 {
		if row < 0 || col < 0 || row >= N || col >= N {
			return 0
		}
		if step == K {
			return 1
		}
		_, ok := m[grid{row, col, step}]
		if !ok {
			m[grid{row, col, step}] = helper(row+1, col+2, step+1)/float64(8) +
				helper(row+2, col+1, step+1)/float64(8) +
				helper(row-1, col-2, step+1)/float64(8) +
				helper(row-2, col-1, step+1)/float64(8) +
				helper(row+1, col-2, step+1)/float64(8) +
				helper(row-1, col+2, step+1)/float64(8) +
				helper(row+2, col-1, step+1)/float64(8) +
				helper(row-2, col+1, step+1)/float64(8)
		}
		return m[grid{row, col, step}]
	}
	return helper(r, c, 0)
}

func main() {
	fmt.Println(knightProbability(3, 2, 0, 0))
}
