import os
import arrays
import math

fn main() {
	filename := "input.txt"

	lines := os.read_lines(filename)!

	mut sum := 0

	for line in lines {
		split := line.substr(9, line.len).replace("  ", " ").trim_space().split(" | ")
		win := split[0].split(" ")
		nums := split[1].split(" ")
		
		mut count := 0
		for num in nums {
			if num in win {
				count += 1
			}
		}

		if count > 0 {
			mut value := 1
			for i in 0..count-1 {
				value *= 2
			}
			// println(value)
			sum += value
		}
	}

	println(sum)
}