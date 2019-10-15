
class Solution{
	final int N = 8;
	static int count = 1;
	public boolean isSafe(int board[][], int row, int col){
		int i, j;
		for(i=0;i<col;i++){
			if(board[row][i] == 1)
				return false;
		}	// rightmost
		
		for(i=row, j=col;i>=0 && j>=0;i--,j--){
			if(board[i][j]==1)
				return false;
		}	//upper left diagonal 
		
		for(i=row, j=col; i<N && j>=0; i++, j--){
			if(board[i][j]==1)
				return false;
		}	//bottom left diagonal
		return true;
	}
	
	public boolean solve(){
		int board[][] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
		
		if(solveUtil(board, 0)==false)
		{
			System.out.println("Solution doesn't exist");
			return false;
		}
		//printSolution(board);
		return true;
	}
	
	public void printSolution(int board[][]){
		int i, j;
		System.out.println(count++);
		for(i=0;i<N;i++){
			for(j=0;j<N;j++)
				System.out.print("|"+board[i][j]+"|");
			System.out.println("");
		}
		System.out.println("--------------------------");
	}
	
	public boolean solveUtil(int board[][], int col){
			int i, j;
			if(col==N){
				printSolution(board);	//NQueen - all posibilities
				return true;	// solution ends
			}
			
			boolean res = false;	//NQueen - all posibilities
			for(i=0;i<N;i++){
				if(isSafe(board, i, col)){
					board[i][col] = 1;
					//print a Solution(board);
					/*if(solveUtil(board, col+1))
						return true;
					*/
					
					res = solveUtil(board, col+1) || res;	//NQueen - all posibilities
					board[i][col] = 0;	//backtrack
				}
			}
			//return false;
			return res;	//NQueen - all posibilities
	}
}
public class NQueen{
	public static void main(String args[]){
		Solution obj = new Solution();
		obj.solve();
	}
}