#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int x,op;
}a[200010];

int cnt;
bool cmp(Node a,Node b){
	if(a.x==b.x) return a.op<b.op;
	return a.x<b.x;
}

void add(int x,int y){
	a[cnt].x=x;
	a[cnt].op=y;
	cnt++;
}

int main(){
	int T,n,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		cnt=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			add(x,1);
			add(y,-1);
		}
		sort(a,a+cnt,cmp);
		int ans=0,k=0,k1=0;
		long long sum=0;
		for(int i=0;i<cnt;i++){
			ans+=a[i].op;
			if(ans>k) k=ans,sum-=a[i].x;
		}
		ans=0,k1=0;
		for(int i=cnt-1;i>=0;i--){
			ans-=a[i].op;
			if(ans>k1) k1=ans,sum+=a[i].x;
		}
		cout << k << " " << sum << endl;
	}
}
