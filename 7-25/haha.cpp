#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
struct Node{
	int num,next,v;
};
struct Que{
	int id,d;
	bool operator < (const Que &s)
	const
	{
		return d>s.d;
	}  
};
struct Que1{
	int d,id,q;
	bool operator < (const Que1 &s)
	const
	{
		return q>s.q;
	}
};

Node edge[100008],edge1[100008];
int b[1008],cnt=0;
int d[1008],head[1008],head1[1008];
void add(int x,int y,int v){
	edge[cnt].v=v;
	edge[cnt].num=y;
	edge[cnt].next=head[x];
		head[x]=cnt;
	edge1[cnt].num=x;	
	edge1[cnt].v=v;
	edge1[cnt].next=head1[y];
	head1[y]=cnt++;
}



void dijstra(int s){
	memset(d,0x1f,sizeof(d));
	d[s]=0;
	int zz;
	memset(b,0,sizeof(b));
	priority_queue<Que> Q;
	Que k;
	k.id=s;
	k.d=0;
	Q.push(k);
	while(!Q.empty()){
		k=Q.top();
		Q.pop();
		b[k.id]=1;
		for(int i=head1[k.id];i!=-1;i=edge1[i].next){
			int n=edge1[i].num;
			if(!b[n])
			if(d[n]==-1||k.d+edge1[i].v<=d[n]){
				d[n]=k.d+edge1[i].v;
				Que l;
				l.id=n;
				l.d=d[n];
				Q.push(l);	
			}
		}
	}
}

int astar(int s,int e,int time){
	priority_queue<Que1> Q;
	Que1 k;
	memset(b,0,sizeof(b));
	k.id=s;
	k.d=0;
	k.q=d[s];
	b[s]=-1;
	Q.push(k);
	int zz;
	while(!Q.empty()){
		k=Q.top();
		Q.pop();
		b[k.id]++;
		if(b[e]==time) return k.d;
		for(int i=head[k.id];i!=-1;i=edge[i].next){
			Que1 p;
			p.id=edge[i].num;
			p.d=k.d+edge[i].v;
			p.q=p.d+d[p.id];
			Q.push(p);
		}
	}
	return -1;	
}

int main(){
	int n,m,x,y,v ;
	memset(head,-1,sizeof(head));
	memset(head1,-1,sizeof(head1));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v);
	}
	scanf("%d%d%d",&x,&y,&v);
	dijstra(y);
	int ans=astar(x,y,v);
	printf("%d",ans);
}
