import java.util.Scanner;

//made by nilesh teji
//10-10-2019
class Solution{
    public static void main(String[] args) {
        System.out.print("Enter the Number of Elements of array");
        Scanner obj=new Scanner(System.in);
        int a=obj.nextInt();
        int[] array=new int[a];
        for(int i=0;i<a;i++){
            array[i]=obj.nextInt();
        }
 //Sorting Algorithm 

for(int i=0;i<a;i++){
    for(int j=i+1;j<a;j++){
        if(array[i]>array[j]){
            int temp=array[i];
            array[i]=array[j];
            array[j]=temp;
        }

    }
}



for(int i=0;i<a;i++){
    System.out.println(array[i]);
}



    }
}