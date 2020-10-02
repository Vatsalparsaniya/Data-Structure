import java.util.*;
public class Main
{
	public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int a,b,c;
        a=s.nextInt();//size of the array
        int arr[]=new int[a];
        int ans[]=new int[a];
        for(int i=0;i<a;i++)
        {
            c=s.nextInt();
            arr[i]=c;
            //b is parent
            b=i+1;
            while(b<=a)
            {
                
                ans[b-1]+=c;
                b=b+(b&(-b));
                //System.out.println("parent for "+(i+1)+"is "+b);
            }
        }
        for(int i=0;i<a;i++)
        {
            System.out.print(ans[i]+"  ");
        }
        b=s.nextInt();//getsum of first b integers
        if(b>a)
            a=-1;//not possible
        else
            a=getsum(b,ans,a);
        System.out.print(a);
        
	}
	public static int getsum(int b,int ans[],int a)
	{
	    int sol=0;
	    while(b!=0)
	    {
	        System.out.println("we added "+ ans[b-1]);
	        sol+=ans[b-1];
	        b=b-(b&(-b));
	    }return sol;
	}
}
