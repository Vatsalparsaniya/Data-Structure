# A simple Python program to introduce a linked list 

# Node class 
class Node: 

	# Function to initialise the node object 
	def __init__(self, data): 
		self.data = data # Assign data 
		self.next = None # Initialize next as null 


# Linked List class contains a Node object 
class LinkedList: 

	# Function to initialize head 
	def __init__(self): 
		self.head = None


# Code execution starts here 
if __name__=='__main__': 

	# Start with the empty list 
	llist = LinkedList() 

	llist.head = Node(1) 
	second = Node(2) 
	third = Node(3) 

	''' 
	Three nodes have been created. 
	We have references to these three blocks as head, 
	second and third 

	llist.head	 second			 third 
		|			 |				 | 
		|			 |				 | 
	+----+------+	 +----+------+	 +----+------+ 
	| 1 | None |	 | 2 | None |	 | 3 | None | 
	+----+------+	 +----+------+	 +----+------+ 
	'''

	llist.head.next = second; # Link first node with second 

	''' 
	Now next of first Node refers to second. So they 
	both are linked. 

	llist.head	 second			 third 
		|			 |				 | 
		|			 |				 | 
	+----+------+	 +----+------+	 +----+------+ 
	| 1 | o-------->| 2 | null |	 | 3 | null | 
	+----+------+	 +----+------+	 +----+------+ 
	'''

	second.next = third; # Link second node with the third node 

	''' 
	Now next of second Node refers to third. So all three 
	nodes are linked. 

	llist.head	 second			 third 
		|			 |				 | 
		|			 |				 | 
	+----+------+	 +----+------+	 +----+------+ 
	| 1 | o-------->| 2 | o-------->| 3 | null | 
	+----+------+	 +----+------+	 +----+------+ 
	'''

