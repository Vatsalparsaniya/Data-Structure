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
//const ll inf = 2e18+11;
//Question Link
//https://www.codechef.com/LRNDSA04/problems/QHOUSE

void solve(){
    //comment before submitting
    vp square(4),triangle(3);
    rep(i,0,4) cin>>square[i].F>>square[i].S;
    rep(i,0,3) cin>>triangle[i].F>>triangle[i].S;
    int actual_ans;
    cin>>actual_ans;
    auto valid_ans=[](pii p,vp square,vp triangle){
        int s=square[0].F;
        if(p.F>=-s and p.F<=s and p.S>=0 and p.S<=s) return 1; //within square 
        int x1=triangle[0].F,x2=triangle[2].F,y1=triangle[0].S,y2=triangle[2].S;
        int y=p.S,x=p.F;
        int ans1=((y-y1)*(x1-x2))-((y1-y2)*(x-x1));
        x1=triangle[1].F,y1=triangle[1].S;
        int ans2=((y-y1)*(x1-x2))-((y1-y2)*(x-x1));
        x1=triangle[0].F,y1=triangle[0].S;
        x2=triangle[1].F,y2=triangle[1].S;
        int ans3=((y-y1)*(x1-x2))-((y1-y2)*(x-x1));
        if(ans1>=0 and ans2<=0 and ans3<=0) return 1; //within triangle
        return 0;
    };
    //till here
    for(;;){
        int l=0,r=1000;
        while(l<=r){
            int m=(l+r)/2;
            cout<<"? "<<m<<' '<<0<<'\n';
            //uncomment while submitting solution
            // string x;
            // cin>>x;
            // if(x=="YES"){
            //     l=m+1;
            // }
            if(valid_ans({m,0},square,triangle)){ //comment while submitting solution
                cout<<"YES\n";
                l=m+1;
            }
            else{
                // cout<<"NO\n";
                r=m-1;
            }
        }
        int a=2*(l-1);
        l=0,r=1000;
        while(l<=r){
            int m=(l+r)/2;
            cout<<"? "<<m<<' '<<a<<'\n';
            // string x;
            // cin>>x;
            // if(x=="YES"){
            //     l=m+1;
            // }
            if(valid_ans({m,a},square,triangle)){
                cout<<"YES\n";
                l=m+1;
            }
            else{
                // cout<<"NO\n";
                r=m-1;
            }
        }
        int b=2*(l-1);
        l=0,r=1000;
        while(l<=r){
            int m=(l+r)/2;
            cout<<"? "<<0<<' '<<m<<'\n';
            // string x;
            // cin>>x;
            // if(x=="YES"){
            //     l=m+1;
            // }
            if(valid_ans({0,m},square,triangle)){
                cout<<"YES\n";
                l=m+1;
            }
            else{
                // cout<<"NO\n";
                r=m-1;
            }
        }
        int h=(l-1)-a;
        int ans=(h*b)/2+(a*a);
        cout<<"! "<<ans;
        if(ans==actual_ans)
            break;
    }
}
 
int main(){ 
    // #ifndef ONLINE_JUDGE  
        // freopen("input.txt", "r", stdin); 
        // freopen("output.txt", "w", stdout); 
    // #endif 
    // fastio;
    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}