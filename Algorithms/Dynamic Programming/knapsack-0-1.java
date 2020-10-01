public class knapsack01 {

	public static int getMax(int a,int b) {
		if(a>b)
			return a;
		return b;
	}
  
	public static void main(String args[]) {
		int values[]=new int[] {10,15,40};
		int weights[]=new int[] {1,2,3};
		int total=6;
		int arr[][]=new int[weights.length+1][total+1];
		for(int i=0;i<weights.length+1;i++) {
			for(int j=0;j<total+1;j++) {
				if(i*j==0);
				else if(j-weights[i-1]>=0) {
					//max value from
					//1.same Column above value
					//2.i-1 th value + arr[i-1][j-weights[i-1]]
					arr[i][j]=getMax(arr[i-1][j],values[i-1]+arr[i-1][j-weights[i-1]]);
				}
				else {
					arr[i][j]=arr[i-1][j];
				}
				System.out.print(arr[i][j] + "  ");
			}System.out.println("");
		}
		System.out.println(arr[weights.length][total]);
	}
  
}


//Output:
/*0  0  0  0  0  0  0  
0  10  10  10  10  10  10  
0  10  15  25  25  25  25  
0  10  15  40  50  55  65  
65*/
