#Defining node as a class and initializing
class Node:
	def __init__(self, key):
		self.left = None
		self.right = None
		self.val = key

#Inserting a node in the BST
def insert_node(root, node):
	if root is None:
		root = node
	else:
		if root.val > node.val:
			if root.left is None:
				root.left = node
			else:
				insert_node(root.left, node)
		else:
			if root.right is None:
				root.right = node
			else:
				insert_node(root.right, node)

#Inorder Traversal of BST
def inorder(root):
	if root:
		inorder(root.left)
		print(root.val, end=" ")
		inorder(root.right)

#User input for root and subsequent nodes
r = Node(int(input("Enter root node: ")))
temp = input("Enter subsequent nodes: ").split()
for i in temp:
	insert_node(r, Node(int(i)))
print("Inorder", end=" ")
inorder(r)
