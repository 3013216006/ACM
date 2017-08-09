#include <iostream>
#include <stdio.h>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;
bitset<50010> a,b,d,e,tmp;

int getans(int l){
	return d.count()%2;
	//cout << d << endl;
	int r;
	while(l){
	//	cout << l << endl;

		r=(l+1)/2;
		l-=r;
		e=d>>l;
		d^=e;
	}
	if(d[0]==0) return 0;
	else return 1;
}
vector<int> v;
struct Node{
	int x,y;
}c[50020];
int ans[50020];
bool cmp(Node a,Node b){
	return a.x<b.x;
}

int main(){
	int T,x,y,z;
	int k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&x,&y,&z);
		a.reset();
		int mx=0;
		for(int i=0;i<x;i++){
				scanf("%d",&k);
				a[k]=a[k]^1;
		}
		for(int i=0;i<50010;i++)
			if(a[i]) mx=i;
		tmp.reset();
		for(int i=0;i<=mx;i++)
			tmp[i]=1;
		b.reset();
		for(int i=0;i<y;i++){
			scanf("%d",&k);
			b[k]=b[k]^1;
		}
		v.clear();
		for(int i=0;i<50010;i++){
			if(b[i]==1) v.push_back(i);
		}
		b.reset();
		for(int i=0;i<v.size();i++){
			int k=v[i];
			for(int j=0;j<=mx;j+=k)
				b[j]=b[j]^1;
		}
		for(int i=0;i<z;i++){
			scanf("%d",&c[i].x);
			c[i].y=i;
		}
		d=a&b;
		int now=0,ansn=getans(mx),l=0;
		sort(c,c+z,cmp);
		for(int i=0;i<z;i++){
			if(c[i].x==now){
				ans[c[i].y]=ansn;
			}
			else{
				while(c[i].x>=v[l]){
					for(int j=now;j<=mx;j+=v[l])
						b[j]=b[j]^1;
					l++;
				}
				b<<=(c[i].x-now);
				b=b&tmp;
				now=c[i].x;
				d=a&b;
				ansn=getans(mx);
				ans[c[i].y]=ansn;
			}
		}
		for(int i=0;i<z;i++){
			printf("%d\n",ans[i]);
		}
	}
}
