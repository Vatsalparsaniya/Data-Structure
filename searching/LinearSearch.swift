import Foundation

func linearSearch<T: Equatable>(array: [T], target: T ) -> Int? {
    for (index, item) in array.enumerated() {
        if item == target {
            return index
        }
    }
    return -1
}

var arr = [23,35,23,346,457,3,36,2365]

print("Array: \(arr)")
print("linear Search index: \(linearSearch(array: arr, target: 3) ?? -1)")