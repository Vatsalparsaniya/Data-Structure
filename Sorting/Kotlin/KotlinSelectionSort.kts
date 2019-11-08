fun selectionSort(arr: Array<Int>): Array<Int> {
    val dataSize = arr.size
    var key = 0
    var prev = 0

    for (current in 1 until dataSize) {
        key = arr[current]
        prev = current - 1
        while (prev >= 0 && arr[prev] > key) {
            arr[prev + 1] = arr[prev]
            prev -= 1
        }

        arr[prev + 1] = key
    }
    return arr
}

fun main() {
    val testCase = arrayOf(5, 3, 4, 2, 1, 10, 9)
    selectionSort(testCase).forEach {
        print("$it ")
    }
}