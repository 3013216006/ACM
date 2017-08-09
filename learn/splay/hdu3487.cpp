#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ls t[x].son[0]
#define rs t[x].son[1]
using namespace std;
struct Node{
	int son[2],size,fl,f,v;
}t[300300];

int rt,cnt;

void print(int x){
	cout << "p=" << x << " ls=" << ls << " rs=" << rs << endl;
	cout << "v=" << t[x].v << " size=" << t[x].size << endl << endl;
	if(ls) print(ls);
	if(rs) print(rs);
}

bool _is(int x){
	return t[t[x].f].son[1]==x;
}
int tp,f,g;

void update(int x){
	t[x].size=t[t[x].son[0]].size+t[t[x].son[1]].size+1;
}

void pushdown(int x){
	t[ls].fl^=1;
	t[rs].fl^=1;
	swap(t[x].son[0],t[x].son[1]);
	t[x].fl=0;
}

void rotate(int x){
	tp=_is(x),f=t[x].f,g=t[f].f;
//	cout << "tp=" << tp << " f=" << f << " g=" << g << endl;
	if(g) t[g].son[_is(f)]=x;t[x].f=g;
	t[f].son[tp]=t[x].son[tp^1];t[t[f].son[tp]].f=f;
	t[x].son[tp^1]=f;t[f].f=x;
	update(f);update(x);
}

void splay(int x,int tar){
//	cout << x << " " << tar << endl;
	for(;t[x].f!=tar;rotate(x))
		if(t[t[x].f].f!=tar) if(_is(t[x].f)==_is(x)) rotate(t[x].f); else rotate(x);
	if(tar==0) rt=x;
}

void nw(int v){
	cnt++;
	t[cnt].son[0]=t[cnt].son[1]=t[cnt].f=0;
	t[cnt].size=1;
	t[cnt].v=v;
	t[cnt].fl=0;
}

int find(int i){
	int x=rt,tmp=0,last;
	while(x){
		last=x;
		if(t[x].fl) pushdown(x);
		if(tmp+t[ls].size+1==i) return x;
		if(tmp+t[ls].size+1<i) tmp+=t[ls].size+1,x=rs;
		else x=ls;
	}
	return last;
}

void add(int i,int v){
	if(rt==0){
		nw(v);
		rt=cnt;
		return;
	}
	if(t[rt].size<=i){
		int x=find(i);
		splay(x,0);
		nw(v);
		t[x].son[1]=cnt;
		t[cnt].f=x;
		t[x].size+=t[cnt].size;
	}
	else{
		cout << "haha" << endl;
	}
}

void cut(int x,int y,int z){
	y=find(y+2);
	x=find(x);
	splay(x,0);
	splay(y,x);
	int tmp=t[y].son[0];
	t[y].son[0]=0;
	update(y);
	update(x);
	int t1=find(z+2);
	int t2=find(z+1);
	splay(t2,0);
	if(t1!=t2){
		splay(t1,t2);
		t[t1].son[0]=tmp;
	}
	else t[t1].son[1]=tmp;
	t[tmp].f=t1;
	update(t1);
	update(t2);
}

void flip(int x,int y){
	x=find(x);
	y=find(y+2);
	splay(x,0);
	splay(y,x);
	t[t[y].son[0]].fl^=1;
}
int ans[300300];
int l;
void myprint(int x){
	if(t[x].fl) pushdown(x);
	if(ls) myprint(ls);
	ans[l++]=t[x].v;
	if(rs) myprint(rs);
}

char s[1000];
int x,y,z;
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		if(n==-1&&m==-1) break;
		cnt=0;
		t[0].size=0;
		t[0].f=0;
		rt=0;
		for(int i=0;i<=n+1;i++){
			add(i,i);
		}
		for(int i=0;i<m;i++){
			scanf("%s",s);
			if(s[0]=='C'){
				scanf("%d%d%d",&x,&y,&z);
				cut(x,y,z);
			//	print(rt);
			}
			else{
				scanf("%d%d",&x,&y);
				flip(x,y);
			}
		}
		l=0;
		myprint(rt);
		for(int i=1;i<n;i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[n]);
	}
}
