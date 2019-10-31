#include<bits/stdc++.h>

using namespace std;

int main(){
int n;
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++) scanf("%d",&arr[i]);
int key,j;

for(int i=1;i<n;i++){
    key=arr[i];
    for(j=i-1;j>=0 && key<arr[j];j--){
     arr[j+1]=arr[j];
    }
    arr[j+1]=key;
}

for(int i=0;i<n;i++) printf("\n%d",arr[i]);

}
