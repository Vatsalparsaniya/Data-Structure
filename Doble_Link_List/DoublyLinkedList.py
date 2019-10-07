#!/usr/bin/env python3

import collections


class Node:
    """A node containing data with, optionally, a pointer to a next and/or previous node.
    i.e. Node1 <-> Node2 OR NULL <- Node1 -> NULL
    There are no restrictions on what type of data can be contained within the node.
    """
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

    def __repr__(self):
        if self.prev is None:
            if self.next is None:
                return 'NULL -> %s -> NULL' % self.data
            return 'NULL -> %s -> %s' % (self.data, self.next.data)
        elif self.next is None:
            return '%s -> %s -> NULL' % (self.prev.data, self.data)
        return '%s -> %s -> %s' % (self.prev.data, self.data, self.next.data)


class DoublyLinkedList:
    """A list of doubly linked nodes containing data.
    i.e. NULL <- Node1 <-> Node2 -> NULL
    """

    def __init__(self, elements=None):
        """Instantiates a new instance of a DoublyLinkedList.
        :param elements: Optional. The elements initialize with.
        :exception: TypeError is raised if 'elements' is not iterable.
        >>> my_list = DoublyLinkedList()
        >>> my_list
        []
        >>> my_list = DoublyLinkedList([3, 4, 5])
        >>> my_list
        [3, 4, 5]
        """
        self._head = None
        self._tail = None
        self._size = 0
        self._iter_node = None

        if elements is not None:
            self.extend(elements)

    def __add__(self, other):
        if not isinstance(other, DoublyLinkedList):
            raise TypeError("other must be a DoublyLinkedList")

        if self._head is None:
            return other.copy()

        if not len(other):
            return self.copy()

        new_list = self.copy()

        new_list.extend(other)

        return new_list

    def __contains__(self, item) -> bool:
        node = self._head
        while node is not None:
            if node.data == item:
                return True

        return False

    def __delitem__(self, key):
        self.remove_item(key)

    def __eq__(self, other):
        if isinstance(other, DoublyLinkedList):
            if self.size != other.size:
                return False
            else:
                self_node = self._head
                other_node = other._head

                while self_node is not None and other_node is not None:
                    if self_node.data != other_node.data:
                        return False
                    self_node = self_node.next
                    other_node = other_node.next

                return True
        elif isinstance(other, list):
            if self.size != len(other):
                return False

            self_node = self._head
            i = 0

            while self_node is not None:
                if self_node.data != other[i]:
                    return False
                self_node = self_node.next
                i += 1

            return True
        else:
            return NotImplemented

    def __getitem__(self, index: int):
        return self.get(index)

    def __iadd__(self, other):
        self.extend(other)

    def __len__(self):
        return self._size

    def __iter__(self):
        return self

    def __next__(self):
        if self._head is None:
            raise StopIteration()

        if self._iter_node is None:
            self._iter_node = self._head
        else:
            self._iter_node = self._iter_node.next

            if self._iter_node is None:
                raise StopIteration()

        return self._iter_node.data

    def __repr__(self):
        s = []
        node = self._head
        while node is not None:
            s.append(node.data)
            node = node.next

        return str(s)

    def __reversed__(self):
        """Returns a reversed copy of the list.
        :return: A reversed copy of the list.
        >>> my_list = DoublyLinkedList([1, 2, 3])
        >>> list(reversed(my_list))
        [3, 2, 1]
        """
        copy = self.copy()
        copy.reverse()

        for data in copy:
            yield data

    @property
    def size(self) -> int:
        """Returns the size of the list.
        :return: The size.
        >>> my_list = DoublyLinkedList()
        >>> my_list.size
        0
        >>> my_list = DoublyLinkedList([1, 2, 3])
        >>> my_list.size
        3
        """
        return self._size

    def append(self, data):
        """Appends the data to the end of the list.
        :param data: The data to append.
        >>> my_list = DoublyLinkedList()
        >>> my_list.append(5)
        >>> my_list
        [5]
        >>> my_list = DoublyLinkedList([3, 4])
        >>> my_list.append(1)
        >>> my_list
        [3, 4, 1]
        """
        self._size += 1

        if self._head is None:
            node = Node(data)
            self._head = node
            self._tail = node
        else:
            self._tail.next = Node(data)
            self._tail.next.prev = self._tail
            self._tail = self._tail.next

    def copy(self):
        """Returns a copy of the list.
        :return: A copy of the list.
        >>> my_list = DoublyLinkedList()
        >>> my_list.copy()
        []
        >>> my_list = DoublyLinkedList([5, 7, -1])
        >>> my_list.copy()
        [5, 7, -1]
        """
        list_copy = DoublyLinkedList()

        node = self._head
        while node is not None:
            list_copy.append(node.data)
            node = node.next

        return list_copy

    def extend(self, other):
        """Extends the list with the elements of another.
         :param other: A list or DoublyLinkedList to extend the list with.
         :exception: TypeError is raised if 'other' is not iterable.
         >>> my_list = DoublyLinkedList([1])
         >>> my_list.extend([2, 3, 4])
         >>> my_list
         [1, 2, 3, 4]
         >>> my_list1 = DoublyLinkedList([1, 2, 3])
         >>> my_list2 = DoublyLinkedList([4, 5])
         >>> my_list1.extend(my_list2)
         >>> my_list1
         [1, 2, 3, 4, 5]
         """
        if isinstance(other, collections.Iterable):
            if self._head is None:
                added_head = False
                node = None

                for data in other:
                    if not added_head:
                        self._head = Node(data)
                        node = self._head
                        added_head = True
                    else:
                        node.next = Node(data)
                        node.next.prev = node
                        node = node.next
                    self._size += 1

                self._tail = node
            else:
                tail = self._tail

                for data in other:
                    tail.next = Node(data)
                    tail.next.prev = tail
                    tail = tail.next
                    self._size += 1

                self._tail = tail
        else:
            raise TypeError("other must be iterable")

    def get(self, index: int):
        """Gets the data at the specified index.
        :param index: The index to retrieve.
        :return: The data.
        :exception: IndexError is raised if index is out of bounds.
        >>> my_list = DoublyLinkedList()
        >>> my_list.extend([4, 6, 2])
        >>> my_list.get(1)
        6
        >>> my_list = DoublyLinkedList()
        >>> my_list.extend([5, 2, -1, 2])
        >>> my_list.get(-2)
        -1
        """
        if index < -self.size or index >= self.size:
            raise IndexError("index is out of range")

        if index < 0:
            index = self.size + index

        if index < self.size // 2:  # closer to head, start search from there
            node = self._head
            for i in range(index):
                node = node.next
        else:  # otherwise, start from tail
            node = self._tail
            for i in range(self.size - index - 1):
                node = node.prev

        return node.data

    def insert(self, index: int, data):
        """Inserts the data at the given element.
        If an element exists at the given position, the element is inserted before it.
        :param index: The index to insert at.
        :param data: The data to insert.
        :exception: IndexError is raised if index is out of bounds.
        >>> my_list = DoublyLinkedList()
        >>> my_list.insert(0, 3)
        >>> my_list.insert(0, 1)
        >>> my_list.insert(-1, 2)
        >>> my_list.insert(len(my_list), 4)
        >>> my_list
        [1, 2, 3, 4]
        """
        if index < -self.size or index > self.size:
            raise IndexError("index is out of range")

        if index < 0:
            index = self.size + index

        if self._head is None:
            self._head = Node(data)
            self._tail = self._head
            self._size += 1
        elif index == 0:
            self.prepend(data)
        elif index == self._size:
            self.append(data)
        else:
            new_node = Node(data)

            if index < self._size // 2:  # closer to head, start search from there
                node = self._head
                for i in range(index):
                    node = node.next
            else:  # otherwise, start from tail
                node = self._tail
                for i in range(self.size - index - 1):
                    node = node.prev

            if node.prev is not None:
                node.prev.next = new_node
                new_node.prev = node.prev
                new_node.next = node
                node.prev = new_node

            if node is self._head:
                self._head = new_node

            self._size += 1

    def is_empty(self):
        """Returns True if the list is empty, otherwise False.
        :return: A boolean indicating whether the list is empty.
        >>> my_list = DoublyLinkedList()
        >>> my_list.is_empty()
        True
        >>> my_list = DoublyLinkedList([1])
        >>> my_list.is_empty()
        False
        """
        return self._size == 0

    def pop(self):
        """Removes and returns the data from the beginning of the list.
        :return: The data.
        :exception: IndexError is raised if list is empty.
        >>> my_list = DoublyLinkedList([1, 2, 3])
        >>> my_list.pop()
        1
        >>> my_list = DoublyLinkedList([2])
        >>> my_list.pop()
        2
        """
        if self._head is None:
            raise IndexError("list is empty")

        if self._head == self._tail:
            node = self._head
            self._head = None
            self._tail = None
            self._iter_node = None
            self._size -= 1

            return node.data

        head = self._head
        self._head = head.next
        self._head.prev = None

        # Update iterable ptr
        if self._iter_node == head:
            self._iter_node = self._head

        self._size -= 1

        return head.data

    def pop_last(self):
        """Removes and returns the data from the beginning of the list.
        :return: The data.
        :exception: IndexError is raised if list is empty.
        >>> my_list = DoublyLinkedList([1, 2, 3])
        >>> my_list.pop_last()
        3
        >>> my_list = DoublyLinkedList([2])
        >>> my_list.pop_last()
        2
        """
        if self._head is None:
            raise IndexError("list is empty")

        if self._head == self._tail:
            node = self._head
            self._head = None
            self._tail = None
            self._iter_node = None
            self._size -= 1

            return node.data

        tail = self._tail
        self._tail = tail.prev
        self._tail.next = None

        # Update iterable ptr
        if self._iter_node == tail:
            self._iter_node = None

        self._size -= 1

        return tail.data

    def prepend(self, data):
        """Prepends the data to the end of the list.
         :param data: The data to append.
         >>> my_list = DoublyLinkedList()
         >>> my_list.prepend(5)
         >>> my_list
         [5]
         >>> my_list = DoublyLinkedList([3, 4])
         >>> my_list.prepend(1)
         >>> my_list
         [1, 3, 4]
         """
        self._size += 1

        if self._head is None:
            node = Node(data)
            self._head = node
            self._tail = node
        else:
            head = self._head

            self._head = Node(data)
            self._head.next = head
            self._head.next.prev = self._head

    def remove(self, index: int):
        """Removes and returns the data at the given index.
         :param index: The index to remove.
         :return: The data at the index.
         :exception: IndexError is raised if index is out of bounds.
         >>> my_list = DoublyLinkedList([4, 7, 2])
         >>> my_list.remove(0)
         4
         >>> my_list = DoublyLinkedList([3, 4])
         >>> my_list.remove(-1)
         4
         """
        if index < -self.size or index >= self.size or self._head is None:
            raise IndexError("index is out of range")

        if index < 0:
            index = self.size + index

        if index == 0:
            head = self._head
            self._head = self._head.next

            # Update iterable ptr
            if self._iter_node == head:
                self._iter_node = self._head

            self._size -= 1
            return head.data
        else:
            if index < self.size // 2:  # closer to head, start search from there
                node = self._head
                for i in range(index):
                    node = node.next

            else:  # otherwise, start from tail
                node = self._tail
                for i in range(self.size - index - 1):
                    node = node.prev

            if node.prev is not None:
                node.prev = node.next

            if node.next is not None:
                node.next = node.prev

            if node is self._head:
                self._head = node.next

            if node is self._tail:
                self._tail = node.prev

            # Update iterable ptr
            if self._iter_node == node:
                self._iter_node = node.next

            self._size -= 1
            return node.data

    def remove_item(self, data):
        """Removes the first occurrence of the given data.
         :param data: The data to remove.
         :exception: ValueError is raised if item is not found.
         >>> my_list = DoublyLinkedList([4, 7, 2])
         >>> my_list.remove_item(7)
         >>> my_list
         [4, 2]
         >>> my_list = DoublyLinkedList([3, 4, 3])
         >>> my_list.remove_item(3)
         >>> my_list
         [4, 3]
         """
        next_node = self._head

        while next_node is not None:
            if next_node.data == data:
                if next_node.prev is not None:
                    next_node.prev.next = next_node.next

                if next_node.next is not None:
                    next_node.next.prev = next_node.prev

                if next_node == self._head:
                    self._head = next_node.next

                if next_node == self._tail:
                    self._tail = next_node.prev

                # Update iterable ptr
                if self._iter_node == next_node:
                    self._iter_node = next_node.next

                self._size -= 1
                return

            next_node = next_node.next

        raise ValueError("item not found")

    def reverse(self):
        """Reverses the list.
        >>> my_list = DoublyLinkedList([1, 2, 3])
        >>> my_list.reverse()
        >>> my_list
        [3, 2, 1]
        """
        node = self._head
        while node is not None:
            node.next, node.prev = node.prev, node.next
            node = node.prev

        self._head, self._tail = self._tail, self._head


if __name__ == '__main__':
    import doctest
    doctest.testmod()
