#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Node{
	long long x,y;
}a[3],b[3];

long long xmul(Node a,Node b,Node c){
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

long long myabs(long long x){
	if(x<0) return -x;
	return x;
}

void swap(){
	for(int i=0;i<3;i++){
		swap(a[i].x,b[i].x);
		swap(a[i].y,b[i].y);
	}
}

int pan(int x){
	int ret=1;
	for(int i=0;i<3;i++){
		int a1=(i+1)%3;
		int a2=(i+2)%3;
		long long tmp=xmul(a[i],a[a1],a[a2])*xmul(b[x],a[a1],a[a2]);
		if(tmp==0) ret=0;
		if(tmp<0) return -1;
	}
	return ret;
}

int _is(Node a,Node b,Node c,Node d){
	long long x1=xmul(c,a,b)*xmul(d,a,b);
	long long x2=xmul(a,c,d)*xmul(b,c,d);
	//if(xmul(c,a,b)*xmul(d,a,b)>0) return 0;
	//if(xmul(a,c,d)*xmul(b,c,d)>0) return 0;
	if(x1>0) return 0;
	if(x2>0) return 0;
//	if(x1==0&&x2==0) return 0;
	return 1;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<3;i++)
			scanf("%I64d%I64d",&a[i].x,&a[i].y);
		for(int i=0;i<3;i++)
			scanf("%I64d%I64d",&b[i].x,&b[i].y);
		long long s1=myabs(xmul(a[0],a[1],a[2]));
		long long s2=myabs(xmul(b[0],b[1],b[2]));
		if(s1<s2) swap();
		int ans=0,ans1=0;
		for(int i=0;i<3;i++){
			long long x=pan(i);
			if(x>0) ans++;
			if(x==0) ans1++;
		}
		swap();
		int ans2=0,ans3=0;
		for(int i=0;i<3;i++){
			long long x=pan(i);
		//	if(x>=0) ans2++;
		
			if(x==0) ans1++;
		}
		/*
		if(ans==3){
			if(ans-ans1!=3) puts("intersect");
			else puts("contain");
		}
		else if(ans2){
			if(ans2-ans3!=3) puts("intersect");
			else puts("contain");
		}
//		if(ans==3&&ans1==0)
//			puts("contain");
*/
		if(ans==3){
			puts("contain");
		}
		else{
			int flag=0;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++){
					if(_is(a[i],a[(i+1)%3],b[j],b[(j+1)%3])) flag=1;
				}
			if(ans1) flag=1;
			if(flag) puts("intersect");
			else 
			puts("disjoint");
		}
	}
}
