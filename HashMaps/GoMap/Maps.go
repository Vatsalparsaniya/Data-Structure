// Map is used for key value association and it is built on top of hashtable.
// Map is unordered group of elements.
//Below is the basic operations of Map in Go programming language.

package main

import "fmt"

func main() {
	//1. creating a map having key of string type and value is of integer type.
	m := make(map[string]int)

	//2. Add elements in map
	m["key1"] = 10
	m["key2"] = 20
	m["key3"] = 30
	fmt.Println("Map : ", m)

	//3. Length of map
	fmt.Println("Length of map : ", len(m))

	//4. Delete from Map
	delete(m, "key2")
	fmt.Println("Map after deletion : ", m)

	//5. Check wether the key present in map or not
	val, status := m["key2"]
	fmt.Println("Key having value", val, "is present in map : ", status)

	val1, status1 := m["key3"]
	fmt.Println("Key having value", val1, "is present in map : ", status1)

	//6. Update the value
	m["key1"] = 50
	fmt.Println("Updated Map : ", m)
}

// To run the program, use following command
// go run Maps.go

// Output is as follows:
// Map :  map[key1:10 key2:20 key3:30]
// Length of map :  3
// Map after deletion :  map[key1:10 key3:30]
// Key having value 0 is present in map :  false
// Key having value 30 is present in map :  true
// Updated Map :  map[key1:50 key3:30]