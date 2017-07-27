#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
vector<int> v[4];
int x,y,w;
int myget(int i,int l){
	if(l<0) return 0;
	if(v[i].size()==0) return 0;
	else return v[i][l];
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&w)){
		v[1].clear();
		v[2].clear();
		v[3].clear();
		for(int i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y*6/x);
		}
		for(int i=1;i<=3;i++)
			sort(v[i].begin(),v[i].end());
		int l1,l2,l3;
		l1=l2=l3=0;
		int r1,r2,r3;
		r1=v[1].size()-1;
		r2=v[2].size()-1;
		r3=v[3].size()-1;
		long long ans=0;
		int a[4];
		while((r1>=0||r2>=0||r3>=0)&&w){
			a[1]=myget(1,r1);
			a[2]=myget(2,r2);
			a[3]=myget(3,r3);
			int t=1;
			if(w>=2&&a[2]>a[t]) t=2;
			if(w>=3&&a[3]>a[t]) t=3;
			w-=t;
			ans+=a[t]*t/6;
			if(t==1) r1--;
			else if(t==2) r2--;
			else r3--;
		}
		for(int i=1;i<=3;i++){
			int lll=v[i].size();
			for(int j=0;j<lll;j++){
				v[i][j]=v[i][j]*i/6;
			}
		}
		if(w==1){
			long long tmp=0;
			if(r2>=0&&v[1].size()-r1>1){
				tmp=max(tmp,1ll*v[2][r2]-v[1][r1+1]);
			}
			if(r3>=0&&v[2].size()-r2>1){
				tmp=max(tmp,1ll*v[3][r3]-v[2][r2+1]);
			}
			if(r3>=0&&v[1].size()-r1>2){
				tmp=max(tmp,1ll*v[3][r3]-v[1][r1+1]-v[1][r1+2]);
			}
			if(r2>=1&&v[3].size()-r2>1){
				tmp=max(tmp,1ll*v[2][r2]+1ll*v[2][r2-1]-v[3][r2+1]);
			}
			ans+=tmp;
		}
		if(w==2){
			long long tmp=0;
			if(r3>=0&&v[1].size()-r1>1){
				tmp=max(tmp,1ll*v[3][r3]-v[1][r1+1]);
			}
			if(r3>=1&&v[2].size()-r2>2){
				tmp=max(tmp,1ll*v[3][r3]+v[3][r3-1]-v[2][r2+1]-v[2][r2+2]);
			}
			ans+=tmp;
		}
		if(w==0){
			long long tmp=0;
			if(r3>=0&&v[1].size()-r1>1&&v[2].size()-r2>1){
				tmp=max(tmp,1ll*v[3][r3]-v[2][r2+1]-v[1][r1+1]);
			}
//			cout << tmp << " " << v[3][r3] << " " << v[2][r2+1] << " " << v[1][r1+1]<< endl;
			if(r3>=1&&v[2].size()-r2>3){
				tmp=max(tmp,1ll*v[3][r3]+v[3][r3-1]-v[2][r2+1]-v[2][r2+2]-v[2][r2+3]);
			}
//			cout << tmp << endl;
			ans+=tmp;
		}
		cout << ans << endl;
	}
}
