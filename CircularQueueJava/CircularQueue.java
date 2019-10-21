import java.util.*;
import java.lang.*;

/*
    code By Varul Srivastava
    First Year undergraduate at IIIT Hyderabad
*/

public class CircularQueue {
    int size;
    int start = -1, end=0;
    int queue_arr[];
    int c=-1729;
    public CircularQueue(int length){
        queue_arr=new int[length];
        
        size=length;
        length--;
        while(length>=0){
            queue_arr[length--]=-1729; //this number cannot be the value of any index. Make it settable.
        }
        start=-1;
        end=-1;
    }


    //overloaded constructor that takes the prohibited value of the queue
    public CircularQueue(int length,int c){
        queue_arr=new int[length--];
        this.c=c;
        size=length;
        while(length>=0){
            queue_arr[length]=c; //this number cannot be the value of any index. Make it settable.
        }
        start=-1;
        end=-1;
    }

    //enter an element in the end of queue
    public void pushEnd(int value){
        try{
            if( end==start && end !=-1 && queue_arr[end]!=c )
            {
                System.out.println("Out of Bounds");
            }
            else if(end==start && start==-1){
                end=start=0;
                queue_arr[end]=value;
                end++;
            }
            else
            {
                if(end==size){
                    end=0;
                }

                queue_arr[end]=value;
                end++;
                if(end==size){
                    end =0;//when elements have not been popped out from queue
                }
            }
        }
        
        catch(Exception e){
            System.err.println(e);
        } 
    }



    //pull out an element from the queue
    public int popFront(){
        if(start==size){
            start=0;
        }
        if(start==-1 || (start==end && queue_arr[start]==c)){
            System.err.println("IndexOutOfBounds");
            
            // throw new emptyStackException;
            return -1;    //Some developer desired constant (not necessary)
        }
        int ret= queue_arr[start];
        queue_arr[start++]=c;
        return ret;
        
    }
    
    //checks if the stack is empty
    public boolean isEmpty(){
        return start==end && (start==-1 || queue_arr[start]==c);
    }

    //checks if stack is full
    public boolean isFull(){
        return start==end && queue_arr[end]==c;
    }

    //main method to test the code
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        
        System.out.println("Enter the size of Queue");
        int length=sc.nextInt();
        CircularQueue ob=new CircularQueue(length);

        char ch='y';//default set to yes, can be changed to No, doesnot matter
        do{
            System.out.println("1-Add an element to the Queue at the end\n2-Check wether the Queue is empty\n3-Return/Delete an Element from the Front\n4-Check if Queue is Full");
            System.out.println("Enter the option");
            int opt=sc.nextInt();//option choosen by the user
            switch(opt){
                case 1:
                System.out.println("Enter the element to be inserted to Queue");
                int elem=sc.nextInt();
                ob.pushEnd(elem);
                break;
                case 2:
                if(ob.isEmpty()){
                    System.out.println("Queue is Empty");
                }
                else{
                    System.out.println("Queue is Not Empty");
                }
                break;
                case 3:
                System.out.println("Enter the deleted/returned is :"+ob.popFront());
                break;
                case 4:
                if(ob.isFull()){
                    System.out.println("Queue is Full");
                }
                else{
                    System.out.println("Queue is not Full");
                }
                default:
                System.out.println("Wrong input");
            }
            System.out.println("Do you want to continue for more inputs?(y/n)");//Any random character will be considered as No
            ch=sc.next().charAt(0);
            ch=Character.toLowerCase(ch);

        }while(ch=='y');

        /*created Date Monday October 7 2019 1800 hrs 
         last modified Saturday October 12 2019 1913 hrs

        Further Edits:Change options according to the methods 
                Check -1 or 0 cases of queue
                Run and debug the codes 
                Add better comments

*/


    }

}
