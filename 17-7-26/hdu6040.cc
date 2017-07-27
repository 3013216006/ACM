#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
unsigned int d[10000010];

unsigned int myget(unsigned int &a,unsigned int &b,unsigned int &c){
	unsigned int t;	
	a^=a<<16;
	a^=a>>5;
	a^=a<<1;
	t=a;
	a=b;
	b=c;
	c=t^a^b;
	return c;
}

unsigned int getk(int l,int r,int k){
	//cout << l<< " " << r << " " << k << endl;
//	for(int i=l;i<=r;i++)
		//cout << d[i] << endl;
	if(l==r) return d[l];
	unsigned int tmp=d[l];
	int l1=l,r1=r;
	while(l1<=r1){
		while(l1<=r1&&d[l1]<=tmp) l1++;
		while(l1<=r1&&d[r1]>tmp) r1--;
		if(l1<=r1){
			swap(d[l1],d[r1]);
			l1++;
			r1--;
		}
	}
	if(r==r1){
		if(l1-l==k) return tmp;
		else return getk(l+1,r,k);
	}
	if(l1-l>=k) return getk(l,r1,k);
	else return getk(l1,r,k-(l1-l));
}
void getnum(unsigned int a,unsigned int b,unsigned int c,int n){
	for(int i=0;i<n;i++){
		d[i]=myget(a,b,c);
	}
}
int ans[110];
pair<int,int> v[110];
int main(){
	int n,m,a,b,c,x;
	int cas=1;
	while(~scanf("%d%d%d%d%d",&n,&m,&a,&b,&c)){
		for(int i=0;i<m;i++){
			scanf("%d",&x);
			v[i]=make_pair(x,i);
		}
		getnum(a,b,c,n);
		sort(v,v+m);
		v[m].first=n;
		for(int i=m-1;i>=0;i--){
			if(v[i].first==v[i+1].first)
				ans[v[i].second]=ans[v[i+1].second];
			else{
				nth_element(d,d+v[i].first,d+v[i+1].first);
//				cout << v[i].first << " " << v[i].second  << endl;
				ans[v[i].second]=d[v[i].first];
			}
		}
//		for(int i=0;i<n;i++) 
//			cout << d[i] << endl;
		printf("Case #%d:",cas++);
		for(int i=0;i<m;i++){
		//	printf(" %u",getk(0,n-1,v[i]+1));
		//	nth_element(d,d+v[i],d+n);
		//	printf(" %u",d[v[i]]);
			printf(" %u",ans[i]);
		}
		puts("");
	}
}
