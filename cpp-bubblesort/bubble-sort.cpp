#include <array>
#include <iostream>

using namespace std;

void printarr(int arr[], int size){
    for (int i = 0; i < size; ++i){
        cout << arr[i] << " ";
    }// ending bracket for for loop
    cout << endl;
}// ending bracket for printarr

int main(){
    int arr[] = {1,5,2,6,4,3,7,8};
    int size = 8;
    int temp ;

    //print array before sorting
    printarr(arr, size);

    //sort array
    for ( int i = 0; i < size; ++i){
        for (int j = 0; j < size-1; j++){
            if (arr[j] > arr[j+1]){ //if j+1 is larger than j, swap j and j+1
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }// ending bracket for if
        }//ending bracket for inner for loop
    }//ending bracket for outter for loop

    //print array after sorting
    printarr(arr,size);

    return 0;
}