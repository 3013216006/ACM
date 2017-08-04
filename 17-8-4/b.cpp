#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
struct Node{
	long long x,y;
	Node(){}
	Node(long long _x,long long _y){
		x=_x,y=_y;
	}
};
int n,k;
vector<Node> v;
int a[100];

int main(){
	int T;
	int cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		long long ans=1;
		v.clear();
		for(int i=1;i<k;i++) ans*=2;
		int mytp=n;
		for(int i=0;i<=k;i++){
			if(mytp&1) a[i]=1;
			else a[i]=0;
			mytp/=2;
		}
		int tp=-1;
		if(a[0]==0){
			ans++;
			tp=0;
			while(a[tp]==0) tp++;
			tp--;
		}
		int l=k-1;
		int f=0;
//		cout << tp << endl;
		while(ans){
			if(a[l]==0){
//				cout << l << endl;
				if(tp==l){
					if(tp!=k-1){
						v.push_back(Node(ans,-1));
						l--;
						ans/=2;
					}
					while(l>=0) v.push_back(Node(ans,1)),ans/=2,l--;
					continue;
				}
				v.push_back(Node(ans,1));
				l--;
				ans/=2;
				while(a[l]==0){
					v.push_back(Node(ans,-1));
					l--;
					ans/=2;
				}
				v.push_back(Node(ans,-1));
				l--;
				ans/=2;
			}
			else{
				v.push_back(Node(ans,1));
				ans/=2;
				l--;
			}
		}
		l=v.size();
		printf("Case #%d:\n",cas++);
		for(int i=l-1;i>=0;i--){
			if(v[i].y==1)
			printf("%lld +\n",v[i].x);
			else printf("%lld -\n",v[i].x);
			
		}
	}
}
