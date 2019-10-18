#include <iostream>
using namespace std;
 
bool reachDestination(int maze[][10], int solution[][10], int i, int j, int n){
	//Base Case
	//reached the destination
	if(i == n-1 && j == n-1){
		solution[i][j] = 1;
		for(int x = 0; x < n; x++){
			for(int y = 0; y < n; y++){
				cout<<solution[x][y]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		solution[i][j] = 0;
		return false;
	}
	//Recursive Case
	while(i < n && j < n){
		if(maze[i+1][j] == 1){
			solution[i][j] = 1;
			bool possibleToReachDestination = reachDestination(maze, solution, i+1, j, n);
			if(possibleToReachDestination){
				return true;
			}
			solution[i][j] = 0;
		}
		if(maze[i][j+1] == 1){
			solution[i][j] = 1;
			bool possibleToReachDestination = reachDestination(maze, solution, i, j+1, n);
			if(possibleToReachDestination){
				return true;
			}
			solution[i][j] = 0;  
		}
		break;
	}
	return false;
}
 
int main(){
	int n;
	cin>>n;
	int maze[10][10] = {0};
	int solution[10][10] = {0};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>maze[i][j];
		}
	}
	reachDestination(maze, solution, 0, 0, n);
	return 0;
}

