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

void solve(){
    vvi data;
    int n;
    cin>>n;
    rep(i,0,n){
        vector<int>a(i+1);
        rep(j,0,i+1){
            cin>>a[j];
        }
        data.pb(a);
    }
    // rep(i,0,n){
    //     rep(j,0,data[i].size()){
    //         cout<<data[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    vi dp(n,0);
    dp[0]=data[0][0];
    rep(i,1,n){
        vi new_dp=dp;
        rep(j,0,data[i].size()){
            dp[j]=(j>=1?max(new_dp[j-1],new_dp[j]):new_dp[j])+data[i][j];
        }
    }
    int ans=0;
    rep(i,0,n){
        ans=max(dp[i],ans);
    }
    cout<<ans;
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
