/*
 *    Java Program to Implement Self organizing List
 */
 
import java.util.Scanner;
 
/* Class SelfOrganizingList */
class SelfOrganizingList
{
    private int[] list;
    private int[] count;
    private int size;
 
    /* Constructor */
    public SelfOrganizingList(int listSize)
    {
        list = new int[listSize];
        count = new int[listSize];
        size = 0;        
    }
    /* Function to check is empty */
    public boolean isEmpty()
    {
        return size == 0;
    }
    /* Function to check if full */
    public boolean isFull()
    {
        return size == list.length;
    }
    /* Function to make list empty */
    public void makeEmpty()
    {
        int l = list.length;
        list = new int[l];
        count = new int[l];
        size = 0;        
    }
    /* Function to get size of list */
    public int getSize()
    {
        return size;
    }
    /* Function to insert element */
    public void insert(int val)
    {
        if (isFull() )
        {
            System.out.println("Error : List full!");
            return;
        }
        list[size] = val;
        count[size] = 0;
        size++;
    }
    /* Function to remove element */
    public void remove(int pos)
    {
        pos-- ;
        if (pos < 0 || pos >= size )
        {
            System.out.println("Invalid position ");
            return;
        }
        for (int i = pos; i < size - 1; i++)
        {
            list[i] = list[i + 1];
            count[i] = count[i + 1];
        }
        size--;        
    }
    /* Function to search for an element */
    public boolean search(int x)
    {
        boolean searchResult = false;
        int pos = -1;
        for (int i = 0; i < size; i++)
        {
            if (list[i] == x)
            {
                searchResult = true;
                pos = i;
                break;
            }
        }
        if (searchResult)
        {
            count[pos]++;
            int c = count[pos];
            for (int i = 0; i < pos; i++)
            {
                if (count[pos] > count[i])
                {
                    for (int j = pos; j > i; j--)
                    {
                        list[j] = list[j - 1];
                        count[j] = count[j - 1];
                    }
                    list[i] = x;
                    count[i] = c;
                    break;
                }
            }
        }
        return searchResult;        
    }
    /* Function to print list */
    public void printList()
    {
        System.out.print("\nList = ");
        for (int i = 0; i < size; i++)
            System.out.print(list[i] +" ");
        System.out.print("\nCount = ");
        for (int i = 0; i < size; i++)
            System.out.print(count[i] +" ");
    }
}
 
/*  Class SelfOrganizingListTest  */
public class SelfOrganizingListTest
{    
    public static void main(String[] args)
    {             
        Scanner scan = new Scanner(System.in);
        System.out.println("SelfOrganizingList Test\n"); 
 
        /* Creating object of class SelfOrganizingList */
        System.out.println("Enter size of list ");
        SelfOrganizingList list = new SelfOrganizingList(scan.nextInt() ); 
 
        char ch;
        /*  Perform list operations  */
        do    
        {
            System.out.println("\nSelfOrganizingList Operations\n");
            System.out.println("1. insert ");
            System.out.println("2. delete at position");
            System.out.println("3. search");
            System.out.println("4. check empty");
            System.out.println("5. check full"); 
            System.out.println("6. get size");            
            int choice = scan.nextInt();            
            switch (choice)
            {
            case 1 : 
                System.out.println("Enter integer element to insert");
                list.insert( scan.nextInt() );                     
                break;                          
            case 2 : 
                System.out.println("Enter position to delete");
                list.remove(scan.nextInt() );                     
                break;                         
            case 3 : 
                System.out.println("Enter integer element to search");
                System.out.println("Search Result : "+ list.search(scan.nextInt() ));
                break;                                          
            case 4 : 
                System.out.println("Empty status = "+ list.isEmpty());
                break;     
            case 5 : 
                System.out.println("Full status = "+ list.isFull());
                break;                     
            case 6 :  
                System.out.println("Size = "+ list.getSize() +" \n");
                break;                         
            default : 
                System.out.println("Wrong Entry \n ");
                break;    
            }
            /*  Display List  */  
            list.printList();
 
            System.out.println("\nDo you want to continue (Type y or n) \n");
            ch = scan.next().charAt(0);                        
        } while (ch == 'Y'|| ch == 'y');               
    }
}