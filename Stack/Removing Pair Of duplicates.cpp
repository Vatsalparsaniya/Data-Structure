
/* You are given a string str. You need to remove the pair of duplicates.Input:
2
aaabbaaccd
aaaa
Output:
ad
Empty String*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        
        string ans = removePair (s);
        
        if(ans=="")
            cout<<"Empty String"<<endl;
        else
            cout<<ans<<endl;
    }
    
	return 0;
}


string removePair(string s){
    
   int n = s.size();
   string s1 = "";
   s1.push_back(s[0]);
   for(int i=1,j=0;i<n;i++){
       if(s1[j] == s[i]){
           s1.pop_back();
            j--;
           
       }else{
           s1.push_back(s[i]);
            j++;
           
       }
   }
   
    return s1;
}
