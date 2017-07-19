#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
using namespace std;
set<pair<int,int> > s;
set<pair<int,int> >::iterator it;
vector<int> v[10000];
int fa[100020];
int a[100010],to[100020];
int find(int x){
//	cout << x << " " << fa[x] << endl;
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
int main(){
	int T;
	int n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			fa[i]=i;
			scanf("%d",&a[i]);
		}
		int cnt=0,l=0;
		s.clear();
		for(int i=n-1;i>=0;i--){
			pair<int,int> t1,tmp;
			t1=make_pair(a[i],i);
			it=s.lower_bound(t1);
//			cout << a[i] << " " << i << "_________________" << endl;
			if(it!=s.end()){
				tmp=*it;
//				cout << tmp.first << "QAQ " << tmp.second << endl;
				fa[tmp.second]=i;
				s.erase(it);
			}
			it=s.lower_bound(t1);
			if(it!=s.end()){
				tmp=*it;
//				cout << tmp.first << "WAW" << tmp.second << endl;
				fa[tmp.second]=i;
				s.erase(it);
			}
			s.insert(t1);
		}
		for(int i=0;i<n;i++){
//			cout << i << endl;
			int fx=find(i);
			if(fx==i){
				to[i]=cnt++;
				v[to[i]].clear();
				v[to[i]].push_back(i);
			}
			else{
				v[to[fx]].push_back(i);
			}
		}
		printf("%d\n",cnt);
		for(int i=0;i<cnt;i++){
			int l=v[i].size();
			printf("%d",l);
			for(int j=0;j<l;j++){
				printf(" %d",v[i][j]+1);
			}
			puts("");
			v[i].clear();
		}
	}
}
