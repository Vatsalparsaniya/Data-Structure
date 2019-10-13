
#include<bits/stdc++.h>
#define append push_back
#define endl "\n"
#define N 1000000
#define M 1000000007
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define cover(arr,val) memset(arr,val,sizeof(arr)) 
using namespace std;
/*
 *
 *This exponentiation is based on the binary representaion of the number
 *
 *
 * */


ll expo(ll x,ll y)
{
	ll z = 1;
	while(y>0)
	{
		if(y%2==1)
			z = z*x;
		x = x*x;
		y = y>>1;
	}
	return z;
}
int main()
{
	ll x,y;
	cout << "enter two numbers ";
	cin >> x >> y;
	cout << x<< " power " <<y <<" is "<<expo(x,y) << endl;
	return 0;
}

