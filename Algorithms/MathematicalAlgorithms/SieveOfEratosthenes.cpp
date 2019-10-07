#include <iostream>
#include <cmath>

using namespace std;

///time complexity : O(sqrt(n)log(log(n)))

///Create a list of consecutive integers from 2 to n: (2, 3, 4, …, n).
///Initially, let p equal 2, the first prime number.
///Starting from p, count up in increments of p and mark each of these numbers greater than p itself in the list. These numbers will be 2p, 3p, 4p, etc.; note that some of them may have already been marked.
///Find the first number greater than p in the list that is not marked. If there was no such number, stop. Otherwise, let p now equal this number (which is the next prime), and repeat from step 3.

int main()
{

    int n;
    cout<<"Enter n: ";
    cin>>n;

    bool* arr = new bool[n+1];

    for(int i=1;i<=n;i++){   //creating a list of the first n integers
        arr[i] = true;
    }
    ///or use memset(arr,true,sizeof(arr)) in cstring library to initialize all elements to true
    for(int i=2;i<=sqrt(n);i++){

        if(arr[i]){ //element is prime
            for(int j=2*i;j<=n;j+=i){
                arr[j] = false;
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(arr[i]){
            cout<<i<<" ";
        }
    }
}
