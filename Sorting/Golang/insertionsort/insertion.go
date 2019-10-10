package insertionsort

func InsertionSort(a []int) []int {
	for i := 1; i < len(a); i++ {
		n := a[i]
		j := i
		for j > 0 && a[j-1] > n {
			a[j] = a[j-1]
			j--
		}
		a[j] = n
	}
	return a
}
