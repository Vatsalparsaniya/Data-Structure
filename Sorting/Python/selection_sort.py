#coding: utf-8;

def selection_sort(array, indice):
	if len(array) - 1 <= 0:
		return -1;
	
	minIndice = indice;
	
	for i in xrange(indice + 1 , len(array)):
		if array[i] < array[minIndice]:
			minIndice = i;
		
	aux = array[indice];
	array[indice] = array[minIndice];
	array[minIndice] = aux;
	
	selection_sort(array, indice + 1); 
	return array;
