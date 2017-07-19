#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int n,mm;
int vis[11][11],m[11][11];
struct Node{
	int x,y,t;
	Node(){}
	Node(int _x,int _y,int _t){
		x=_x,y=_y,t=_t;
	}
};
queue<Node> Q;
int find(int x,int y,int t){
//	cout << x << " " << y << endl;
	vis[x][y]=t;
	int ret=0;
	if(x+1<n){
		if(m[x+1][y]&&vis[x+1][y]!=t) ret=max(ret,find(x+1,y,t)+1);
	}
	if(y+1<mm){
		if(m[x][y+1]&&vis[x][y+1]!=t) ret=max(ret,find(x,y+1,t)+1);
	}
	if(x-1>=0){
		if(m[x-1][y]&&vis[x-1][y]!=t) ret=max(ret,find(x-1,y,t)+1);
	}
	if(y-1>=0){
		if(m[x][y-1]&&vis[x][y-1]!=t) ret=max(ret,find(x,y-1,t)+1);
	}
	return ret;
}

int getsum(int x,int y,int k){
	while(!Q.empty()){
		Q.pop();
	}
	Q.push(Node(x,y,0));
	int ret=0;
	vis[x][y]=k;
	
	while(!Q.empty()){
		Node tmp=Q.front();
		Q.pop();
		x=tmp.x;
		y=tmp.y;
//		cout << "haha"  << x << " " << y << endl;
		ret=tmp.t;
		int t=tmp.t+1;
		if(x+1<n){				
			if(m[x+1][y]&&vis[x+1][y]!=k){
				Q.push(Node(x+1,y,t));
				vis[x+1][y]=k;
			}
		}
		if(y+1<mm){
			if(m[x][y+1]&&vis[x][y+1]!=k){
				Q.push(Node(x,y+1,t));
				vis[x][y+1]=k;
			}
		}
		if(x-1>=0){
			if(m[x-1][y]&&vis[x-1][y]!=k){
				Q.push(Node(x-1,y,t));
				vis[x-1][y]=k;
			}
		}
		if(y-1>=0){
			if(m[x][y-1]&&vis[x][y-1]!=k){
				Q.push(Node(x,y-1,t));
				vis[x][y-1]=k;
			}
		}
	}
	return ret;
}

int myget(int x,int y,int s,int t,int k){
	int ret=0;
	while(!Q.empty()) Q.pop();
	Q.push(Node(x,y,0));
	Q.push(Node(s,t,0));
	vis[x][y]=k;
	vis[s][t]=k;
	while(!Q.empty()){
		Node tmp=Q.front();
		Q.pop();
		x=tmp.x;
		y=tmp.y;
//		cout << x << " " << y << endl;
		ret=tmp.t;
		t=tmp.t+1;
		if(x+1<n){				
			if(m[x+1][y]&&vis[x+1][y]!=k){
				Q.push(Node(x+1,y,t));
				vis[x+1][y]=k;
			}
		}
		if(y+1<mm){
			if(m[x][y+1]&&vis[x][y+1]!=k){
				Q.push(Node(x,y+1,t));
				vis[x][y+1]=k;
			}
		}
		if(x-1>=0){
			if(m[x-1][y]&&vis[x-1][y]!=k){
				Q.push(Node(x-1,y,t));
				vis[x-1][y]=k;
			}
		}
		if(y-1>=0){
			if(m[x][y-1]&&vis[x][y-1]!=k){
				Q.push(Node(x,y-1,t));
				vis[x][y-1]=k;
			}
		}
	}
	return ret;
}

vector<pair<int,int> > v,p;
int getans(){
	int ret=100,r=0;
	int tt=5;
	int l=v.size();
//	cout << l << endl;
	for(int i=0;i<l;i++){
		r=max(r,getsum(v[i].first,v[i].second,tt++));
	}
	ret=r;
//	cout << ret << endl;
	for(int i=0;i<l;i++)
		for(int j=i+1;j<l;j++){
			//cout << i << " " << j << endl;
			ret=min(ret,myget(v[i].first,v[i].second,v[j].first,v[j].second,++tt));
//			if(ret==(r+1)/2) return ret;
		}
		return ret;
}
char s[15];
int main(){
	int T;
	int cas=1;
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&mm);
		int ans=0;
		for(int i=0;i<n;i++){
			scanf("%s",s);
			for(int j=0;j<mm;j++)
				if(s[j]=='#') m[i][j]=1;
				else m[i][j]=0;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<mm;j++)
				if(vis[i][j]==0&&m[i][j]) find(i,j,++ans);
		//cout << "ans=" << ans << endl;
		if(ans>2){
			printf("Case %d: -1\n",cas++);
		}
		else if(ans==2){
			int ret1=100,ret2=100;
			v.clear();
			p.clear();
			for(int i=0;i<n;i++)
				for(int j=0;j<mm;j++)
					if(vis[i][j]==1) v.push_back(make_pair(i,j));
					else if(vis[i][j]==2) p.push_back(make_pair(i,j));
			for(int i=0;i<v.size();i++){
	//			cout << v[i].first << " " << v[i].second << endl;
				ret1=min(ret1,getsum(v[i].first,v[i].second,++ans));
			}
			for(int i=0;i<p.size();i++){
//				cout << p[i].first << " " << p[i].second << endl;
				ret2=min(ret2,getsum(p[i].first,p[i].second,++ans));
			}
//			cout << ret1 << " " << ret2 << endl;
			printf("Case %d: %d\n",cas++,max(ret1,ret2));
		}
		else{
			v.clear();
			for(int i=0;i<n;i++){
				for(int j=0;j<mm;j++)
				if(vis[i][j]){
					v.push_back(make_pair(i,j));
				}
			}
			int ret=getans();
			printf("Case %d: %d\n",cas++,ret);
		}
	}
}
