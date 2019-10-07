class QuickSorter(object):

    def __init__(self,array):
        """
        Initialize QuickSorter with an array of numbers that should be sorted
        """
        self.list = []
        self.replace_list(array)

    def replace_list(self, array):
        if isinstance(array, list):
            for i in array:
                if not (isinstance(i,int) or isinstance(i, float)):
                    raise ValueError("all elements must be type number")
        else:
            raise AttributeError("search array must be list type")
        
        self.sorted = False
        self.list = array


    def __quicksort(self, low, high):
        size = high - low + 1
        stack = [0] * (size) 
    
        top = -1
    
        top = top + 1
        stack[top] = low 
        top = top + 1
        stack[top] = high 
    
        while top >= 0: 
    
            high = stack[top] 
            top = top - 1
            low = stack[top] 
            top = top - 1
    
            partition = self.__partition( low, high ) 
    
            if partition-1 > low: 
                top = top + 1
                stack[top] = low 
                top = top + 1
                stack[top] = partition - 1
    
            if partition+1 < high: 
                top = top + 1
                stack[top] = partition + 1
                top = top + 1
                stack[top] = high 

    def __partition(self,low,high): 
        i = ( low - 1 ) 
        x = self.list[high] 
    
        for j in range(low , high): 
            if   self.list[j] <= x: 
                i = i+1
                self.list[i],self.list[j] = self.list[j],self.list[i] 
    
        self.list[i+1],self.list[high] = self.list[high],self.list[i+1] 
        return (i+1) 


    def sort(self):
        """
        Executing Hoare partition scheme quick sort algorithm, iterativly
        """
        self.__quicksort( 0, len(self.list) - 1 )
        self.sorted = True



    def result(self):
        """
        Return the sorted list, and sort before if not already sorted
        """
        if not self.sorted:
            self.sort()
        
        return self.list
