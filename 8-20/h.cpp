#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int a[200100];
int t[90][200100];
int sum[90][200100];
int pre[200010];
int haha[200010];
int used[200010];
int ljc[90];
int ans,x,y,n,m;
vector<int> v[20000];
int cnt;
void init(){
	for(int i=0;i<cnt;i++)
		v[i].clear();
//	memset(t,0,sizeof(t));
	memset(pre,0,sizeof(int)*(n+10));
	memset(haha,0,sizeof(int)*(n+10));
	memset(sum,0,sizeof(sum));
}

int lowbit(int x){
	return (-x)&x;
}
void add(int x,int y,int k){
	while(y<=n){
		t[x][y]+=k;
		y+=lowbit(y);
	}
}

int query(int x,int y){
	int ret=0;
	while(y){
		ret+=t[x][y];
		y-=lowbit(y);
	}
	return ret;
}

int main(){
	memset(a,0,sizeof(a));
	a[0]=1;
	cnt=1;
	for(int i=2;i<=200000;i++)
	if(a[i]==0){
		a[cnt++]=i;
		for(int j=i+i;j<=200000;j+=i)
			a[j]=1;
	}
	memset(sum,0,sizeof(sum));
	memset(used,0,sizeof(used));
	while(~scanf("%d%d",&n,&m)){
		if(n==0&&m==0) break;
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if(x==1) sum[0][i]=1;
			for(int j=1;j<88&&x!=1;j++)
				if(x%a[j]==0){
					haha[i]++;
					sum[j][i]=1;
					v[j].push_back(i);
					while(x%a[j]==0)x/=a[j];
				}
			if(x!=1){
				int t=lower_bound(a,a+cnt,x)-a;
				v[t].push_back(i);
			}
			for(int j=0;j<88;j++)
				sum[j][i]+=sum[j][i-1];
		}
		for(int i=0;i<m;i++){
			memset(ljc,0,sizeof(ljc));
			scanf("%d%d",&x,&y);
			if(x>y) swap(x,y);
			int cn=0;
			ans=0;
			for(int j=1;j<88;j++){
				if(sum[j][y]-sum[j][x-1]==1){
					int tmp=(lower_bound(v[j].begin(),v[j].end(),x)-v[j].begin());
					tmp=v[j][tmp];
					used[tmp]++;
					ljc[j]=tmp;
					if(used[tmp]==haha[tmp]) ans++;
				}
			}
			for(int j=1;j<88;j++)
				if(ljc[j]){
					used[ljc[j]]--;
				}
			for(int j=88;j<cnt;j++)
			if(v[j].size()>0){
				int l=(lower_bound(v[j].begin(),v[j].end(),x)-v[j].begin());
				int r=upper_bound(v[j].begin(),v[j].end(),y)-v[j].begin()-1;
				if(l==r&&v[j][l]<=y&&v[j][l]>=x) ans++;
			}
			cout << ans << endl;
			ans+=sum[0][y]-sum[0][x-1];
			printf("%d\n",ans);
		}
	}
}
