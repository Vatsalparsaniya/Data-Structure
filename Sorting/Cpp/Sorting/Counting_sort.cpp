    #include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<double> & vec)
{
    const double EPS = 1e-9;

    for(size_t i = 0; i < vec.size(); i++)
    {
        for(size_t j = i + 1; j < vec.size(); j++)
        {
            if(vec[i] - vec[j] > EPS)
                swap(vec[i], vec[j]);
        }
    }
}

void bucket_sort(vector<double> & vec)
{
    size_t n = vec.size();

    vector<double> bucket[n];

    for(size_t i = 0; i < n; i++)
    {
        bucket[((size_t) vec[i] * n)].push_back(vec[i]);
    }

    for(size_t i = 0; i < n; i++)
    {
        insertion_sort(bucket[i]);
    }

    size_t next = 0;

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < bucket[i].size(); j++)
        {
            vec[next++] = bucket[i][j];
        }
    }
}

int main(int argc, char ** argv)
{
	bool print_input = true;

	if(argc > 1 and argv[1][1] == 'v')
		print_input = false;

	size_t n;

	if(print_input)
		cout<<"Array size: ";

	cin>>n;

	vector<double> arr(n);

	if(print_input)
		cout<<"Array elements: ";

	for(size_t i = 0; i < n; i++)
        cin>>arr[i];

    bucket_sort(arr);

    if(print_input)
        cout<<"Sorted array: ";
    
    for(size_t  i = 0; i < n; i++)
        cout<<arr[i]<<' ';
    
    cout<<endl;

	return 0;
}