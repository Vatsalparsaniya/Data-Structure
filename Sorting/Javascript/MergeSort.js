/**
 * The algorithm that comes with the popular phrase "Divide and conquer"
 * It divides input array in two halves, calls itself for the two halves and then merges
 * the two sorted halves. The merge() function is used for merging two halves.
 */

// Split the array into halves and merge them recursively
function mergeSort(array) {
  if (array.length === 1) return array;

  const middle = Math.floor(array.length / 2);
  const left = array.slice(0, middle);
  const right = array.slice(middle);

  return merge(mergeSort(left), mergeSort(right));
}

// Compare the arrays item by item and return the concatenated result
function merge(left, right) {
  let result = [];
  let indexLeft = 0;
  let indexRight = 0;

  while (indexLeft < left.length && indexRight < right.length) {
    if (left[indexLeft] < right[indexRight]) {
      result.push(left[indexLeft]);
      indexLeft++;
    } else {
      result.push(right[indexRight]);
      indexRight++;
    }
  }

  return result.concat(left.slice(indexLeft)).concat(right.slice(indexRight));
}

const arrayOfNumbers = [2, 5, 1, 3, 7, 4, 2, 3, 9, 8, 6, 3];
const anotherArrayOfNumbers = [33, 1, 5, 4, 8, 56, 443, 2818, 218, 2, 8, 23];
console.log(mergeSort(arrayOfNumbers)); // [1, 2, 2, 3, 3, 3, 4, 5, 6, 7, 8, 9]
console.log(mergeSort(arrayOfNumbers)); // [ 1, 2, 4, 5, 8, 8, 23, 33, 56, 218, 443, 2818 ]
