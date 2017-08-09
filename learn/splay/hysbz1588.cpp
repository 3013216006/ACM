#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Node{
	int f,son[2],v;
}t[100000];
int cnt,rt,x;

void print(int x){
	
	if(t[x].son[0]) print(t[x].son[0]);
	cout << x << ": " << t[x].v << " f=" << t[x].f << " ls=" << t[x].son[0] << " rs=" << t[x].son[1] << endl;
	if(t[x].son[1]) print(t[x].son[1]);
}

int _is(int x){
	return t[t[x].f].son[1]==x;
}


void rotate(int x){
	int f=t[x].f,g=t[f].f,i=_is(x);
	if(g) t[g].son[_is(f)]=x;t[x].f=g;
	t[f].son[i]=t[x].son[i^1];t[t[f].son[i]].f=f;
	t[x].son[i^1]=f;t[f].f=x;
}

void splay(int x,int tar){
	for(;t[x].f!=tar;rotate(x)){
		if(t[t[x].f].f!=tar) if(_is(t[x].f)==_is(x)) rotate(t[x].f); else rotate(x);
	}
	if(tar==0) rt=x;
}

int findmax(int x){
	int now=rt,ret=0;
	while(now){
		if(x>t[now].v) now=t[now].son[1];
		else if(x<t[now].v) ret=now,now=t[now].son[0];
		else return now;
	}
	return ret;
}

int findmin(int x){
	int nw=rt,ret=0;
	while(nw){
		if(x>t[nw].v) ret=nw,nw=t[nw].son[1];
		else if(x<t[nw].v) nw=t[nw].son[0];
		else return nw;
	}
	return ret;
}

void newnode(int v){
	cnt++;
	t[cnt].son[0]=t[cnt].son[1]=t[cnt].f=0;
	t[cnt].v=v;
}

int insert(int x){
	if(rt==0){
		cnt=0;
		newnode(x);
		rt=cnt;
		return x;
	}
//	cout << x << "!:" ;
	int minx=findmin(x),maxx=findmax(x);
	//cout << minx << " " << maxx << " " << t[minx].v << " " << t[maxx].v << endl;
	if(minx==maxx){
		return 0;
	}
	else{
		if(minx==0){
			splay(maxx,0);
			newnode(x);
			t[maxx].son[0]=cnt;
			t[cnt].f=maxx;
			return t[maxx].v-x;
		}
		else if(maxx==0){
			splay(minx,0);
			newnode(x);
			t[minx].son[1]=cnt;
			t[cnt].f=minx;
			return x-t[minx].v;
		}
		else{
			splay(minx,0);
			//print(rt);
			splay(maxx,minx);
			//print(rt);
			newnode(x);
			t[maxx].son[0]=cnt;
			t[cnt].f=maxx;
			return min(x-t[minx].v,t[maxx].v-x);
		}
	}
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		int ans=0;
		rt=0;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			ans+=insert(x);
			//print(rt);
			//cout << ans << endl;
		}
		cout << ans << endl;
	}
}
