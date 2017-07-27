#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
deque<pair<int,int> > Q;
int a[300000],b[300000];
int mod=1000000007;
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		while(!Q.empty()) Q.pop_back();
		sort(b,b+n);
		for(int i=0;i<n;i++){
			a[i]-=(i+1);
			while(!Q.empty()&&Q.back().first<=a[i]) Q.pop_back();
			Q.push_back(make_pair(a[i],i+1));
		}
		int ans=0;
		for(int i=0,j=n+1;i<n;i++,j++){
//			cout << j << " " << ans  << endl;
			while(!Q.empty()&&Q.front().second<b[i]) Q.pop_front();
			pair<int,int> tmp=Q.front();
			ans+=tmp.first;
			if(ans>=mod) ans-=mod;
			int hehe=tmp.first-j;
			while(!Q.empty()&&Q.back().first<=hehe) Q.pop_back();
			Q.push_back(make_pair(hehe,j));
		}
		cout << ans << endl;
	}
}
