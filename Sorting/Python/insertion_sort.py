#coding: utf-8;

def insertion_sort(array):
	for i in range(1, len(array)):
		key = array[i];
		aux = i - 1;
		while aux >= 0 and array[aux] > key:
			array[aux + 1] = array[aux];
			aux -= 1;
		array[aux + 1] = key;
	
	return array;
