#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
deque<int> Q;
int a[100010],now[100010],_next[100010];
int t[100110];
int b[100100];

int lowbit(int x){
	return x&(-x);
}

int up;
void add(int x,int y){
	while(x<=up){
		t[x]+=y;
		x+=lowbit(x);
	}
}

int query(int x){
	int ret=0;
	while(x){
		ret+=t[x];
		x-=lowbit(x);
	}
	return ret;
}

int main(){
	int T;
	scanf("%d",&T);
	int n;
	while(T--){
		scanf("%d",&n);
		now[1]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			now[i+1]=max(now[i],a[i]);
			b[i]=a[i];
		}
		memset(_next,0,sizeof(_next));
		memset(t,0,sizeof(t));
		while(!Q.empty()) Q.pop_back();
		a[n+1]=now[n+1]+1;
		b[n+1]=a[n+1];
		sort(b+1,b+2+n);
		int l=unique(b+1,b+2+n)-b-1;
		_next[n+1]=0;
		up=l+10;
		add(1,n+1);
		for(int i=n;i>1;i--){
			int nw=_next[n+1];
			while(nw&&nw%i==0) nw=_next[nw];
			if(nw) now[i]=max(now[i],a[nw]);
			
			int x=lower_bound(b+1,b+1+l,a[i])-b;
			x=l+1-x;
			int tp=query(x);
			_next[i]=_next[tp];
			_next[tp]=i;
			add(x,i-tp);
			if(_next[i]){
				int y=a[_next[i]];
				y=lower_bound(b+1,b+1+l,y)-b;
				y=l+1-y;
				add(y,tp-i);
			}
		}
		for(int i=2;i<n;i++)
			printf("%d ",now[i]);
		printf("%d\n",now[n]);
	}
}
