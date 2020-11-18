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
const int N = 1e6+5;

sii primes;

void sieve(){  
    bool prime[N+1]; 
    memset(prime,true,sizeof(prime)); 
    for(int p=2;p*p<=N;p++){  
        if(prime[p]==true){ 
            for(int i=p*p;i<=N;i+=p) 
                prime[i]=false; 
        } 
    } 
    rep(p,2,N+1) 
       if(prime[p]) 
            primes.insert(p);
} 

void solve(){
    sieve();
    sii truncable;
    ll sum=0;
    for(int i:primes){
        if(i!=2 and i!=3 and i!=5 and i!=7){
            string check=to_string(i);
            int n=check.size();
            bool flag=1;
            rep(j,1,n){
                int num=stoi(check.substr(j,n));
                // cout<<num<<'\n';
                if(primes.count(num)==0){
                    flag=0;
                    break;
                }
            }
            repr(j,1,n-1){
                int num=stoi(check.substr(0,j));
                // cout<<num<<'\n';
                if(primes.count(num)==0){
                    flag=0;
                    break;
                }
            }
            if(flag){
                // cout<<i<<'\n';
                sum+=i;
            }
        }
    }
    cout<<sum<<'\n';
}
int main(){ 
    // #ifndef ONLINE_JUDGE  
        // freopen("input.txt", "r", stdin); 
        // freopen("output.txt", "w", stdout); 
    // #endif 
    fastio;
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
