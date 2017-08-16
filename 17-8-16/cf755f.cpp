#include <iostream>
#include <stdio.h>
#include <bitset>
#include <string.h>
#include <vector>
using namespace std;
bitset<1000100> S;
int a[1000100],b[1000100],vis[1001000];
vector<int> v;

int main(){
	int n,k;
	while(~scanf("%d%d",&n,&k)){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(vis,0,sizeof(vis));
		memset(b,0,sizeof(b));
		int sum1=0,sum2=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			int l=0,r=i;
			while(!vis[r]) vis[r]=1,r=a[r],l++;
			b[l]++;
			sum1+=l/2;
			sum2+=l%2;
		}
		v.clear();
		for(int i=1;i<=n;i++){
			if(b[i]){
				int l=1;
				while(b[i]>=l) v.push_back(i*l),b[i]-=l,l<<=1;
				if(b[i]) v.push_back(i*b[i]);
			}
		}
		S.reset();
		S[n]=1;
		for(int i=0;i<v.size();i++){
			S|=(S>>v[i]);
		}
		int mi,mx;
		if(S[n-k]==1) mi=k;
		else mi=k+1;
		if(k>=sum1) mx=sum1+k;
			else mx=k*2;
		cout << mi << " " << min(mx,n) << endl;
	}
}
