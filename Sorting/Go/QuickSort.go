// quicksort.go

package main

import "fmt"

// arr = array
// low = starting index
// high = ending index
func main() {
	arr := []int{1, 2, 10, 3, 5}
	quickSort(arr)
	fmt.Println(arr)
}

func quickSort(arr []int) []int {
	sort(arr, 0, len(arr)-1)

	return arr
}

func sort(arr []int, low, high int) {
	if low < high {
		partitionIndex := partition(arr, low, high)
		sort(arr, low, partitionIndex-1)
		sort(arr, partitionIndex+1, high)
	}
}

func partition(arr []int, low, high int) int {
	pivot := arr[high]
	i := low - 1
	for j := low; j < high; j++ {
		if arr[j] <= pivot {
			i++
			arr[i], arr[j] = arr[j], arr[i]
		}
	}
	arr[i+1], arr[high] = arr[high], arr[i+1]

	return i + 1
}
