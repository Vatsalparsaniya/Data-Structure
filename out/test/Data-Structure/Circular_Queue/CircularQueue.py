class CircularQueue(object):
    def __init__(self, size):
        """
        Initializing CircularQueue
        """
        self.size = size
        self._front = -1
        self._rear = -1
        self.queue = [None] * size


    def front(self):
        """
        Return the value at the front of the queue
        """
        return self.queue[self._front]


    def rear(self):
        """
        Return the value at the rear of the queue
        """
        return self.queue[self._rear]


    def enqueue(self, value):
        """
        Insert value into the rear of the circular queue 
        """
        if (self._rear == self.size - 1 and self._front == 0) or (self._rear == self._front-1):
            # Queue is full
            raise OverflowError("CircularQueue is full")
        elif (self._rear == -1):
            # Setting up for first item
            self._rear = 0
            self._front = 0
        else:
            # Calculating rear index after insert
            self._rear = (self._rear + 1) % self.size

        self.queue[self._rear] = value


    def dequeue(self):
        """
        Remove and return the value at the front of the circular queue 
        """
        if(self._front==-1):
            # Queue is empty
            raise IndexError("CircularQueue is empty")
        elif(self._front == self._rear):
            # Remove the last remaning value and indicate the queue empty
            value = self.queue[self._front]
            self._front = -1
            self._rear = -1
            return value
        else:
            # Return the value at the front of the queue
            value = self.queue[self._front]
            self.queue[self._front] = None
            self._front = (self._front + 1 ) % self.size
            return value