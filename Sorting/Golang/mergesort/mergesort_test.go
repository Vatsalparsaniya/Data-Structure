package mergesort

import (
	"reflect"
	"testing"
)

func TestMergeSort(t *testing.T) {
	actual := mergeSort([]int{1, 2, 68, 2, -1, 41})
	expected := []int{-1, 1, 2, 2, 41, 68}

	if !reflect.DeepEqual(actual, expected) {
		t.Errorf("expected a merge sorted slice, but got %v instead of %v", actual, expected)
	}
}
