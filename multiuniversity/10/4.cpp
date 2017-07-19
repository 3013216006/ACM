#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;


int ans[1000010];
struct qu{
	int x,id;
}a[1000010];
bool cmp(qu a,qu b){
	return a.x<b.x;
}
int t[30000010*4];
void build(int l,int r,int rt){
	if(l==r){
		t[rt]=1;
		return;
	}
	int ls=rt<<1,rs=ls|1,mid=l+r>>1;
	build(l,mid,ls);
	build(mid+1,r,rs);
	t[rt]=t[ls]+t[rs];
}

int kill(int x,int l,int r,int rt){
	int ls=rt<<1,rs=ls|1,mid=l+r>>1;
	if(l==r){
		t[rt]--;
		return l;
	}
	t[rt]--;
	if(t[ls]>=x){
		return kill(x,l,mid,ls);
	}
	else{
		return kill(x-t[ls],mid+1,r,rs);
	}
}

int main(){
	int T,n,m,q;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&q);
		for(int i=0;i<q;i++){
			scanf("%d",&a[i].x);
			a[i].id=i;
		}
		sort(a,a+q,cmp);
		build(1,n,1);
		int cnt=0,l=0,res=n;
		for(;l<q;){
			int sum=0;
			for(int j=1,zz=0;j<=res&&l<q;j+=m,zz++){
				sum++;
				cnt++;
				if(cnt==a[l].x){
					int tmp=kill(j-zz,1,n,1);
					while(l<q&&a[l].x==cnt){
						ans[a[l].id]=tmp;
						l++;
					}
				}
				else kill(j-zz,1,n,1);
			}
			res-=sum;
		}
		for(int i=0;i<q;i++){
			printf("%d\n",ans[i]);
		}
	}
}
