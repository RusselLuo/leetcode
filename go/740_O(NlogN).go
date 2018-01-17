package main

import "sort"
import "fmt"

func reduce(nums []int) ([]int, []int) {
	sort.Ints(nums)
	elems, counts := make([]int, 0), make([]int, 0)
	last := 0
	count := -1
	for _, i := range nums {
		if i != last {
			elems = append(elems, i)
			counts = append(counts, 0)
			count++
			last = i
		}
		counts[count]++
	}
	return elems, counts
}
func deleteAndEarn(nums []int) int {
	if len(nums) == 0 {
		return 0
	} else if len(nums) == 1 {
		return nums[0]
	}
	elems, counts := reduce(nums)
	dp := make([]int, len(elems))
	dp[0] = elems[0] * counts[0]
	if elems[1] == elems[0]+1 {
		dp[1] = elems[1] * counts[1]
		if elems[1]*counts[1] < dp[0] {
			dp[1] = dp[0]
		}
	} else {
		dp[1] = elems[1]*counts[1] + dp[0]
	}
	for i := 2; i < len(elems); i++ {
		if elems[i] == elems[i-1]+1 {
			dp[i] = elems[i]*counts[i] + dp[i-2]
			if dp[i] < dp[i-1] {
				dp[i] = dp[i-1]
			}
		} else {
			dp[i] = elems[i]*counts[i] + dp[i-1]
		}
	}
	return dp[len(elems)-1]
}
func main() {

	fmt.Println(deleteAndEarn([]int{8, 10, 4, 9, 1, 3, 5, 9, 4, 10}))
}
