// C++ program for explaning Sieve of Eratosthenes 
#include<bits/stdc++.h> 
using namespace std; 


//the function to generate all primes smaller than or equal to a number
void SieveOfEratosthenes(int n) 
{ 

	bool prime[n+1]; 
	memset(prime, true, sizeof(prime)); 

	for(int p=2; p*p<=n; p++) 
	{ 
		if(prime[p]==true) 
		{
			for(int i=p*2;i<=n;i+=p) 
				prime[i]=false; 
		} 
	}
	for(int p=2;p<=n;p++) 
	if(prime[p])
		cout<<p<<" "; 
} 

//main program
int main() 
{ 
	int n = 42; 
	cout << "The prime numbers which are smaller than or equal to " << n << endl; 
	SieveOfEratosthenes(n); 
	return 0; 
} 

