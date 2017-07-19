#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int t[500000];
int dp1[10][10],dp2[1024][10],dp3[1024][1024];
int a[500000];


void init(){
	memset(dp1,0,sizeof(dp1));
	memset(dp2,0,sizeof(dp2));
	memset(dp3,0,sizeof(dp3));
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			dp1[i][j]=(i+j)%10+(i+j)/10;
	for(int i=0;i<1024;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<10;k++){
				if(i&(1<<k)){
					dp2[i][j]|=1<<dp1[j][k];
				}
			}
		}
	}
	for(int i=0;i<1024;i++)
		for(int j=0;j<1024;j++)
			for(int k=0;k<10;k++)
				if(j&(1<<k)){
					dp3[i][j]|=dp2[i][k];
				}
}

int myget(int x){
	while(x>=10){
		x=x/10+x%10;
	}
	return x;
}

void build(int l,int r,int rt){
	if(l==r){
		t[rt]=1<<myget(a[l]);
	cout << rt<<":" << t[rt] << endl;
		return;
	}
	int ls=rt<<1,rs=ls|1,mid=l+r>>1;
	build(l,mid,ls);
	build(mid+1,r,rs);
	t[rt]=dp3[t[ls]][t[rs]]|t[ls]|t[rs];
	cout << rt<<":" << t[rt] << endl;
	return;
}

int query(int l,int r,int L,int R,int rt){
	if(l>=L&&r<=R){
		cout << l << " " << r << endl;
		return t[rt];
	}
	int mid=l+r>>1,ls=rt<<1,rs=ls|1;
	int lson=0,rson=0;
	if(L<=mid) lson=query(l,mid,L,R,ls);
	if(R>mid) rson=query(mid+1,r,L,R,rs);
	return lson|rson|dp3[lson][rson];
}

int main(){
	init();
	int T,n,m,cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i = 1; i <= n; i++){
			scanf("%d",&a[i]);
		}
		build(1,n,1);
		int k,l,r;
		scanf("%d",&m);
		printf("Case #%d:\n",cas++);
		while(m--){
			scanf("%d%d",&l,&r);
			int ans=query(1,n,l,r,1);
			cout << ans << endl;
			l=9;
			for(int i=0;i<5;i++){
//				cout << endl<< "aaaa"  << ans << " " << l << " " <<  (1<<l) << " "  <<  (ans&(1<<l))  << endl << endl;
				while(l>=0 && ((ans&(1<<l))==0) ) l--;	
				if(i) printf(" ");
				printf("%d",l);
				if(l>=0) l--;
			}
			puts("");
		}
	}
}
