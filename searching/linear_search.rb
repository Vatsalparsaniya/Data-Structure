def linear_search(arr, key)
  arr.each_with_index do |el, index|
    if el == key
      return index
    end
  end
  return -1
end

arr = Array.new
puts "Enter the size of Array"
n = gets.chomp().to_i

puts ("Enter the " + n.to_s + " elements in the array.")
for i in 0..(n)-1
  x = gets.chomp()
  arr.push(x)
end

puts "Enter the element to be searched : "
key = gets.chomp()

result = linear_search(arr, key)

result != -1 ? (puts "Element found at location " + result.to_s) : (puts "Element not found")
