#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;
int x[600],y[600];
map<pair<int,int>,int> M;
int main(){
	int n;
	while(~scanf("%d",&n)){
		M.clear();
		for(int i=0;i<n;i++){
			scanf("%d%d",&x[i],&y[i]);
			M[make_pair(x[i],y[i])]=1;
		}
		long long ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int tmpx=y[i]-y[j];
				int tmpy=x[i]-x[j];
				if(M.count(make_pair(x[i]+tmpx,y[i]-tmpy))>0&&
					M.count(make_pair(x[j]+tmpx,y[j]-tmpy))>0)
					ans++;
				if(M.count(make_pair(x[i]-tmpx,y[i]+tmpy))>0&&
					M.count(make_pair(x[j]-tmpx,y[j]+tmpy))>0)
					ans++;
			}
		}
		ans/=4;
		cout << ans << endl;
	}
}
