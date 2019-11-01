#include <iostream>
#include <vector>
using namespace std;

void counting_sort(vector<size_t> & origin, size_t digit, size_t exponent)
{
    vector<size_t> temp(exponent + 1);
    vector<size_t> target(origin.size());

    for(size_t i = 0; i < exponent; i++)
        temp[i] = 0;

    for(size_t j = 0; j < origin.size(); j++)
    {
        temp[(origin[j]/digit) % exponent]++;
    }
    cout<<endl;

    for(size_t i = 1; i < exponent; i++)
        temp[i] += temp[i - 1];

    for(size_t j = origin.size() -1 ; ; j--)
    {
        target[temp[(origin[j]/digit) % exponent] - 1] = origin[j];
        temp[(origin[j]/digit) % exponent]--;
    
        if(j == 0)
            break;
    }

    for(size_t i = origin.size() - 1; ; i--)
    {
        origin[i] = target[i];
        if(i == 0)
            break;
    }
}

void radix_sort(vector<size_t> & vec, size_t max_input, const int exponent = 10)
{
    size_t highest_base = 0;
    while(max_input > 0)
    {
        highest_base++;
        max_input /= exponent;
    }

    size_t divisor = 1;

    for(size_t i = 0; i < highest_base; i++)
    {
        counting_sort(vec, divisor, exponent);
        divisor *= exponent;
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

	vector<size_t> arr(n);

	if(print_input)
		cout<<"Array elements: ";

    size_t max_input = 0;

	for(size_t i = 0; i < n; i++)
	{
        cin>>arr[i];
        max_input = max(arr[i], max_input);
    }

    radix_sort(arr, max_input);

    if(print_input)
        cout<<"Sorted array: ";
    
    for(size_t  i = 0; i < n; i++)
        cout<<arr[i]<<' ';
    
    cout<<endl;

	return 0;
}