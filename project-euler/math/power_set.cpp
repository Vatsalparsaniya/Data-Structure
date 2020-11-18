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

void solve(){
   int h,w,K;
   cin>>h>>w>>K;
   vector<string>a(h);
   rep(i,0,h) cin>>a[i];
   int ans=0,ctr=0;
   string s="";
   rep(i,0,h){
      s+=to_string(i);
   }
   set<string>s1,s2;
   rep(i,0,pow(2,s.size())){
      string x="";
      rep(j,0,s.size()){
         if(i&(1<<j)) x+=s[j];
      }
      //cout<<x<<endl;
      s1.insert(x);
   }
   s="";
   rep(i,0,w){
      s+=to_string(i);
   }
   rep(i,0,pow(2,s.size())){
      string x="";
      rep(j,0,s.size()){
         if(i&(1<<j)) x+=s[j];
      }
      //cout<<x<<endl;
      s2.insert(x);
   }
   for(string check1:s1){
      for(string check2:s2){      
         int ctr=0;
         rep(i,0,h){
            rep(j,0,w){
               string c1=to_string(i),c2=to_string(j);
               bool f1=1,f2=1;
               //cout<<c<<'\n';
               for(char cx:check1){
                  if(c1[0]==cx){
                     f1=0;
                     break;
                  }
               }
               for(char cx:check2){
                  if(c2[0]==cx){
                     f2=0;
                     break;
                  }
               }
               if(f1 and f2 and a[i][j]=='#') ctr++;
            }
         }
         //cout<<check<<' '<<ctr<<'\n';
         if(ctr==K) ans++;
      }
   }
   cout<<ans;
}

int main(){ 
    // #ifndef ONLINE_JUDGE  
        // freopen("input.txt", "r", stdin); 
        // freopen("output.txt", "w", stdout); 
    // #endif 
   //  fastio;
    int t=1;
   //  cin>>t;
    while(t--)
        solve();
    return 0;
}
