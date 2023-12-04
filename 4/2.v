import os
import arrays
import math

fn main() {
	filename := "input.txt"

	lines := os.read_lines(filename)!

	mut card_map := []int{len: lines.len, init: 1}

	mut cards := 0

	mut counter := 0

	for line in lines {
		split := line.substr(9, line.len).replace("  ", " ").trim_space().split(" | ")
		win := split[0].split(" ")
		nums := split[1].split(" ")

		mut wins := 0
		
		for num in nums {
			if num in win {
				wins += 1
			}
		}

		for i in counter+1..counter+1+wins {
			card_map[i] += card_map[counter]
		}
		cards += card_map[counter]
		counter += 1
	}

	println(cards)
}