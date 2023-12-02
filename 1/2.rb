file_path = 'input.txt'
file_contents = File.read(file_path)

# replace file contents substr 
file_contents.gsub! 'one', 'o1e'
file_contents.gsub! 'two', 't2o'
file_contents.gsub! 'three', 't3e'
file_contents.gsub! 'four', 'f4r'
file_contents.gsub! 'five', 'f5e'
file_contents.gsub! 'six', 's6x'
file_contents.gsub! 'seven', 's7n'
file_contents.gsub! 'eight', 'e8t'
file_contents.gsub! 'nine', 'n9e'

lines = file_contents.split("\n")

sum = 0
for i in 0..lines.length-1
    cur_int = ""
    cur_str = ""
    for j in 0..lines[i].length-1
        char = lines[i][j]
        if char.to_i.to_s == char
            cur_int = char

            if cur_str == ""
                cur_str += char
            end
        end
    end 
    cur_str += cur_int

    sum += cur_str.to_i
end

puts sum
