import java.util.*;
class Solution{
	final int N = 3;	//4x4 matrix
        static int count = 0;
	public boolean isSafe(int maze[][], int x, int y){
		return (x>=0 && x<N && y>=0 && y<N && maze[x][y]==1);
	}
	
	public boolean solve(int maze[][]){
		int sol[][] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
		if(solveMazeUtil(maze, 0, 0, sol)==false)
		{
			System.out.println("Solution doesn't exit");
                        printSolution(sol);
			return false;
		}
		printSolution(sol);
		return true;
	}
	
	public void printSolution(int sol[][]){
		int i, j;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				System.out.print(sol[i][j]+" ");
			}
			System.out.println(" ");
		}
	}
	
	public boolean solveMazeUtil(int maze[][], int x, int y, int sol[][]){
		if(x==N-1 && y==N-1){	//reaches (4,4)
			sol[x][y] = 1;
			return true;
		}
		if(isSafe(maze, x, y)){
			sol[x][y] = 1;
			if(solveMazeUtil(maze, x+1, y, sol))	//bottom
				return true;
			if(solveMazeUtil(maze, x, y+1, sol))	//forward
				return true;
			System.out.println(x+" "+y);
			sol[x][y] = 0;
                        count++;
			return false;
		}
		
		return false;
	}
}
public class RatInMaze{
	public static void main(String args[]){
		/*int maze[][] = {{1, 1, 1, 1},
                                {1, 0, 1, 1},
                                {0, 1, 1, 0},
                                {1, 1, 0, 1}};
		*/
                
                int maze[][] = {{1, 1, 0},
                                {0, 1, 1},
                                {0, 1, 1}};
                Solution obj = new Solution();
		obj.solve(maze);
	}
}