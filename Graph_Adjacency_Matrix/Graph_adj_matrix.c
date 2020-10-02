//... A Program to represent a Graph by using an Adjacency Matrix method
#include <stdio.h>
#include <stdlib.h>
void main()
{
   int option;
   do
   {    	
        printf("\n A Program to represent a Graph by using an ");
	printf("Adjacency Matrix method \n ");
	printf("\n 1. Directed Graph ");
	printf("\n 2. Un-Directed Graph ");
	printf("\n 3. Exit ");
	printf("\n\n Select a proper option : ");
	scanf("%d", &option);
	switch(option)
	{
            case 1 : dir_graph();
                     break;
            case 2 : undir_graph();
                     break;
            case 3 : exit(0);
	} // switch
    }while(1);
}
 
int dir_graph()
{
    int adj_mat[50][50];
    int n;
    int in_deg, out_deg, i, j;
    printf("\n How Many Vertices ? : ");
    scanf("%d", &n);
    read_graph(adj_mat, n);
    printf("\n Vertex \t In_Degree \t Out_Degree \t Total_Degree ");
    for (i = 1; i <= n ; i++ )
    {
        in_deg = out_deg = 0;
	for ( j = 1 ; j <= n ; j++ )
	{
            if ( adj_mat[j][i] == 1 )
                in_deg++;
	} 
        for ( j = 1 ; j <= n ; j++ )
            if (adj_mat[i][j] == 1 )
                out_deg++;
            printf("\n\n %5d\t\t\t%d\t\t%d\t\t%d\n\n",i,in_deg,out_deg,in_deg+out_deg);
    }
    return;
}
 
int undir_graph()
{
    int adj_mat[50][50];
    int deg, i, j, n;
    printf("\n How Many Vertices ? : ");
    scanf("%d", &n);
    read_graph(adj_mat, n);
    printf("\n Vertex \t Degree ");
    for ( i = 1 ; i <= n ; i++ )
    {
        deg = 0;
        for ( j = 1 ; j <= n ; j++ )
            if ( adj_mat[i][j] == 1)
                deg++;
        printf("\n\n %5d \t\t %d\n\n", i, deg);
    } 
    return;
} 
 
int read_graph ( int adj_mat[50][50], int n )
{
    int i, j;
    char reply;
    for ( i = 1 ; i <= n ; i++ )
    {
        for ( j = 1 ; j <= n ; j++ )
        {
            if ( i == j )
            {
                adj_mat[i][j] = 0;
		continue;
            } 
            printf("\n Vertices %d & %d are Adjacent ? (Y/N) :",i,j);
            scanf("%c", &reply);
            if ( reply == 'y' || reply == 'Y' )
                adj_mat[i][j] = 1;
            else
                adj_mat[i][j] = 0;
	}
    } 
    return;
}