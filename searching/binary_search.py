def binarySearch(arr, l, r, x):
	if r >= l:
		mid = l + (r - l)//2
		if arr[mid] == x:
			return mid
		elif arr[mid] > x:
			return binarySearch(arr, l, mid-1, x)
		else:
			return binarySearch(arr, mid + 1, r, x)
	else:
		return -1

print("Enter elements of list as space seperated integers:")
a = list(map(int, input().split()))
x = int(input("Enter the element to be searched in the list: "))
index = binarySearch(a, 0, len(a)-1, x)
if index == -1:
	print("Number not in list")
else:
	print("The Number is present at index {}".format(index))