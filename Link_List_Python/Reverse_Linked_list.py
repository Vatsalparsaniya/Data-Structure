# Define class Node
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


# Define class Linked List
class LinkedList:
    def __init__(self):
        self.head = None
        self.last_node = None

    def append(self, data):
        if self.last_node is None:
            self.head = Node(data)
            self.last_node = self.head
        else:
            self.last_node.next = Node(data)
            self.last_node = self.last_node.next

    def display(self):
        current = self.head
        while current is not None:
            print(current.data, end=' ')
            current = current.next


# Reverse a Linked Lists
def reverse_llist(llist):
    before = None
    current = llist.head
    if current is None:
        return
    after = current.next
    while after:
        current.next = before
        before = current
        current = after
        after = after.next
    current.next = before
    llist.head = current


a_list = LinkedList()
n = int(input('Enter how many elements'))
for i in range(n):
    data = int(input())
    a_list.append(data)

reverse_llist(a_list)
# Print the reversed Linked List
print(a_list.display())
