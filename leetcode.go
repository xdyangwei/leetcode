package main

import (
	"strconv"
)

func main() {
	s := "yangwei"
	CreateList(s)
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

//ListNode problem2:两数相加
type ListNode struct {
	Val  int
	Next *ListNode
}

//暴力解法时间复杂度太高
func ListSum(l *ListNode) int {
	sum1 := 0
	index := 1
	for l != nil {
		sum1 += (l.Val * index)
		index *= 10
		l = l.Next
	}
	return sum1
}

func CreateList(str string) *ListNode {
	if len(str) == 0 {
		return nil
	}
	l := new(ListNode)
	l.Val = int(str[0] - '0')
	l.Next = CreateList(str[1:])
	return l
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	sum1 := ListSum(l1)
	sum2 := ListSum(l2)
	sum := sum1 + sum2
	s := strconv.Itoa(sum)
	return CreateList(s)
}
