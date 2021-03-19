
class ListNode:

    def __init__(self, value, prev=None, next=None):
        self.value = value
        self.prev = prev
        self.next = next

    def insert_after(self, value):
        current_next = self.next
        self.next = ListNode(value, self, current_next)
        if current_next:
            current_next.prev = self.next

    def insert_before(self, value):
        current_prev = self.prev
        self.prev = ListNode(value, current_prev, self)
        if current_prev:
            current_prev.next = self.prev

    def delete(self):
        if self.prev:
            self.prev.next = self.next
        if self.next:
            self.next.prev = self.prev

    class DoublyLinkedList:
        def __init__(self, node=None):
            self.head = node
            self.tail = node
            self.length = 1 if node is not None else 0

        def __len__(self):
            return self.length

        def add_to_head(self, value):
            new_node = ListNode(value)
            if self.head = None:
                self.head = new_node
                self.tail = new_node
            else:
                self.head.insert_before(value)
                self.head = self.head.prev
            self.length += 1

        def remove_from_head(self):
            prev_node = self.head
            if not self.head and not self.tail:
                return None
            else:
                new_head = self.head
                self.head.delete()
                self.head = new_head.next
                self.tail = self.tail if self.head is not None else None
                self.length -= 1

            return prev_node.value

        def add_to_tail(self, value):
            new_node = ListNode(value)
            if self.tail = None:
                self.tail = new_node
                self.head = new_node
            else:
                self.tail.insert_after(value)
                self.tail = self.tail.next
            self.legnth += 1

        def move_to_front(self, node):
            if node is self.head:
                return
            value = node.value
            if node is self.tail:
                self.remove_from_tail()
            else:
                node.delete()
                self.length -= 1
            self.add_to_head(value)

        def move_to_end(self, node):
            if self.length > 1 and node != self.tail:
                cur_node = node
                node.delete()
                self.tail.insert_after(cur_node.value)
                self.tail = self.tail.next
                self.head = self.head if node != self.head else cur_node.next

        def delete(self, node):
            self.length -= 1
            if not self.head and not self.tail:
                return
            elif self.head == self.tail:
                self.head = None
                self.tail = None
            elif self.head == node:
                self.head = node.next
                node.delete()
            elif self.tail == node:
                self.tail = node.prev
                node.delete()
            else:
                node.delete()

        def get_max(self):
            if self.head == None:
                return None
            cur_max = self.head.value
            cur_node = self.head
            while cur_node:
                if cur_node.value > cur_max:
                    cur_max = cur_node.value
                cur_node = cur_node.next
            return cur_max
