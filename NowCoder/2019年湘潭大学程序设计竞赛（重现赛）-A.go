package main

import "fmt"

func main() {
	var n1, p1, s1 int
	var n2, p2, s2 int
	fmt.Scanf("%d %d %d", &n1, &p1, &s1)
	fmt.Scanf("%d %d %d", &n2, &p2, &s2)
	if n1 == n2 {
		if p1 == p2 {
			if s1 == s2 {
				fmt.Printf("God\n")
			} else if s1 < s2 {
				fmt.Printf("1\n")
			} else {
				fmt.Printf("2\n")
			}
		} else if p1 < p2 {
			fmt.Printf("1\n")
		} else {
			fmt.Printf("2\n")
		}
	} else if n1 > n2 {
		fmt.Printf("1\n")
	} else {
		fmt.Printf("2\n")
	}
}
