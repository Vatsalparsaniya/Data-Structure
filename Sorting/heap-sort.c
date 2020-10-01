#include<stdio.h>
#include<math.h>
int arr[100];
void heapify(int a)
{
    int b=log(a)/log(2);
    printf("a is %d\n",a);
	printf("b is %d\n",b);
    int i,par,ch,temp,ch1,ch2,mxc;
    for(i=pow(2,b)-2;i>-1;i--)
    {
        par=i;    
		printf("parent is   %d\n",i);    
        while(par<=a-1)
        {
            ch1=2*par+1;
            ch2=2*par+2;
            mxc=ch1;
            if(ch1>=a)
                arr[ch1]=-999;
            if(ch2>=a)
                arr[ch2]=-999;
            
            if(arr[ch2]>arr[mxc])
                mxc=ch2;
            
            if(arr[mxc]<arr[par])
                break;
            else
            {
                //swap
                temp=arr[mxc];
                arr[mxc]=arr[par];
                arr[par]=temp;
            }
            par=mxc;
        }                    
    }
}
int main()
{
    int a,b,c,d,e,f;
    scanf("%d",&a);//number of elements in the array
    for(b=0;b<100;b++)
    {
        arr[b]=-100;
    }
    for(b=0;b<a;b++)
    {
        scanf("%d",&arr[b]);
    }arr[a]=-1;
   while(a!=0)
   {
        heapify(a);
        printf("%d  ",arr[0]);
        arr[0]=arr[a-1];
        a--;
   }
   
}
