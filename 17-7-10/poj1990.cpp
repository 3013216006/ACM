#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int x,y;
}a[20020];
bool cmp(Node a,Node b){
	return a.x<b.x;
}
int N=20000;
long long t[20020][4];
int lowbit(int x){
	return x&(-x);
}

void add(int x,long long op,int i){
	while(x<=n){
		t[x][i]+=op;
		x+=lowbit(x);
	}
}

long long query(int x,int i){
	long long ret=0;
	while(x){
		ret+=t[x][i];
		x-=lowbit(x);
	}
	return ret;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].y,&a[i].x);
		}
		sort(a,a+n,cmp);
		long long sum=0,sum2=0;
		memset(t,0,sizeof(t));
		long long ans=0;
		for(int i=0;i<n;i++){
			long long numSmall=query(a[i].y,0);
			long long sumSmall=query(a[i].y,1);
			long long sumLarge=sum-query(a[i].y,2);
			long long sumallLarge=sum2-query(a[i].y,3);
	//		cout << "-------------" << i << "-----------------" << endl;
	//		cout << a[i].x << " " << a[i].y << endl<< endl;
			ans+=(1ll*a[i].x*numSmall-sumSmall)*a[i].y;
	//		cout << ans << endl;
			ans+=1ll*a[i].x*sumLarge-sumallLarge;
	//		cout << ans << endl;

	//		cout << "---------------------------" << endl;
	//		cout << endl;
			add(a[i].y,1,0);
			add(a[i].y,a[i].x,1);
			add(a[i].y,a[i].y,2);
			sum+=a[i].y;
			add(a[i].y,1ll*(a[i].x)*a[i].y,3);
			sum2+=1ll*a[i].x*a[i].y;
		}
		cout << ans << endl;
	}
}
