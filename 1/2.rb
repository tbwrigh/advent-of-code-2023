file_path = 'input.txt'
file_contents = File.read(file_path)

# replace file contents substr 
file_contents.gsub! 'one', 'one1one'
file_contents.gsub! 'two', 'two2two'
file_contents.gsub! 'three', 'three3three'
file_contents.gsub! 'four', 'four4four'
file_contents.gsub! 'five', 'five5five'
file_contents.gsub! 'six', 'six6six'
file_contents.gsub! 'seven', 'seven7seven'
file_contents.gsub! 'eight', 'eight8eight'
file_contents.gsub! 'nine', 'nine9nine'

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
