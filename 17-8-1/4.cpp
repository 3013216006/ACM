#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int v[500000][33],tmp[2][500000];
int a[500000];
int sum[500000][33];
int sum1[500000][33];
long long ans=0;
void getans(int l,int r,int k){
	if(l>=r) return;
	int nex=k&1,now=nex^1;
	int r1=l,l1=r;
	for(int i=l;i<=r;i++){
		if(v[tmp[now][i]][k]==0) tmp[nex][r1++]=tmp[now][i];
		else tmp[nex][l1--]=tmp[now][i];
	}
//	cout << l << " " << r << " " << k << endl;
//	cout << sum[k] << " " << r1-l << " " << r-l1 << endl;
//	cout << endl;
//	ans+=1ll*sum[k]*(r1-l)*(r-l1-1);
	
	for(int i=l1+1,j=r;i<j;i++,j--){
		swap(tmp[nex][i],tmp[nex][j]);
	}
	/*
	if(k<=3){
	cout << l << " " << r << " " << k << endl;
	for(int i=l;i<r1;i++) 
		cout << tmp[nex][i] << " ";
		puts("");
	for(int i=l1+1;i<=r;i++){
		cout << tmp[nex][i] << " ";
	}
	puts("");
	puts("");
	}
	*/
	long long tmpsum=0;
	int num=0;
	for(int i=l1+1,j=l;i<=r;i++){
		while(j<r1&&tmp[nex][i]>tmp[nex][j]) tmpsum+=sum[tmp[nex][j++]][k];
//		if(k<=3){
//			cout << i << " " << j << " " << l << endl;
//				cout << tmp[nex][i] << " " << tmpsum << endl ;
//		}
		ans+=1ll*sum[tmp[nex][i]][k]*(j-l)-tmpsum;
//		cout << ans << endl << endl;
	}
	tmpsum=0;
	for(int i=l,j=l1+1;i<r1;i++){
		while(j<=r&&tmp[nex][i]>tmp[nex][j]) tmpsum+=sum1[tmp[nex][j++]][k];
		ans+=1ll*sum1[tmp[nex][i]][k]*(j-l1-1)-tmpsum;
	}
	if(k==0) return;
	else getans(l,l1,k-1),getans(r1,r,k-1);
}

int main(){
	int T;
	int n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(sum,0,sizeof(sum));
		memset(sum1,0,sizeof(sum1));
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			for(int j=0;j<30;j++){
				if(a[i]&(1<<j)) sum1[i][j]=1,v[i][j]=1;
				else sum[i][j]=1,v[i][j]=0;
			}
			tmp[0][i]=i;
		}
		for(int i=1;i<n;i++)
			for(int j=0;j<30;j++){
				sum[i][j]+=sum[i-1][j];sum1[i][j]+=sum1[i-1][j];
			}
		ans=0;
		getans(0,n-1,29);
		cout << ans << endl;
	}
}
