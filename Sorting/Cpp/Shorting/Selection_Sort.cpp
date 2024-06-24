#include<iostream>
using namespace std;

// main function
int main(){

    // declaring variables
    int arr[20], pos, i, j, temp, num;

    // taking input of number-of-elemets
    cout << "Enter number of elements: ";
    cin >> num;

    // taking input of elements
    cout << endl << "Enter elements:" << endl;
    for(i = 0; i < num; i++)
        cin >> arr[i];

    // sorting elements using Selection Sort
    for (i = 0; i < num; i++)  {  
        pos = i;  
        for (j = i + 1; j < num; j++)  
        if (arr[j] < arr[pos])  
            pos = j;  
  
        temp = arr[pos];
        arr[pos] = arr[i];
        arr[i] = temp;  
    }  

    // printing Sorted elements
	cout << endl << "Sorted elements: " << endl;
    for(i = 0; i < num; i++)
        cout << arr[i] << endl;
    
    // returning 0
    return 0;
}
// main closed