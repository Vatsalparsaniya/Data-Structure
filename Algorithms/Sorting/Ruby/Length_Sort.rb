arr = ["words", "examples", "here"]

puts arr

sorted_arr = arr.sort_by { |word| word.length}

puts sorted_arr