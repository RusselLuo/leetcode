package main

import (
	"fmt"
)

func findTargetSumWays(nums []int, S int) int {
	var helper func(int, int) int
	helper = func(target int, curr int) int {
		if curr == -1 {
			if target == 0 {
				return 1
			} else {
				return 0
			}
		}
		return helper(target+nums[curr], curr-1) + helper(target-nums[curr], curr-1)
	}
	return helper(S, len(nums)-1)
}

func main() {
	fmt.Println(findTargetSumWays([]int{1, 1, 1, 1, 1}, 3))
}
