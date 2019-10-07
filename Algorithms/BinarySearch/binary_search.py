class SearchBinary(object):

    def __init__(self, array):
        """
        Initialize SearchBinary with a sorted array to be searched
        :type l: list
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
        
        self.list = array


    def find(self, key):
        """
        Find the index of the key in the list given to SearchBinary
        """
        left_boundry = 0
        right_boundry = len(self.list) - 1

        while left_boundry <= right_boundry:
            middle = (left_boundry + right_boundry) // 2
            if self.list[middle] < key:
                left_boundry = middle + 1

            elif self.list[middle] > key:
                right_boundry = middle - 1

            else:
                return middle
        # Returning -1 (invalid index) indicates not found
        return -1