
package main
import "fmt"
 
func binarySearch(below int, up []int) bool {
 
    low := 0
    high := len(up) - 1
 
    for low <= high{
        median := (low + high) / 2
 
        if up[median] < below {
            low = median + 1
        }else{
            high = median - 1
        }
    }
 
    if low == len(up) || up[low] != below {
        return false
    }
	
    return true
}
 
func main(){
    items := []int{3, 15, 21, 36, 46, 67, 93, 110}
	var searchKey = 21
	if (binarySearch(searchKey, items) == true){
		fmt.Println(searchKey,"is available in the array")
	}else{
		fmt.Println(searchKey,"isn't available in the array")
	}

}