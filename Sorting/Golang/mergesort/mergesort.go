package mergesort

func mergeSort(l []int) []int {
	if len(l) < 2 {
		return l
	}
	mid := len(l) / 2
	a := mergeSort(l[:mid])
	b := mergeSort(l[mid:])
	return merge(a, b)
}

func merge(left, right []int) []int {
	var i, j int
	result := make([]int, len(left)+len(right))

	for i < len(left) && j < len(right) {
		if left[i] <= right[j] {
			result[i+j] = left[i]
			i++
		} else {
			result[i+j] = right[j]
			j++
		}
	}

	for i < len(left) {
		result[i+j] = left[i]
		i++
	}
	for j < len(right) {
		result[i+j] = right[j]
		j++
	}
	return result
}
