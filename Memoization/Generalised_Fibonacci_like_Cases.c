#include <stdio.h>

long long int arr[100005], i;

long long int f(long long int x,long long int k){

	
	
	if(arr[x]==-1){
		arr[x]=((f(x-1,k))%1000000007+(f(x-k,k))%1000000007)%1000000007;
		return arr[x];

	}

	else{

		return arr[x];
	}


}

int main(){

	int T;
	scanf("%d", &T);

	while(T--){
	
		for(i=0; i<100005;i++){
			arr[i]=-1;
		}
		
	
		long long int N, K;
		scanf("%lld%lld",&N,&K);

		for(i=1; i<K; i++){
			arr[i]=1;
		arr[K]=2;arr[0]=1;
		}

		long long int ans = (f(N,K))%1000000007;
		printf("%lld\n", ans);

	}
	


	return 0;
}
