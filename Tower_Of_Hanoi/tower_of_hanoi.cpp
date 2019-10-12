#include <cstdio>
using namespace std;

//n = no. of pegs
//src, aux, dest defines name of towers
//returns : number of moves
int tower_of_hanoi(int n, char src, char aux, char dest, bool print_move = false) {
	if(n < 1) return 0;
	if(n == 1) {
		if(print_move) printf("Moved disk 1 from %c to %c\n",src,dest);
		return 1;
	}
	int count = 0;
	count += tower_of_hanoi(n-1,src,dest,aux,print_move);
	if(print_move) printf("Moved disk %d from %c to %c\n",n,src,dest);
	count += tower_of_hanoi(n-1,aux,src,dest,print_move);
	return count+1;
};

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d",&n);
    printf("No of moves = %d\n", tower_of_hanoi(n,'A','B','C'));
}
