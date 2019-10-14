public class Queue { //Queue(fifo data structure) class that gets initialized with fixed value
    int values[]; //array that holds the values in the array
    int rear,front, capacity;

    public Queue(int n) { //n will be the length of the Queue
        capacity = n; //capacity set
        rear = front = 0; //rear and front are set to the same
        values = new int[capacity]; //values set to the capacity size
    }

    public void enqueue(int value) { //adds value to queue(enqueue)
        if(capacity == rear) {
            System.out.println("The queue is full"); //if queue is full, error message is printed
        } else { //other wise value is added to end of queue
            values[rear] = value;
            rear++; //end value is incrmented
        }

    }

    public void dequeue() { //empties the front value of the queue
        if(front == rear) {
            System.out.println("The queue is empty"); //prints error message if queue is empty
        } else {
            for(int i=0; i<values.length-1; i++) { //otherwise, front value(first one entered) is removed
                values[i] = values[i+1];
            }

            rear--; //en d value is decremented
        }
    }

    public void display() { //simple method to print out the queue
        if(front == rear) {
            System.out.println("The queue is empty"); //shows that queue is empty
        } else {
            for(int i=front; i<rear; i++) { //iteraters over values and prints them 
                if(i != rear-1)
                    System.out.print(values[i] + " <--- ");
                else
                    System.out.print(values[i]);

            }
        }
    }


}