#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int bin_search(int l,int h,int key,vector <int> a,bool searchIndex){
    int mid,result = -1;
    while(l<=h){
        mid = ceil((l+h)/2);
        if(key==a[mid]){
            result = mid;
            if(searchIndex)
                h = mid-1;
            else
                l = mid+1;
        }
        else if(key<a[mid]){
            h=mid-1;
        }
        if(key>a[mid]){
            l=mid+1;
        }
    }
    return result;
}



int main()
{
  vector <int> a;
  int ele,l,n,h,key,res;
  cin>>n;
  cin>>key;

  for (int i=0;i<n;i++){
    cin>>ele;
    a.push_back(ele);
  }
  l = a[0];
    h = a[n-1];

  int firstIndex = bin_search(l,h,key,a,true);
  if(firstIndex==-1){
    cout<<0<<endl;
  }else{
    int lastIndex = bin_search(l,h,key,a,false);
    cout<<firstIndex<<" "<<lastIndex<<endl;
  }
  return 0;
}