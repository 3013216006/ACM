#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int num,next;
}edge[1000100];

int head[100010],in[100010],in1[100010],a[100010],cnt;

void add(int x,int y){
	edge[cnt].next=head[x];
	edge[cnt].num=y;
	head[x]=cnt++;
	edge[cnt].next=head[y];
	edge[cnt].num=x;
	head[y]=cnt++;
}
int num,sumans,sum;
int pan(int x){
	sumans=max(sumans,sum^a[x]);
	in[x]=0;
	num--;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].num;
		if(in[v]!=0){
			pan(v);
		}
	}
	if(num==0) return 1;
	return 0;
}
int x,y,n,m;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sum=0;
		int haha=a[1];
		for(int i=2;i<=n;i++)
			haha=max(haha,a[i]);
		cnt=0;
		memset(head,-1,sizeof(head));
		memset(in,0,sizeof(in));
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y); 
			add(x,y);
			in[x]++;
			in[y]++;
		}
		int tmp=0,tmp1=-1,tmp2=0,tmp3=1;
		for(int i=1;i<=n;i++){
			if(in[i]%2==1) tmp++,tmp1=i,sum^=a[i];
			if(in[i]==0){
				tmp2++;
			}
			else tmp3=i;
			if(((in[i])/2)%2==1) sum^=a[i];
		}
		sumans=sum^a[tmp3];
		num=n-tmp2;
		if((tmp==2||tmp==0)){
			if(tmp==0) {
				if(pan(tmp3)) printf("%d\n",sumans);
					else puts("Impossible");
				}
				else if(pan(tmp1)) printf("%d\n",sum);
					else puts("Impossible");
		}
		else{
			puts("Impossible");
		}
	}
}
