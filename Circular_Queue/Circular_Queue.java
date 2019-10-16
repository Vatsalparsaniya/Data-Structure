import java.util.Scanner;
class Circular_Queue
{
    public static int front= 0;
    public static int rear= 0;
    public static int queue[] = new int[5];

    static void insertQueue(int item)
    {
        int n =5;
        Circular_Queue.rear = (Circular_Queue.rear+1) % n;

        if(Circular_Queue.front == Circular_Queue.rear)
        {
            System.out.println("Queue is full");
            if(Circular_Queue.rear == 0)
            {
                Circular_Queue.rear = n-1;
            }
            else{
                Circular_Queue.rear = Circular_Queue.rear -1;

            }
        }
        else{
            Circular_Queue.queue[rear] = item;
        }

    }

    static int deleteQueue()
    {
        int n = 5;
        if(Circular_Queue.front == Circular_Queue.rear)
        {
            System.out.println("Queue is empty");
            return -1;
        }
        else{
            Circular_Queue.front = (Circular_Queue.front+1) % n;
            int item = Circular_Queue.queue[Circular_Queue.front];
            Circular_Queue.queue[Circular_Queue.front] = 0;
            return item;
        }
    }

    static void displayQueue(){
        System.out.println("Queue is:\n ");
        for(int i = 0; i<Circular_Queue.queue.length ; i++)
        {
            System.out.println(queue[i]);
        }
    }


    public static void main(String args[])
    {
        System.out.println("Press 1. Insert in the Queue \nPress 2. Delete from the Queue \nPress 3. Display Queue \n Press 4. Exit");
        int choice = 0;
        Scanner sc = new Scanner(System.in);

        while(choice!= 4)
        {
            System.out.println("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Enter the element you want to insert: ");
                    int ele = sc.nextInt();
                    insertQueue(ele);
                    break;

                case 2:
                    int item = deleteQueue();
                    System.out.println("Deleted Value is: " + item);
                    break;
                case 3:
                    displayQueue();
                    break;

                case 4:
                    System.out.println("Thank you :)");
                    break;

                default:
                    break;
            }
        }
    }
}