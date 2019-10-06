#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void Shellsort(vector<T> & vec)
{
	size_t j;
	T temp;

	for(size_t aux = vec.size() / 2; aux > 0; aux /= 2)
	{
		for(size_t i = aux; i < vec.size(); ++i)
		{
			temp = vec[i];
			
			for(j = i; j >= aux and vec[j - aux] > temp; j -= aux)
				vec[j] = vec[j - aux];
			
			vec[j]=temp;
		}
	}
}
 
int main()
{
	int array_size;
	
	cout<<"Array size: ";
	cin>>array_size;

	vector<int> vec(array_size);

	cout<<"Array elements: ";
	
	for(int i = 0; i < array_size; i++)
			cin>>vec[i];

	Shellsort(vec);

	cout<<"Sorted array: ";
	for(int i = 0; i < array_size; i++)
		cout<<vec[i]<<' ';
	cout<<endl;

	return 0;
}