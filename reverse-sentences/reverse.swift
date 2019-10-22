//
//  reverse.swift
//  
//
//  Created by Henrik Storch on 10/22/19.
//

import Foundation

let input = "This is a sample input string"

extension String {
    var reverseSentance: String {
        var words = self.components(separatedBy: " ")
        words.reverse()
        return words.joined(separator: " ")
    }
}

print(input.reverseSentance)
