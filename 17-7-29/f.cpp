#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long t[10010];
int lowbit(int x){
	return x&(-x);
}
long long query(int l){
	long long ret=0;
	while(l){
		ret=max(ret,t[l]);
		l-=lowbit(l);
	}
	return ret;
}

void change(int x,long long v){
	while(x<=10000){
		t[x]=max(t[x],v);
		x+=lowbit(x);
	}
}
int a[100010],b[100010];
long long tmp[100010];
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		long long ans=0;
		for(int i=0;i<n;i++){
			if(a[i]==10000){
				int l=0;
				for(int j=i+1;j<n;j++)
					b[l++]=a[j];
				for(int j=0;j<i;j++)
					b[l++]=a[j];
				memset(t,0,sizeof(t));
				for(int i=0;i<l;i++){
					//cout << i << endl;
					if(b[i]==10000){
					tmp[i]=0;
					continue;
					}
					int x=query(10000-b[i]);
					//cout << "yes" << endl;
					x+=b[i];
					tmp[i]=x;
					//cout << "yes1" << endl;
					change(10000-b[i],x);
				}
				memset(t,0,sizeof(t));
				for(int i=l-1;i>=0;i--){
					if(b[i]==10000) continue;
					int x=query(10000-b[i]);
					//cout << "yes" << endl;
					tmp[i]+=x;
					x+=b[i];
					change(10000-b[i],x);
					//cout << "yes1" << endl;
				}
				for(int i=0;i<l;i++){
					ans=max(ans,tmp[i]);
				}
			}
		}
		cout << ans+10000 << endl;
	}
}
