#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
long long mod=100000007ll;

long long getpow(long long x,int k){
	long long ret=1;
	while(k){
		if(k&1) ret=ret*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ret;
}

map<pair<int,int>,int> M;

int main(){
	int n,m,k;
	int x,y,l;
	while(~scanf("%d%d%d",&n,&m,&k)){
		int ans=0;
		M.clear();
		if(n&1) l=(n+1);
		else l=n;
		l/=2;
		ans=l*(l+1)/2;
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			x++,y++;
			if(x>l) x=n-x+1;
			if(y>l) y=n-y+1;
			if(x>y) swap(x,y);
			if(M.count(make_pair(x,y))>0);
			else M[make_pair(x,y)]=1,ans--;
		}
		cout << getpow(k,ans) << endl;
	}
}
