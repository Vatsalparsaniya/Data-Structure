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
const int MAXN = 2e5+9;
double pi = 2 * acos(0.0); 

//problem link https://www.codechef.com/LRNDSA05/problems/BINXOR

int bpow(int x, int n) {
	return n ? n % 2 ? 1LL * x * bpow(x, n - 1) % MOD : bpow(1LL * x * x % MOD, n / 2) : 1;
}
int inv(int x) {
	return bpow(x, MOD - 2);
}
 
int F[MAXN];
int fact(int n) {
	return n ? F[n] ? F[n] : F[n] = 1LL * n * fact(n - 1) % MOD : 1;
}
int rfact(int n) {
	return inv(fact(n));
}
int nCr(int n, int r) {
	return 1LL * fact(n) * rfact(r) % MOD * rfact(n - r) % MOD;
}

void solve(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int a1=0,a2=0;
    rep(i,0,n){
        if(a[i]=='1'){
            a1++;
        }
        if(b[i]=='1'){
            a2++;
        }
    }
	int ans = 0;
	int L = abs(a1 - a2);
	int R = a1 + a2 - 2 * max(0, a1 + a2 - n);
	for(int k = L; k <= R; k += 2) {
		ans = (ans + nCr(n,k)) % MOD;
	}
	cout << ans << endl;
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
