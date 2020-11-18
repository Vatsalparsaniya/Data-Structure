/*Made by Shivam Solanki*/
#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define ll long long int
#define endl '\n'
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<pii> vp;
typedef vector<pll> vpll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef set<int> sii;
typedef set<ll> sll;
typedef queue<int> qii;
typedef priority_queue<int> pq;
typedef unordered_map<int,int> umii;
typedef unordered_map<ll,ll> umll;
#define all(x) x.begin(),x.end()
#define rep(i,k,n) for (int i = k; i < n; ++i) 
#define repr(i,k,n) for (int i = n; i>=k; --i)
#define repll(i,k,n) for (ll i = k; i < n; ++i) 
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define F first
#define S second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 1e9+5;
const int MOD = 1e9+7;
double pi = 2 * acos(0.0); 
const int N = 1e7+5;

sii primes;

void simpleSieve(int limit,vector<int> &prime){ 
    bool mark[limit+1];
    memset(mark,1,sizeof(mark));
    for(int p=2;p*p<limit;p++)
        if(mark[p]) for(int i=p*2;i<limit;i+=p) mark[i]=0;
    rep(p,2,limit)
        if(mark[p]) primes.insert(p),prime.push_back(p); 
} 

void segmentedSieve(){ 
    int limit=(sqrt(N))+1; 
    vector<int> prime;  
    simpleSieve(limit,prime);   
    int low=limit,high=2*limit; 
    while(low<N){ 
        if(high>=N) high=N; 
        bool mark[limit+1]; 
        memset(mark, true, sizeof(mark)); 
        rep(i,0,prime.size()){ 
            int loLim=(low/prime[i])*prime[i]; 
            if (loLim<low) loLim+=prime[i]; 
            for(int j=loLim;j<high;j+=prime[i]) 
                mark[j-low] = false; 
        } 
        rep(i,low,high)
            if(mark[i-low])  primes.insert(i);
        low+=limit,high+=limit; 
    } 
} 

void solve(){
    //To find maximum prime subarray length
	int n;
	cin>>n;
	int a[n];
	rep(i,0,n) cin>>a[i];
	int ctr=0,ans=0;
	rep(i,0,n){
		if(primes.count(a[i])){
			ctr++;
		}
		else{
			ans=max(ctr,ans);
			ctr=0;
		}
	}
	ans=max(ctr,ans);
	cout<<(ans?ans:-1)<<'\n';
}

int main(){ 
    // #ifndef ONLINE_JUDGE  
        // freopen("input.txt", "r", stdin); 
        // freopen("output.txt", "w", stdout); 
    // #endif 
    fastio;
    segmentedSieve();
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
