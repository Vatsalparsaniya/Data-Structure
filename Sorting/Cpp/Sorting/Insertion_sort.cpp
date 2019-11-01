#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void insertion_sort(vector<T> & vec)
{
    for(size_t i = 0; i < vec.size() - 1; i++)
    {
        for(size_t j = i + 1; j < vec.size(); j++)
        {
            if(vec[i] > vec[j])
                swap(vec[i], vec[j]);
        }
    }
}

int main()
{
    size_t n;
    cin>>n;

    vector<int> arr(n);

    for(size_t i = 0; i < n; i++)
        cin>>arr[i];

    insertion_sort(arr);

    for(size_t i = 0; i < n; i++)
        cout<<arr[i]<<' ';
    
    cout<<endl;

    return 0;
}