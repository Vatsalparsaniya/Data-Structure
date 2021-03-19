class MyQueue:
    def __init__(self):
        self.stackIn = []
        self.stackOut = []

    def enqueue(self, values):
        self.stackIn.append(values)

    def dequeue(self):
        if len(self.stackOut) == 0:
            while len(self.stackIn) > 0:
                self.stackOut.append(self.stackIn.pop())

        return self.stackOut.pop()

    def peek(self):
        if len(self.stackIn) == 0:
            return None
        else:
            while len(self.stackIn) > 0:
                self.stackOut.append(self.stackIn.pop())

        return self.stackIn[0]


q = MyQueue()
print(q.peek())

q.enqueue(10)
print(q.peek())

q.enqueue(9)
q.enqueue(8)

print(q.dequeue())
print(q.dequeue())
print(q.dequeue())
