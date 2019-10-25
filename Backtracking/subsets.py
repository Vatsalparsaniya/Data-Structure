
def subsetsUtil(A, subset, index): 
	print(*subset) 
	for i in range(index, len(A)): 
		
		# include the A[i] in subset. 
		subset.append(A[i]) 
		
		# move onto the next element. 
		subsetsUtil(A,subset, i + 1) 

		subset.pop(-1) 
	return

def subsets(A): 
	global res 
	subset = [] 
	
	index = 0
	subsetsUtil(A, subset, index) 
	

