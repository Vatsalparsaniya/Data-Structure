#All the possible ways of insertion & deletion in a linked are performed
#Revering a Linked list
#Sorting a linked list 
# info about the elements of the list
class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

# info about the head
class LinkedList:
    def __init__(self):
        self.head = None

    def traverse_list(self):
        if self.head is None:
            print("List has no elements\n")
            return
        else:
            n = self.head
            while n is not None:
                print(n.data , end = " ")
                n = n.next

    #insertion at start in linked list, head will become second
    def insert(self, data):
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode
    #insertion at end
    def insert_end(self,data):
        newNode = Node(data)
        #if list is empty, head pe vo value store ho jayegi
        if self.head is None:
            self.head = newNode
            return
        n = self.head    
        while n.next is not None:
            n = n.next
        n.next = newNode
    #insert after a particular value
    def insert_after_item(self, x, data):
        n = self.head   
        print("k\n")
        while n is not None:
            if n.data == x:
                break
            n = n.next
        if n is None:
            print("not in list\n")
        else:
            newNode = Node(data)
            newNode.next = n.next
            n.next = newNode

    def insert_before_item(self, x, data):
        if self.head is None:
            print("list has no item\n") 
            return
        if x == self.head.data:
            newNode = Node(data)
            newNode.next = self.head
            self.head = newNode
            return
        n = self.head
        while n.next is not None:
            #print(n.next.data)
            #print(n.data)
            if n.next.data == x:
                break
            n = n.next
        if n.next is None:
            print("not in list\n")
        else:
            newNode = Node(data)
            newNode.next = n.next
            n.next = newNode       

    #insertion at index
    def insert_at_index(self, index, data):
        if index ==1:
            newNode = Node(data)
            newNode.next = self.head
            self.head = newNode
        i =1
        n = self.head
        while i < index-1 and n is not None:
            n = n.next
            i = i+1
        if n is None:
            print("index out of bound") 
        else:
            newNode = Node(data)
            newNode.next = n.next
            n.next = newNode       

    #counting the elements
    def get_count(self):
        if self.head is None:
            return 0
        n = self.head
        count = 0
        while n is not None:
            count = count +1
            n = n.next
        print(count) 
        #return count   

    #searching item
    def search(self, x):
        if self.head is None:
            print("empty list\n")
            return
        n = self.head
        while n is not None:
            if n.data == x:
                print("item exists")
                return True
            n = n.next
        print("item not found")
        return False     

    #creating a linked list func
    def make_list(self):
        # no of insertions
        num = int(input())
        if num == 0:
            return
        for i in range(num):
            val = int(input())
            self.insert_end(val)

    #deletion from start
    def delete(self):
        if self.head is None:
            print("No ele to delete")
            return
        self.head = self.head.next

    #deletion at end
    def del_end(self):
        if self.head is None:
            print("No ele to delete")
            return
        n = self.head
        while n.next.next is not None:
            n = n.next
        n.next = None
    
    #deletion of a particular value
    def deletion(self, x):
        if self.head is None:
            print("nothing to delete")
            return
        if self.head.data == x:
            self.head = self.head.next
            return
        n = self.head
        while n.next is not None:
            if n.next.data ==x:
                break
            n = n.next

        if n.next is None:
            print("item not in list")
        else:
            n.next = n.next.next

    #reverse
    def reverse(self):
        prev = None
        n = self.head
        while n is not None:
            next = n.next
            n.next = prev
            prev = n
            n = next
        self.head = prev

    #sort
    def sort(self):
        end = None
        while self.head != end:
            p = self.head
            while p.next != end:
                q = p.next
                if p.data > q.data:
                    p.data, q.data = q.data, p.data
                p= p.next
            end = p
'''
Execution Statements for all the functions together  

ll=LinkedList()
#no elements, will print empty
ll.traverse_list()
# creating the head  
#ll.head= Node(3)
# only the node is created, but it is not yet linked to the list
first = Node(4)
second = Node(5)
# value of data in second node
print("Printing node value")
print(second.data)
# traversing the list shows that, only head is there
print("Linked list")
ll.traverse_list()
print("insert at start")
ll.insert(4)
# 4 will be head, 3 will be second node                 
ll.traverse_list()
# insertion at end
print("insertion at end")
ll.insert_end(5)
ll.insert_end(6)
ll.insert_end(7)
ll.insert_end(8)
ll.traverse_list()
print(ll.head.data)
ll.insert(9)
print(ll.head.data)
ll.traverse_list()
ll.insert_after_item(10,11)
ll.insert_after_item(9,10)
ll.traverse_list()
print("insertion before\n")
ll.insert_before_item(10,2)
ll.traverse_list()
print("insertion before\n")
ll.insert_before_item(2,1)
ll.traverse_list()
print("insert at index\n")
ll.insert_at_index(2,0)
ll.traverse_list()
print("count\n")
ll.get_count()
ll.search(2)
print("making list\n")
#ll.make_list()
#ll.traverse_list()
print("delete\n")
ll.delete()
ll.traverse_list()
print("deletion from end \n")
ll.del_end()
ll.traverse_list()
print("byeeee\n")
ll.deletion(0)
ll.traverse_list()
ll.deletion(9)
ll.deletion(10)
ll.traverse_list()
print("reverse\n")
ll.reverse()
ll.traverse_list()
print("sort\n")
ll.sort()
ll.traverse_list()

'''






                
