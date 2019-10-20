import java.util.Arrays;
class Heap{
	 public void buildHeap(int arr[],int i){
		        if ((i-1)/2<0)
		         return;
		         int child=i;
		         int parent=(i-1)/2;
		         if(arr[child]<arr[parent])
		           swap(arr,child,parent);
    }
	public void swap(int arr[],int child,int parent){
	        int temp=arr[child];
	        arr[child]=arr[parent];
	        arr[parent]=temp;
	    }

}
public class Build_heap
{

	public static void main(String[] args) {
		int arr[]={56,23,67,32,98,76};
		Heap obj=new Heap();
		for(int j=0;j<arr.length;j=j+1){
		    obj.buildHeap(arr,j);//this function create min heap in O(n) time which is most efficient way to build a heap
		}
		System.out.println(Arrays.toString(arr));
		//output:[23, 32, 67, 56, 98, 76]
	}
}