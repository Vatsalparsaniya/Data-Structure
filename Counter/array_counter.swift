//
//  array_counter.swift
//  
//
//  Created by Henrik Storch on 10/22/19.
//

extension Array where Element: Equatable{
    func count(_ elements: Element) -> Int {
        var countArr = [Element]()
        for item in self{
            if item == elements {
                countArr.append(item)
            }
        }
        return countArr.count
    }
}

// let data = [5,6,1,4,5,7,8,2,4,6,3,2,6,6,3,5,5,2,10]
// data.count(5)

// <- 4
