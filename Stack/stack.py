class Stack(object):

    def __init__(self,size):
        self.index = -1
        self.stack = [None] * size
    
    def push(self, value):
        if self.index != len(self.stack) -1:
            self.index = self.index + 1
            self.stack[self.index] = value

    def pop(self):
        if not self.empty():
            value = self.stack[self.index]
            self.stack[self.index] = None
            self.index = self.index - 1
            return value

    def peek(self):
        if not self.empty():
            return self.stack[self.index]

    def empty(self):
        return self.index == -1