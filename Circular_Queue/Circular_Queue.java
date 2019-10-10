import java.util.Scanner;
class Circular_Queue
{
    public static int front=-1;
    public static int rear=-1;
    public static int queue[] = new int[20];
    
    void insertQueue(int item) 
    {
        int rear = (Circular_Queue.rear+1)mod n;
        int front = Circular_Queue.front;
        int n =20;
        if(front == rear)
        {
            System.out.println("Queue is full");
            if(rear == 0)
            {
                Circular_Queue.rear = n-1;
            }
            else{
                Circular_Queue.rear = rear -1;
                return -1;
            }
        }
        else{
            Circular_Queue.queue[rear] = item;
        }
    }

    int deleteQueue()
    {
        int rear = Circular_Queue.rear;
        int front = Circular_Queue.front;
        int n =20;
        if(front == rear)
        {
            System.out.println("Queue is empty");
            return -1;
        }
        else{
            front = (front+1)mod n;
            item = Circular_Queue.queue[front];
            return item;
        }
    }


    public static void main(String args[])
    {
        System.out.println("Press 1. Insert in the Queue \nPress 2. Delete from the Queue \nPress 3. Exit ");
        int choice = 0;
        Scanner sc = new Scanner(System.in);
        
        while(choice!= 3)
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
                    deleteQueue();
                    break;
                
                case 3:
                    System.out.println("Thank you :)");
                    break;
            
                default:
                    break;
            }
        }
    }
}