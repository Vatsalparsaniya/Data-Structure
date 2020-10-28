//Ques Link https://www.interviewbit.com/problems/merge-two-sorted-lists-ii
/* Given two sorted integer arrays A and B, merge B into A as one sorted array.

 Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
TIP: C users, please malloc the result into a new array and return the result. 
If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n */

//main function has been included to ease readability and for  better understanding

#include <bits/stdc++.h>
using namespace std;
void Merge2SortedArrays(vector<int> &A, vector<int> &B)
{

    vector<int> arr;  //use of additional memory allowed
    int i = 0, j = 0; //2 pointers to at head of A and B resp.
    while (i < A.size() && j < B.size())
    {
        if (A[i] > B[j])
        {
            arr.push_back(B[j]);
            j++;
        }
        else
        {
            arr.push_back(A[i]);
            i++;
        }
    }
    if (i < A.size()) //if elements of A are left, keep pushing them in arr till end
    {
        while (i != A.size())
        {
            arr.push_back(A[i]);
            i++;
        }
    }
    if (j < B.size())
    {
        while (j != B.size()) //if elements of B are left, keep pushing them in arr till end
        {
            arr.push_back(B[j]);
            j++;
        }
    }

    A = arr; //copy vector arr to A to modify A
}

int main()
{
    int size1, size2;
    cin >> size1 >> size2;
    vector<int> A(size1), B(size2);

    for (auto &x : A)
        cin >> x;

    for (auto &xx : B)
        cin >> xx;

    Merge2SortedArrays(A, B);
    for (auto &x : A)
        cout << x << " ";  //array elemets after merge
    return 0;
}
