# Node class
class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

# Linked list class containing node object
class LinkedList:
	def __init__(self):
		self.head = None

if __name__ == '__main__':
	llist = LinkedList()
	llist.head = Node(1)
	second = Node(2)
	third = Node(3)
	llist.head.next = second
	second.next = third
	while llist.head!= None:
		print(" ->", llist.head.data, end = " ")
		llist.head = llist.head.next