#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

struct Node{
	int x,y,z;
	friend bool operator < (Node a,Node b){
		return a.y>b.y;
	}
};
Node a[200700];
int ans[200700];
priority_queue<Node> Q;
bool cmp(Node a,Node b){
	return a.x<b.x;
}
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		int cnt=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[cnt].x,&a[cnt].y,&a[cnt].z);
			if(a[cnt].y-a[cnt].x+1<m) cnt++; 
		}
		n=cnt;
		int myans=-1;
		while(!Q.empty()) Q.pop();
		sort(a,a+n,cmp);
		memset(ans,-1,sizeof(ans));
		for(int i=0;i<n;i++){
			while(!Q.empty()&&Q.top().y<a[i].x){
				Node tmp=Q.top();
				Q.pop();
				int l=tmp.y-tmp.x+1;
				if(ans[l]==-1) ans[l]=tmp.z;
				else
				ans[l]=min(ans[l],tmp.z);
			}
			int l=a[i].y-a[i].x+1;
			if(ans[m-l]!=-1){
				if(myans==-1) myans=ans[m-l]+a[i].z;
				else myans=min(myans,ans[m-l]+a[i].z);
			}
			Q.push(a[i]);
		}
		printf("%d\n",myans);
	}
}
