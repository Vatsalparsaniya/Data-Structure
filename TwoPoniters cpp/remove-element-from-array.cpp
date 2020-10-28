// Ques Link : https: //www.interviewbit.com/problems/remove-element-from-array
/* Given an array and a value, remove all the instances of that value in the array.
Also return the number of elements left in the array after the operation.
It does not matter what is left beyond the expected length.

 Example:
If array A is [4, 1, 1, 2, 1, 3]
and value elem is 1,
then new length is 3, and A is now [4, 2, 3] 
Try to do it in less than linear additional space complexity. */

//main function has been included to ease readability and for  better understanding

#include <bits/stdc++.h>
using namespace std;
int removeElement(vector<int> &A, int B)
{

    int i = 0, j = 0, duplicates = 0;

    while (i < A.size() && j < A.size())
    {
        if (A[i] != B)
        {
            A[j++] = A[i];
        }
        else
            duplicates++; //whenever A[i] == B
        i++;
    }
    return A.size() - duplicates;
}

int main()
{
    int size;
    cin >> size;
    vector<int> A(size);

    for (auto &x : A)
        cin >> x;
    int element;
    cin >> element;
    int newlength = removeElement(A, element);
    cout << "Newlength after removal of element is " << newlength << '\n';

    for (int i = 0; i < newlength; i++)
        cout << A[i] << " ";

    return 0;
}