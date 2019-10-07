#include<iostream.h>
#include<conio.h>
int Bsearch(int[ ],int,int);
void main()
{    clrscr();
     int AR[50],item,n,index;
     cout<<"Enter desired array size(max. 50):) ";
     cin>>n;
     cout<<"Enter array elements:\n";
     for(int i=0;i<n;i++)
	 { cin>>AR[i]; }
     cout<<"\nEnter element to be searched for: ";
     cin>>item;
     index=Bsearch(AR,n,item);
     if(index==-1)
	cout<<"\nSorry!!Given element could not be found.\n";
     else
	cout<<"\nElement found at index:"<<index<<",Position:"<<index+1<<endl;
     getch();
}
int Bsearch(int AR[ ],int size,int item)
{    int beg,last,mid;
     beg=0;
     last=size-1;
     while(beg<=last)
     {                mid=(beg+last)/2;
	 if(item==AR[mid]) { return mid; }
	 else if(item>AR[mid])
	     beg=mid+1;
	 else
	     last=mid-1;
     }   return -1;
}
