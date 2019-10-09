#coding: utf-8

def merge_sort(array):
	
	if len(array) < 2:
		return;
	
	mid = len(array) / 2;
	
	left = array[:mid];
	right = array[mid:];
	
	leftI = 0;
	rightI = 0;
	arrayI = 0;
	
	while leftI < len(left) and rightI < len(right):
		if left[leftI] < right[rightI]:
			array[arrayI] = left[leftI];
			leftI += 1;
		else:
			array[arrayI] = right[rightI];
			rightI += 1;
		
		arrayI += 1;
		
	while leftI < len(left):
		array[arrayI] = left[leftI];
		leftI += 1;
		arrayI += 1;
	
	while rightI < len(right):
		array[arrayI] = right[rightI];
		rightI += 1;
		arrayI += 1;

