/*Made by Shivam Solanki*/
#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
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

//Problem code: https://codeforces.com/gym/102644/problem/A

struct Matrix{
    double a[2][2]={{0,0},{0,0}};
    Matrix operator *(const Matrix& other){
        Matrix product;
        rep(i,0,2) rep(j,0,2) rep(k,0,2){
            product.a[i][k]+=a[i][j]*other.a[j][k];
        }
        return product;
    }
};

Matrix mat_expo(Matrix a,int k){
    Matrix product;
    rep(i,0,2) product.a[i][i]=1;
    while(k>0){
        if(k%2) product=product*a;
        a=a*a;
        k/=2;
    }
    return product;
}

void solve(){
    int n;
    double p;
    cin>>n>>p;
    Matrix s;
    s.a[0][0]=1-p;
    s.a[0][1]=p;
    s.a[1][0]=p;
    s.a[1][1]=1-p;
    Matrix ans=mat_expo(s,n);
    cout<<fixed<<setprecision(10)<<ans.a[0][0]<<'\n';
}

int main(){ 
    // #ifndef ONLINE_JUDGE  
        // freopen("input.txt", "r", stdin); 
        // freopen("output.txt", "w", stdout); 
    // #endif 
    fastio;
    int t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}
