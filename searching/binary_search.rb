def binary_search(arr, low, high, key)
  if low <= high
    mid = (high+low)/2
    if arr[mid] == key
      return mid
    elsif arr[mid] > key
      return binary_search(arr, low, mid-1, key)
    else
      return binary_search(arr, mid+1, high, key)
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

result = binary_search(arr, 0, n-1, key)

result != -1 ? (puts "Element found at location " + result.to_s) : (puts "Element not found")