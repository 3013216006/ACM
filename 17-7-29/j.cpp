#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct Node{
	int x,y;
}a[1001];
map<int,int> M,M1;
vector<int> v[1001],v1[1001];
int main(){
	int n;
	int x,y;
	while(~scanf("%d",&n)){
		int cnt=0,cnt1=0;
		M.clear();
		M1.clear();
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
			if(M.count(a[i].x)>0);
			else M[a[i].x]=cnt++;
			
			if(M1.count(a[i].y)>0);
			else M1[a[i].y]=cnt1++;
		}
		for(int i=0;i<cnt;i++)
			v[i].clear();
		for(int i=0;i<cnt1;i++)
			v1[i].clear();
		for(int i=0;i<n;i++){
			v[M[a[i].x]].push_back(a[i].y);
			v1[M1[a[i].y]].push_back(a[i].x);
		}
		for(int i=0;i<cnt;i++)
			sort(v[i].begin(),v[i].end());
		for(int i=0;i<cnt1;i++)
			sort(v1[i].begin(),v1[i].end());
		int ans=0,to=0;
		x=0,y=0;
		vector<int>::iterator it;
		while(ans<=4000){
			if(to==3){
					if(M.count(x)>0){
						it=upper_bound(v[M[x]].begin(),v[M[x]].end(),y);
						if(it==v[M[x]].end()) break;
						else{
							y=*it-1;
							ans++;
							to=0;
						}
					}
					else break;
			}
			else if(to==2){
					if(M1.count(y)>0){
						it=upper_bound(v1[M1[y]].begin(),v1[M1[y]].end(),x);
						if(it==v1[M1[y]].begin()) break;
						it--;
						{
							x=*it+1;
							ans++;
							to=3;
						}
					}
					else break;
			}
			else if(to==1){
					if(M.count(x)>0){
						it=upper_bound(v[M[x]].begin(),v[M[x]].end(),y);
						if(it==v[M[x]].begin()) break;
						it--;
						{
							y=*it+1;
							ans++;
							to=2;
						}
					}
					else break;
			}
			else{
					if(M1.count(y)>0){
						it=upper_bound(v1[M1[y]].begin(),v1[M1[y]].end(),x);
						if(it==v1[M1[y]].end()) break;
						else{
							x=*it-1;
							ans++;
							to=1;
						}
					}
					else break;
			}
//			cout << x << " " << y << " " << to << endl;
		}
		if(ans>=4000) puts("-1");
		else printf("%d\n",ans);
	}
}
