#coding: utf-8;

def quick(array, init, end):
	pivot = array[init];
	
	while True:
		while array[init] < pivot:
			init += 1;
		
		while array[end] > pivot:
			end -= 1;
		
		if init >= end:
			return end;
		
		swap(array, init, end);
		
		init += 1;
		end -= 1;

def swap(array, i, j):
	array[i], array[j] = array[j], array[i];


def quick_sort(array, init, end):
	if init < end:
		partition = quick(array, init, end);
		quick_sort(array, init, partition);
		quick_sort(array, partition + 1, end);
	
