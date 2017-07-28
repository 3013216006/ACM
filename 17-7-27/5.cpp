#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[3100];
struct Node{
	int l,r;
	Node(){}
	Node(int _l,int _r){
		l=_l,r=_r;
	}
}sav[3100],s[3100];
int ans;
int mytmp[3100];
int getans(int l,int r,int L,int R){
	int ret=0;
	int r1=l,mi=a[l];
	int haha=R;
	while(l<=r){
		r1=l,mi=a[l];
		while(r1-l!=R-mi){
			r1++;
			mi=min(mi,a[r1]);
		}
		mytmp[ret]=mi;
		s[ret++]=Node(l,r1);
		R=mi-1;
		l=r1+1;
	}
	
	//cout << "yes" << endl;
	if(ret==1) return 0;
	if(ret==2) return 1;
	int ans=0;
	for(int i=1;i<ret-1;i++){
		mi=mytmp[i];
//		cout << mi << endl;
//		cout << s[i].l << " " << s[i].r << endl;
		int tmp=0;
		for(int j=s[i].l;j<=s[i].r;j++){
//			cout << j << endl;
			int mx=a[j],r=j;
			while(mx-mi!=r-j){
				r++;
				mx=max(mx,a[r]);
			}
			mi=mx+1;
			j=r;
			tmp++;
		}
		if(i==0||i==ret-1) ans=max(ans,tmp-1);
		else ans=max(ans,tmp);
	}
	//cout << "yes1" << endl;
	return 1+ans;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		ans=0;
		long long haha=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
 		for(int i=1;i<=n;i++){
			int mx=a[i],r=i;
			while(mx!=r){
				r++;
				mx=max(mx,a[r]);
			}
			sav[ans++]=Node(i,r);
			i=r;
		}
		int tmp=ans;
		for(int i=0;i<tmp;i++){
			ans=max(ans,tmp+getans(sav[i].l,sav[i].r,sav[i].l,sav[i].r));
		}
		cout << ans << endl;
	}
}
