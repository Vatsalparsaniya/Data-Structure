#include <vector>

using namespace std;

template <class T>
class stack {
private:
	vector<T> items;
	int size;

public:
	void push(T);
	T pop();
	int getSize();
	T top();
};

template <class T>
void stack<T>::push(T item) {
	items.push_back(item);
	size++;
}

template <class T>
T stack<T>::pop() {
	if (size == 0) {
		throw "No items to pop";
	}
	else {
		T temp = items[size - 1];
		items.pop_back();
		size--;
		return temp;
	}
}

template <class T>
int stack<T>::getSize() {
	return size;
}

template <class T>
T stack<T>::top() {
	return items[size - 1];
}