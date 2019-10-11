#include<bits/stdc++.h>
#define N 5
using namespace std;

void printSolution(int board[N][N])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return ;
}
bool isSafe(int board[N][N],int row,int col)
{
    int i,j;
    for(i=0;i<col;i++)
    {
        if(board[row][i])
            return false;
    }
    for(i=row,j=col;i>=0 && j>=0 ; i-- ,j--)
    {
        if(board[i][j])
            return false;
    }
    for(i=row,j = col;i<N && j>=0 ;i++,j--)
    {
        if(board[i][j])
            return false;
    }
    return true;
}

bool solveNQUtil(int board[N][N], int col)
{
    if (col >= N)
		return true;
	for (int i = 0; i < N; i++)
	{
		if ( isSafe(board, i, col) )
		{
			board[i][col] = 1;
			if ( solveNQUtil(board, col + 1) )
				return true;
			board[i][col] = 0;
		}
	}
	return false;
}

bool solveQueen()
{
    int board[N][N] ,i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            board[i][j] = 0;
        }
    }

    if(solveNQUtil(board,0)==false)
    {
        cout<<"\n\nNo solution exist for this N..."<<endl;
        return false;
    }
    printSolution(board);
    return true;
}
int main(void)
{
    solveQueen();
    return 0;
}
