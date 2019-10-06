class MyHashMap(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.hash_map = [None] * 1000
        

    def put(self, key, value):
        """
        value will always be non-negative.
        :type key: int
        :type value: int
        :rtype: None
        """
        the_hash = hash(key) % 1000
        if not self.hash_map[the_hash]:
            self.hash_map[the_hash] = []
        self.remove(key)
        self.hash_map[the_hash].append((key, value))
        

    def get(self, key):
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        :type key: int
        :rtype: int
        """
        the_hash = hash(key) % 1000
        
        if self.hash_map[the_hash]:
            for t in self.hash_map[the_hash]:
                if t[0] == key:
                    return t[1]
        return -1

    def remove(self, key):
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        :type key: int
        :rtype: None
        """
        the_hash = hash(key) % 1000
        to_delete = None
        if self.hash_map[the_hash]:
            new_cell = []
            for i in range(len(self.hash_map[the_hash])):
                if not self.hash_map[the_hash][i][0] == key:
                    new_cell.append(self.hash_map[the_hash][i])                    
            self.hash_map[the_hash] = new_cell
