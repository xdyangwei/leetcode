package main

import "fmt"

func main() {
	a := []int{2, 7, 11, 15}
	target := 9
	fmt.Println(twoSum(a, target))
}

//problem1：两数之和，暴力解法
func twoSum(nums []int, target int) []int {
	var a []int
	for index, number := range nums {
		for index2, num2 := range nums {
			if (number+num2 == target) && index != index2 {
				a = append(a, index, index2)
				break
			}
		}
		if len(a) != 0 {
			break
		}
	}
	return a
}

//两数之和使用map求解
func twoSum2(nums []int, target int) []int {
	var m = map[int]int{}
	for index, number := range nums {
		if value, ok := m[target-number]; ok {
			return []int{value, index}
		}
		m[number] = index
		//fmt.Println(m)
	}
	return nil
}
