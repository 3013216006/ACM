#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <string.h>
#include <utility>
using namespace std;
map<pair<int,int>,int> M;
struct Node{
	int x,y;
}a[10001];
bool cmp(Node a,Node b){
	if(a.x==b.x) return a.y<b.y;
	else return a.x<b.x;
}
int r[10001],c[10001],c1[10001],r1[10001];
int main(){
	int n,m,k;
	while(~scanf("%d%d%d",&n,&m,&k)){
		M.clear();
		for(int i=0;i<k;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
			M[make_pair(a[i].x,a[i].y)]=1;
		}
		sort(a,a+k,cmp);
		memset(r,-1,sizeof(r));
		memset(c,-1,sizeof(c));
		memset(r1,-1,sizeof(r1));
		memset(c1,-1,sizeof(c1));
		r[1]=0;
		c[1]=0;
		r1[1]=0;
		c1[1]=0;
		for(int i=1;i<k;i++){
			int x=-1,y=-1;
//			cout << r[a[i].x] << " " << c[a[i].y] << endl;
			if(r[a[i].x]!=-1){
				if(M.count(make_pair(a[i].x,a[i].y-1))>0){
					x=min(r1[a[i].x],r[a[i].x]+1);
				}
				else x=r[a[i].x]+1;
			}
			if(c[a[i].y]!=-1){
				if(M.count(make_pair(a[i].x-1,a[i].y))>0){
					y=min(c1[a[i].y],c[a[i].y]+1);
				}
				else y=c[a[i].y]+1;
			}
//			cout << i << ": x="  << x << " y=" << y << endl;  
			int tmp=x;
			if(x==-1&&y!=-1) tmp=y;
			if(y!=-1) tmp=min(tmp,y);
//			cout << i<< ":" << "x=" << a[i].x << " y=" << a[i].y << " ans=" << tmp << endl;
			r1[a[i].x]=tmp;
			c1[a[i].y]=tmp;
			if(tmp==-1) continue;
//			cout << i << " : yes " << endl;  
			if(r[a[i].x]!=-1)
			r[a[i].x]=min(r[a[i].x],tmp);
			else r[a[i].x]=tmp;
			if(c[a[i].y]==-1) c[a[i].y]=tmp;
			c[a[i].y]=min(c[a[i].y],tmp);
		}
//		for(int i=1;i<=n;i++) cout << i << ": "  << r[i] << endl;
//		for(int i=1;i<=m;i++) cout << i << ": "  << c[i] << endl;
		if(M.count(make_pair(n,m))>0) cout << min(r[n],c[m]) << endl;
		else{
			int x=-1,y=-1;	
			if(r[n]!=-1) x=r[n]+1;
			if(c[m]!=-1) y=c[m]+1;
			int ans=-1;
			if(x==-1) ans=y;
			else if(y==-1) ans=x;
			else ans=min(x,y);
			cout << ans << endl;
		}
	}
}
