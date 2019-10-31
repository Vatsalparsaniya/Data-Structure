#include <iostream>
#include <vector>
using namespace std;

template <typename T>
bool greater_c(const T a,const T b)
{
	return a > b;
}

template <typename T>
bool lower_c(const T a, const T b)
{
	return a < b;
}

size_t left(const size_t node)
{
	return node << 1;
}

size_t right(const size_t node)
{
	return 1 + (node << 1);
}

size_t parent(const size_t node)
{
	return node >> 1;
}

template <typename T>
void max_heapify(vector<T> & heap, size_t position, size_t heap_size, bool comparator(T, T))
{
	size_t l = left(position);
	size_t r = right(position);
	size_t high_priority;

	if(l < heap_size and comparator(heap[position], heap[l]))
	{
		high_priority = l;
	}
	else
	{
		high_priority = position;
	}

	if(r < heap_size and comparator(heap[high_priority], heap[r]))
	{
		high_priority = r;
	}

	if(high_priority != position)
	{
		swap(heap[position], heap[high_priority]);
		max_heapify(heap, high_priority, heap_size, comparator);
	}
}

template <typename T>
void build_heap(vector<T> & heap, bool comparator(T, T))
{

	for(size_t i = heap.size() - 1; ; i--)
	{

		max_heapify(heap, i, heap.size(), comparator);
		if(i == 0)
			break;

	}
	
}

template <typename T>
void heap_sort(vector<T> & heap, bool comparator(T, T) = lower_c)
{
	build_heap(heap, comparator);

	size_t heap_size = heap.size();

	for(size_t i = heap.size() - 1; i >= 1; i--)
	{

		swap(heap[0], heap[i]);
		heap_size--;
		max_heapify(heap, 0, heap_size, comparator);

	}

}

int main(int argc, char ** argv){

	bool print_input = true;

	if(argc > 1 and argv[1][1] == 'v')
		print_input = false;

	size_t n;

	if(print_input)
		cout<<"Array size: ";

	cin>>n;

	vector<int> arr(n);

	if(print_input)
		cout<<"Array elements: ";

	for(size_t i = 0; i < n; i++)
		cin>>arr[i];

	heap_sort(arr);

	if(print_input)
		cout<<"Sorted array: ";
	
	for(size_t  i = 0; i < n; i++)
		cout<<arr[i]<<' ';
	
	cout<<endl;

	return 0;
}
