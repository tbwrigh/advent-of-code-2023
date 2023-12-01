file_path = 'input.txt'
file_contents = File.read(file_path)

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
