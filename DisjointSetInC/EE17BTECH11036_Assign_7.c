// Implementing disjoint sets (DSU) data structure using rank.

#include <stdio.h>
#include <stdlib.h>
struct node{
	int vertex,rank;
	struct node* parent;
};
void freedf(struct node**arr,int n){
     for(int i=0;i<n+1;i++)
     	free(arr[i]);
     free(arr);
     arr=NULL;
}
void makeset(struct node **arr,int n){
	 while(n){
	 	struct node *x=(struct node *)malloc(sizeof(struct node));
	 	x->vertex=n;
	 	x->parent=x;
	 	x->rank=1;
        arr[n--]=x;
      }
}
int findset(struct node *x){
	return x->parent==x ? x->vertex:findset(x->parent) ;
}
int findrank(struct node *x){
	return x->rank;
}
int relate_sets(struct node*a,struct node*b){
 	return findset(a)==findset(b)?1:0;
}
struct node *root(struct node*x){
	return x->parent==x ? x :root(x->parent) ;
}
void dounion(struct node *a,struct node *b){
		struct node* a_rep=root(a),*b_rep=root(b);
		if(a_rep != b_rep){                // If they are not in same set aldready
			if(b_rep->rank > a_rep->rank)
				a_rep->parent = b_rep;     // Making higher ranked root node , parent
			else
				b_rep->parent = a_rep;
			if(a_rep->rank == b_rep->rank)
				a_rep->rank++;
		}
	}
	
/*

Input format:
 
Each line of the input looks like one of the following:
• ‘N’ followed by a positive integer n that indicates number of singleton sets to create.
• ‘?’ followed by two positive integers a and b separated by a space.
• ‘S’ followed by a positive integer a.
• ‘U’ followed by two positive integers a and b separated by a space.
• ‘R’ followed by a positive integer a.
Each of the lines above ends with a ‘\n’ character. All numbers used will fit inside an int.
End of input is indicated by EOF.
 


Sample input:

N 5
R 2
R 3
R 9
U 3 4
R 3
U 1 4
R 4
R 3
? 12 21
? 1 3
? 3 2
U 1 62
S 1
S 4
S 62
U 1 2
S 2
R 3
U 3 5
? 1 5
R 3
R 9
N 4
U 1 2
R 1
U 3 4
R 3
U 2 3
R 1
S 4
 * 
 * 
 * 
Output Format
• If input line was “N n”: No corresponding output.
• If input line was “U a b”: No corresponding output.
• If input line was “? a b”:
– Output −1 if either of a or b is not a valid element.
– Output 0 if a and b belong to different sets.
– Output 1 if a and b belong to the same set.

1

• If input line was “S a”:
Output the representative element of the set that contains a.
• If input line was “R a”:
Output the rank of a if a is a valid element. Output −1 otherwise.
All output lines end with a ‘\n’ character.
 * 
 * 
 * 
 */
int main(){
	int digit,N=-1,a,b;
	struct node **arr=NULL;
	while((digit=fgetc(stdin))!=EOF){
		if(digit=='N'){
			freedf(arr,N);
			scanf("%d",&N);
            arr=(struct node **)malloc((N+1)*sizeof(struct node*));
			makeset(arr,N);
		}
		else if(digit=='?'){
			scanf("%d%d",&a,&b);
			printf("%d\n",(a<=N && b<=N) ? relate_sets(arr[a],arr[b]) : -1);             
		}
		else if(digit=='S'){
			scanf("%d",&a);
			printf("%d\n",a<=N ? findset(arr[a]) : -1 );
		}
		else if(digit=='R'){
			scanf("%d",&a);
			printf("%d\n",a <= N ? findrank(arr[a]) : -1);
		}
		else if(digit=='U'){
			scanf("%d%d",&a,&b);
			if(a<=N && b<=N)
			dounion(arr[a],arr[b]);
		}
	}
	freedf(arr,N);   // Freeing the latest array befor exit
	return 0;
}
