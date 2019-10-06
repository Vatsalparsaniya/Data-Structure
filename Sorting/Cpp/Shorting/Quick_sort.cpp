#include <vector>
#include <iostream>
using namespace std;

template <typename T>
size_t partition(vector<T> & vec, size_t p, size_t r)
{
    T x = vec[r];
    size_t i = p - 1;
    for(size_t j = p; j < r; j++)
    {
        if(vec[j] <= x)
        {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[r]);
    return i + 1;
}

template <typename T>
void quick_sort(vector<T> & vec, size_t p = 0, size_t r = 0)
{
    static bool started = false;

    if(!started)
    {
        started = true;
        p = 1;
        r = vec.size() - 1;
    }

    if(p < r)
    {
        size_t q = partition(vec, p, r);
        quick_sort(vec, p, q - 1);
        quick_sort(vec, q + 1, r);
    }

    if(p == 0 and r == vec.size() - 1)
        started = false;
}

int main(int argc, char ** argv)
{
    bool print_input = true;

    if(argc > 1 and argv[1][1] == 'v')
        print_input = false;

    if(print_input)
        cout<<"Array size: ";

    size_t n;
    cin>>n;

    vector<int> arr(n + 1);
    arr[0] = 0;

    if(print_input)
        cout<<"Array elements: ";

    for(size_t i = 1; i <= n; i++)
        cin>>arr[i];

    quick_sort(arr);

    if(print_input)
        cout<<"Sorted array: ";

    for(size_t i = 1; i <= n; i++)
        cout<<arr[i]<<' ';
    
    cout<<endl;

    return 0;
}