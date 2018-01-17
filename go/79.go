package main

import (
	"fmt"
)

type grid struct {
	row int
	col int
}

func exist(board [][]byte, word string) bool {
	m := make(map[grid]bool, 0)
	queue, tempQ := make(chan grid, 1000), make(chan grid, 1000)
	width, height := len(board), len(board[0])
	for step, c := range word {
		if step == 0 {
			for row, x := range board {
				for col, y := range x {
					if y == byte(c) {
						if row != 0 {
							g := grid{row - 1, col}
							queue <- g
						}
						if row != width-1 {
							g := grid{row + 1, col}
							queue <- g
						}
						if col != 0 {
							g := grid{row, col - 1}
							queue <- g
						}
						if col != height-1 {
							g := grid{row, col + 1}
							queue <- g
						}
						m[grid{row, col}] = true
					}
				}
			}
		} else {
			matched := false
			for len(queue) != 0 {
				g := <-queue
				x, y := g.row, g.col
				if board[x][y] == byte(c) {
					m[grid{x, y}] = true
					matched = true
					if x != 0 {
						g := grid{x - 1, y}
						_, ok := m[g]
						if !ok {
							tempQ <- g
						}
					}
					if x != width-1 {
						g := grid{x + 1, y}
						_, ok := m[g]
						if !ok {
							tempQ <- g
						}
					}
					if y != 0 {
						g := grid{x, y - 1}
						_, ok := m[g]
						if !ok {
							tempQ <- g
						}
					}
					if y != height-1 {
						g := grid{x, y + 1}
						_, ok := m[g]
						if !ok {
							tempQ <- g
						}
					}
				}
			}
			queue = tempQ
			if step == len(word) && matched {
				return true
			}
			if len(tempQ) == 0 {
				return false
			}
			tempQ = make(chan grid, 1000)
		}
	}
	return true
}

func main() {
	fmt.Println(exist([][]byte{{'A', 'B', 'C', 'A'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "ABC"))
}
