#include <iostream> // input and output
#include <vector>	// vector
using namespace std;

template <typename T>
void merge_sort(vector<T> & vec, size_t l = 0, size_t r = 0)
{

	static bool started = false;

	if(!started)
	{
		l = 0;
		r = vec.size() - 1;
		started = true;
	}

	if(l == r)
		return;

	size_t mid = (l + r) / 2;

	merge_sort(vec, l, mid);
	merge_sort(vec, mid + 1, r);

	size_t pl = l;
	size_t pr = mid + 1;
	size_t next = 0;

	vector<T> sorted(r - l + 1);

	while(pl <= mid or pr <= r)
	{

		if(pl <= mid and pr <= r)
		{

			if(vec[pr] < vec[pl])
				sorted[next] = vec[pr++];
			else
				sorted[next] = vec[pl++];

		}
		else if(pl <= mid)
		{
			sorted[next] = vec[pl++];
		}
		else
		{
			sorted[next] = vec[pr++];
		}

		next++;

	}

	for(size_t i = l; i <= r; i++)
		vec[i] = sorted[i - l];

	if(l == 0 and r == vec.size() - 1)
		started = false;

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

	vector<int> vec(n);
		
	if(print_input)
		cout<<"Array elements: ";
		
	for(size_t i = 0; i < n; i++)
		cin>>vec[i];

	merge_sort(vec);
	
	if(print_input)
		cout<<"Sorted array: ";

	for(size_t i = 0; i < n; i++)

		cout<<vec[i]<<' ';

	cout<<endl;
	
	return 0;
}
