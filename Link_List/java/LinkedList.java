
public class LinkedList {
    private Node head;

    public LinkedList() {
        head = null;
    }

    public void printHead() {
        System.out.println(head.getValue());
    }

    //Creates linkedList with head value
    public LinkedList(int v) {
        head = new Node(v);
    }

    // Method to insert a new node 
    public void addLast(int data) { 
        // Create a new node with given data 
        Node newNode = new Node(data); 
        newNode.nextNode = null; 
   
        // If the Linked List is empty, 
        // then make the new node as head 
        if (this.head == null) { 
            this.head = newNode; 
        } 
        else { 
            // Else traverse till the last node 
            // and insert the newNode there 
            Node last = this.head; 
            while (last.nextNode != null) { 
                last = last.nextNode; 
            } 
   
            // Insert the newNode at last node 
            last.setNextNode(newNode);
        } 
   
    } 

    //Adds node to front of linked list
    //(Essentially replaces the head)
    public void addFirst(int data) {
        Node newNode = new Node(data);
        if(this.head != null) {
            newNode.setNextNode(head);
        }

        this.head = newNode;
    }

    //removes last node from linked list
    public void pop() {

        //Gets head node
        Node lastNode = this.head;

        //Iterates over linked list
        //Once final node is located it, the previous node's next node is set to null
        //The loop is then broken
        while(lastNode.getNextNode() != null) {
            if(lastNode.getNextNode().getNextNode() == null) {
                lastNode.setNextNode(null);
                break;
            }

            lastNode = lastNode.getNextNode();
        }
    }

    //Method to display the content of the linked list
    public void display() {
        Node currentNode = this.head;
        while(currentNode != null) {
            System.out.println(currentNode.getValue());
            currentNode = currentNode.getNextNode();
        }
    }
}