object KadanesAlgorithm {
    /**
     * **Time**: `O(n)`
     *
     * **Space**: `O(1)`
     */
    fun maxSubArray(nums: IntArray): Int {
        var maxSoFar = nums[0]
        var maxEndingHere = nums[0]

        (1..nums.lastIndex).forEach { i ->
            maxEndingHere = max(nums[i], maxEndingHere + nums[i])
            maxSoFar = max(maxSoFar, maxEndingHere)
        }

        return maxSoFar
    }
}