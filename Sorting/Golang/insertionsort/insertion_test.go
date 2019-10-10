package insertionsort

import (
	"reflect"
	"testing"
)

func TestInsertionSort(t *testing.T) {
	testCases := []struct {
		in  []int
		exp []int
	}{
		{
			in:  []int{1, 2, 3, 4, 5},
			exp: []int{1, 2, 3, 4, 5},
		},
		{
			in:  []int{1, 2, 1, 5, 4},
			exp: []int{1, 1, 2, 4, 5},
		},
		{
			in:  []int{5, 4, 3, 2, 1},
			exp: []int{1, 2, 3, 4, 5},
		},
	}
	for _, tC := range testCases {
		t.Run("", func(t *testing.T) {
			actual := InsertionSort(tC.in)
			if !reflect.DeepEqual(actual, tC.exp) {
				t.Errorf("expected %v but got %v", tC.exp, tC.in)
			}
		})
	}
}
