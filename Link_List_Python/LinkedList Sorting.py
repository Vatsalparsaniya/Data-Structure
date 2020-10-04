class Node:
    def __init__(self , dataval=None):
        self.data = dataval
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    # print linkedlist
    def listprint(self):
        printval = self.head
        while printval is not None:
            print(printval.data)
            printval = printval.next


def merge(L1,L2):
    # here we maerged l2 with l1 because l1 has low points then l2

    # if in one of the linked list has only one node then simply add with other linkedlist
    if L1.next == None:
        L1.next = L2
        return L1

    # cur1 , Next1 for linked list
    # cur2 , Next2 for linked list

    cur1 = L1
    cur2 = L2
    next1 = L1.next
    next2 = L2.next

    while cur2 is not None:

        if cur2.data >= cur1.data and next1.data >= cur2.data:

            cur1.next = cur2
            cur2.next = next1

            cur1 = cur2
            cur2 = next2

            if cur2 is not None:
                next2 = cur2.next

        else:
            if next1.next is not None:

                cur1 = cur1.next
                next1 = next1.next

            else:

                next1.next = cur2

                return L1

    return L1

def RearangeLinked_List(node):
    node = node.head
    ptr = node

    #only one node
    if node.next == None:
        return node

    # half list is sorted so we check for this condition
    while ptr.next != None and ptr.next.next != None and ptr.data <= ptr.next.data:
        ptr = ptr.next

    temp = ptr
    ptr = ptr.next
    temp.next = None

    # if one of the list is empty then return othr list

    if node is None:
        return ptr
    if ptr is None:
        return node

    # start with that linked list whose data is low

    if node.data < ptr.data:
        return merge(node , ptr)
    else:
        return merge(ptr , node)


list = LinkedList()
list.head = Node(3)
n2 = Node(4)
n3 = Node(6)
n4 = Node(7)
n5 = Node(8)
n6 = Node(2)
n7 = Node(3)
n8 = Node(4)

list.head.next = n2
n2.next = n3
n3.next = n4
n4.next = n5
n5.next = n6
n6.next = n7
n7.next = n8

list.listprint()
print('New Linked List')
head = RearangeLinked_List(list) # return is Node type

# so we created new Print
printval = head
while printval is not None:
    print(printval.data)
    printval = printval.next