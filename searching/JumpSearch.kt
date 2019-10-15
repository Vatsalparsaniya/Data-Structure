package hacktoberfest

/**
 * Jump Search implementation in Kotlin
 * Assumes that the array is already sorted
 * Time Complexity - O(sqrt(n))
 */

object JumpSearch {

    /**
     * Searching for an element in a sorted array using jump search
     * @param arr integer array in which we have to search
     * @param x integer element to be searched
     * @return index of element if it exists in the array, -1 otherwise
     */
    private fun jumpSearch(arr: IntArray, x: Int): Int {

        val n = arr.size

        // Finding step size to be jumped
        var step = kotlin.math.floor(kotlin.math.sqrt(n.toDouble())).toInt()

        // Finding the block where element is present (if it is present), else return -1
        var prev = 0
        while (arr[kotlin.math.min(step, n) - 1] < x) {
            prev = step
            step += kotlin.math.floor(kotlin.math.sqrt(n.toDouble())).toInt()
            if (prev >= n)
                return -1
        }

        // Doing a linear search for x in the block
        while (arr[prev] < x) {
            prev++

            // If we reached next block, element is not present.
            if (prev == kotlin.math.min(step, n))
                return -1
        }

        return if (arr[prev] == x) prev else -1

    }

    @JvmStatic
    fun main(args: Array<String>) {

        val arr = intArrayOf(0, 1, 2, 4, 8, 17, 29, 34, 53, 73, 88, 108, 145)
        val x = 53

        val index = jumpSearch(arr, x)

        if (index != -1)
            println("\n$x is located at index $index")
    }
}
