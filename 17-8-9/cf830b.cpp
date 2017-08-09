#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int t[100100];
int n;
int t1[100100];
struct Node{
	int x,y;
}a[100100];

int lowbit(int x){
	return x&(-x);
}

void add(int x,int v){
	while(x<=n){
		t[x]=max(t[x],v);
		x+=lowbit(x);
	}
}

int query(int x){
	int ret=0;
	while(x){
		ret=max(ret,t[x]);
		x-=lowbit(x);
	}
	return ret;
}

void add1(int x,int v){
	while(x<=n){
		t1[x]=max(t1[x],v);
		x+=lowbit(x);
	}
}

int query1(int x){
	int ret=0;
	while(x){
		ret=max(ret,t1[x]);
		x-=lowbit(x);
	}
	return ret;
}

bool cmp(Node a,Node b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
int b[100100];
int main(){
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i].x);
			a[i].y=i;
		}
		long long ans=0;
		sort(a,a+n,cmp);
		memset(t,0,sizeof(t));
		memset(t1,0,sizeof(t1));
		for(int i=0;i<n;i++){
			int l=i;
			while(i+1<n&&a[i+1].x==a[i].x) i++;
			for(int j=l;j<=i;j++){
				b[j]=max(query(a[j].y),query1(n-a[j].y)+1);
			}
			for(int j=l;j<=i;j++){
				add(a[j].y+1,b[j]);
				add1(n-a[j].y,b[j]);
				ans+=b[j];
			}
		}
		cout << ans << endl;
	}
}
