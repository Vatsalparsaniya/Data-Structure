import java.util.EmptyStackException;
import java.util.Iterator;
import java.util.LinkedList;

public class Stack <T> implements Iterable <T> {
    
    private LinkedList <T> list = new java.util.LinkedList <T>();

    // Create an empty stack
    public Stack() { }

    // Create a Stack with an initial element
    public Stack(T firstElem) {
        push(firstElem);
    }

    // Return the number of elements in the stack
    public int size() {
        return list.size();
    }

    // Check if the stack is empty
    public boolean isEmpty() {
        return size() == 0;
    }

    // Push an element on the stack
    public void push(T elem) {
        list.addLast(elem);
    }

    // Pop an element off the stack
    // Throws an error is the stack empty
    public T pop() {
        if (isEmpty())
            throw new EmptyStackException();
        return list.removeLast();
    }

    // Peek the top of the stack without removing an element
    // Throws an exception if the stack is empty
    public T peek() {
        if (isEmpty())
            throw new EmptyStackException();
        return list.peekLast();
    }

    // Allow users to iterate through the stack using an iterator
    @Override public Iterator <T> iterator () {
        return list.iterator();
    }
}
