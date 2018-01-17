package main

import "fmt"

func getDistance(s1, s2 string) int {
	dis := 0
	for i := 0; i < 8; i++ {
		if s1[i] != s2[i] {
			dis++
		}
	}
	return dis
}

func minMutation(start string, end string, bank []string) int {
	editDis := make([][]string, 9)
	queue := make(chan string, 100)
	visited := make(map[string]bool)
	disMat := make(map[string]int)
	for i := 0; i < 9; i++ {
		editDis[i] = make([]string, 0)
	}
	for _, val := range bank {
		dis := getDistance(end, val)
		editDis[dis] = append(editDis[dis], val)
		visited[val] = false
		disMat[val] = -1
	}
	queue <- start
	visited[start] = true
	disMat[start] = 0
	for len(queue) > 0 {
		curr := <-queue
		dis := getDistance(curr, end)
		if dis+1 < 9 {
			for _, val := range editDis[dis+1] {
				if !visited[val] && getDistance(curr, val) == 1 {
					disMat[val] = disMat[curr] + 1
					visited[val] = true
					queue <- val
				}
			}
		}
		if dis-1 >= 0 {
			for _, val := range editDis[dis-1] {
				if !visited[val] && getDistance(curr, val) == 1 {
					disMat[val] = disMat[curr] + 1
					visited[val] = true
					queue <- val
				}
			}
		}
	}
	// fmt.Println(disMat[end])
	_, ok := disMat[end]
	if !ok {
		fmt.Println(-1)
		return -1
	}
	return disMat[end]
}

func main() {
	minMutation("AACCGGTT", "AACCGGTA", []string{"AACCGGTA"})
}

/*
Use BFS! A connection from A to B exist iff distance of A and B is 1. Do the BFS
along the bank.
*/
