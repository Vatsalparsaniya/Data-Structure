def binarysearch(l ,val):
	lowerlimit = 0
	upperlimit = len(l)-1

	while lowerlimit <= upperlimit:
		mid = (lowerlimit + upperlimit) // 2

		if l[mid] == val:
			print(f"{val} is found at {mid} ")
		if val > l[mid] :
			lowerlimit = mid + 1
		else:
			upperlimit = mid - 1

	if lowerlimit > upperlimit:
		print(f"{val} not in list")
		return

l = [2,4,6,8,10,21,43,56,65,75]
val = 4
binarysearch(l,val)