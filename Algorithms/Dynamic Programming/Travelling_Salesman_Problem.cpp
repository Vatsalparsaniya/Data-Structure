#include <iostream>
using namespace std;

int costMatrix[5][5];
int vistedCities[5];
int numCity = 5;
int cost = 0;

int tsp(int);
void minCost(int);

//Main functions
int main()
{

	int i;
	int j;
	cout << "\n\nEnter distance between cities into matrix...\n";
	for (i = 0; i < numCity; i++)
	{
		cout << "\nEnter " << numCity << " elements in Row[" << i + 1 << "]\n";
		for (j = 0; j < numCity; j++)
			cin >> costMatrix[i][j];
	}
	cout << "\nDistances entered into cost matrix:\n";
	for (i = 0; i < numCity; i++)
	{
		cout << endl;
		for (j = 0; j < numCity; j++)
		{
			cout << costMatrix[i][j] << " ";
		}
	}

	//Display results
	cout << "\n\n Optimum Path: \t ";
	minCost(0);
	cout << "\n Minimum Cost: \t";
	cout << cost;
	return 0;
}

//Function to determine minimum cost
void minCost(int city)
{
	int nearestCity;
	vistedCities[city] = 1;

	cout << city + 1;
	nearestCity = tsp(city);

	if (nearestCity == 999)
	{
		nearestCity = 0;
		cout << nearestCity + 1;
		cost = cost + costMatrix[city][nearestCity];
		return;
	}
	minCost(nearestCity);
}

int tsp(int city1)
{
	int counter;
	int nearestCity = 999;
	int mini = 999;
	int temp;

	for (counter = 0; counter < numCity; counter++)
	{
		if ((costMatrix[city1][counter] != 0) && (vistedCities[counter] == 0))
		{
			if (costMatrix[city1][counter] < mini)
			{
				mini = costMatrix[counter][0] + costMatrix[city1][counter];
			}
			temp = costMatrix[city1][counter];
			nearestCity = counter;
		}
	}
	if (mini != 999)
		cost = cost + temp;

	return nearestCity;
}
