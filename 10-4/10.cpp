#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
struct BigNum{
	int l,a[1200];
};
char s[1200];

void print(BigNum a){
	for(int i=a.l-1;i>=0;i--)
		printf("%d",a.a[i]);

	printf("\n");
}
BigNum sub(BigNum a,BigNum b){
	if(b.l>a.l){
		a.l=-1;
		return a;
	}
	int l=a.l;
	for(int i=0;i<l;i++){
		a.a[i]-=b.a[i];
		while(a.a[i]<0){
			a.a[i]+=10;
			a.a[i+1]--;
		}
	}
	if(a.a[l]<0){
		a.l=-1;
		return a;
	}
	while(a.l>1&&a.a[a.l-1]==0) a.l--;
	return a;
}

queue<BigNum> Q;
int main(){
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		BigNum a;
		int l,flag=0;
		a.l=strlen(s);
		l=a.l;
		for(int i=0;i<l;i++)
			a.a[l-i-1]=s[i]-'0';
		a.a[l]=0;
		int cnt=0;
		while(1){
			if(a.l==1&&a.a[0]==0) break;
			BigNum b;
			b.l=a.l;
			for(int i=0;i<a.l;i++)
				b.a[i]=a.a[i];
			for(int i=0;i<a.l/2;i++)
				b.a[i]=a.a[a.l-i-1];
			BigNum c=sub(a,b);
			if(c.l!=-1){
			}
			else{
				int mid=b.l/2;
				b.a[mid]--;
				while(b.a[mid]<0){
					b.a[mid]+=10;
					mid++;
					b.a[mid]--;
				}
				while(b.l>1&&b.a[b.l-1]==0) b.l--;
				for(int i=0;i<b.l/2;i++)
					b.a[i]=b.a[b.l-i-1];
				c=sub(a,b);
			}
				Q.push(b);
				cnt++;
				a.l=c.l;
				for(int i=0;i<c.l;i++)
					a.a[i]=c.a[i];
				a.a[a.l]=0;
		}
		printf("Case #%d:\n%d\n",cas++,cnt);
		while(!Q.empty()){
			a=Q.front();
			Q.pop();
			print(a);
		}
	}
}
