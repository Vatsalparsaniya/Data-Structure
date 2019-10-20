import java.util.Arrays;
class Heapify{
public void heapify(int arr[],int i,int modifiedLast){
	if((2*i+1)>modifiedLast)
	  return ;
    if((2*i+2)<modifiedLast && arr[i]<arr[2*i+2])
      (new Build_max_heap()).swap(arr,2*i+2,i);
     if(arr[i]<arr[2*i+1])
     (new Build_max_heap()).swap(arr,2*i+1,i);
}
}
class Build_max_heap{
	 public void buildHeap(int arr[],int i){
		        if ((i-1)/2<0)
		         return;
		         int child=i;
		         int parent=(i-1)/2;
		         if(arr[child]>arr[parent])
		           swap(arr,child,parent);
    }
	public void swap(int arr[],int child,int parent){
	        int temp=arr[child];
	        arr[child]=arr[parent];
	        arr[parent]=temp;
	    }
}
public class Heap_sort
{
   public static void main(String[] args) {
		int arr[]={56,23,67,32,98,76,0};


		Build_max_heap obj=new Build_max_heap();
		for(int j=0;j<arr.length;j=j+1){
		    obj.buildHeap(arr,j);//this function create min heap in O(n) time which is most efficient way to build a heap
	}


	     Heapify hp=new Heapify();
         for(int modifiedLast=arr.length-1;modifiedLast>=0;modifiedLast=modifiedLast-1){
			hp.heapify(arr,0,modifiedLast);
			(new Build_max_heap()).swap(arr,0,modifiedLast);
		}
		System.out.println(Arrays.toString(arr));
		//output:[0,23, 32, 56, 67, 76, 98]
	}
}