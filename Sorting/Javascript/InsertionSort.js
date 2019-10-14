/**
 * Insertion sort algorithm iterates, consuming one input element each repetition,
 * and growing a sorted output list. Each iteration removes one element
 * from the input data, finds the location it belongs within the sorted list,
 * and inserts it there. It repeats until no input elements remain.
 * From Wikipedia
 */

// array to sort
const array = [9, 221, 25, 6, 41, 3, 7, 17, 11, 10, 1, 8, 55];

//ES6 version
const insertionSort = array => {
  array.forEach((element, index) => {
    let temp = element;
    let target = index - 1;
    while (target >= 0 && array[target] > temp) {
      array[target + 1] = array[target];
      target--;
    }
    array[target + 1] = temp;
  });

  return array;
};

console.log(insertionSort(array)); // => [ 1, 3, 6, 7, 8, 9, 10, 11, 17, 25, 41, 55, 221 ]
