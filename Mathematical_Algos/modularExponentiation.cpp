/*---- enazuma11-------  */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define M 1000000007
// The exp function calucates (a^b)%M value for larger inputs of a,b and M should be a larhe prime number
ll exp(ll x,ll n,ll m)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return exp((x*x)%m,n/2,m);
    else                             //n is odd
        return (x*exp((x*x)%m,(n-1)/2,m))%m;

}
int main() {
	
	ll a=167;
	ll b=89;

	ll ans=exp(a,b,M);
	cout<<ans<<'\n';
	
	return 0;
}