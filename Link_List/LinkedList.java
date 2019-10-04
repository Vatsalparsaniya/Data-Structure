
import java.util.NoSuchElementException;

// Class to create a Node that contains data and pointer to next Node
class Node<T>{
    public T data;
    public Node<T> next;

    // Constructor to create a Node
    public Node(T input){
        this.data = input;
        this.next = null;
    }
}

// Class containing methods to be performed on Linked List
public class LinkedList<T> {

    private Node<T> head;
    private int sizeOfList = 0;

    public LinkedList(){
        head = null;
    }

    // Method to add an element to the start of the Linked List
    public void addFront(T input){
        Node<T> newNode = new Node<T>(input);
        newNode.next = head;
        head = newNode;
        sizeOfList++;
    }

    // Method to add an element to the end of the Linked List
    public void addLast(T input){
        if(head==null){
            Node<T> newNode = new Node<T>(input);
            head = newNode;
            sizeOfList = 1;
        } else{
            Node<T> temp = head;
            while (temp.next != null){
                temp = temp.next;
            } Node<T> newNode = new Node<T>(input);
            temp.next = newNode;
            sizeOfList++;
        }
    }


    // Method to add an element at a given index
    public void add(T input, int index){
        if (index<0 || index>sizeOfList){
            throw new IndexOutOfBoundsException("Invalid index.");
        }
        Node<T> temp = head;
        if(index ==0){
            addFront(input);
        } else {
            for (int i =0; i< index-1; i++){
                temp = temp.next;
            }
            Node<T> newNode = new Node<T>(input);
            newNode.next = temp.next;
            temp.next = newNode;
            sizeOfList++;
        }
    }

    public boolean isEmpty() {
        return sizeOfList == 0;
    }

    // Method to remove the Firt element from the Linked List
    public T removeFront(){
        if(isEmpty()){
            throw new NoSuchElementException();
        }
        T removedElement = head.data;
        head = head.next;
        sizeOfList--;

        return removedElement;
    }

    // Method to remove the front element from the Linked List
    public T removeLast(){
        if(isEmpty()){
            throw new NoSuchElementException();
        }
        T removedElement;
        if(head.next == null){
            removedElement = head.data;
            head = null;
        }else{
            Node<T> temp = head;
            while ( temp.next.next!= null)
                temp = temp.next;
            removedElement = temp.next.data;
            temp.next=null;
        }

        sizeOfList--;
        return removedElement;
    }

    // Method to remove element at specific index from the Linked List
    public T remove(int index){
        if(isEmpty()){
            throw new NoSuchElementException();
        }if(index<0 || index> sizeOfList){
            throw new IndexOutOfBoundsException();
        }

        if(index>0){
            Node<T> temp = head;
            for (int i =0; i<index-1;i++){
                temp = temp.next;
            }
            T removedElement = temp.next.data;
            temp.next = temp.next.next;

            sizeOfList--;
            return  removedElement;
        }
        return removeFront();
    }

    public int search(T input){
        Node<T> temp = head;
        for (int i = 0; i < sizeOfList; i++) {
            if (temp.data == input)
                return i;
            else
                temp = temp.next;
        }
        return -1;
    }

    public void display() {
        Node<T> temp = head;
        if (temp != null) {
            System.out.print("[");
            while (temp != null) {
                System.out.print(temp.data+", ");
                temp = temp.next;
            }
            System.out.print("\b\b]\n");
        }
    }

    public int size() {
        return sizeOfList;
    }


    public static void main(String[] args) {

        LinkedList<Integer> list = new LinkedList<Integer>();

        list.addFront(10);
        list.addFront(20);

        list.display();

        list.addFront(30);
        list.addFront(40);

        list.display();

        list.removeFront();

        list.display();

        list.removeLast();
        list.display();

        list.addLast(50);
        list.addLast(60);

        list.remove(2);
        list.display();

        int found = list.search(20);
        if (found >= 0)
            System.out.println("Element found at index: " + found);
        else
            System.out.println("Element not found");

        if (list.isEmpty())
            System.out.println("List is empty");
        else
            System.out.println("List is not empty, Size of list: " + list.size());

    }

}
