#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN=200100;
int t1[MAXN],t2[MAXN],c[MAXN];

bool cmp(int *r,int a,int b,int l){
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
/*
void da(int str[],int sa[],int rank[],int height[],int n,int m){
	n++;
	int i,j,p,*x=t1,*y=t2;
	for(i=0;i<m;i++) c[i]=0;
	for(i=0;i<n;i++) c[x[i]==str[i]]++;
	for(i=1;i<m;i++) c[i]+=c[i-1];
	for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
	for(j=1;j<=n;j<<=1){
		p=0;
		for(i=n-j;i<n;i++) y[p++]=i;
		for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
		for(i=0;i<m;i++) c[i]=0;
		for(i=0;i<n;i++) c[x[y[i]]]++;
		for(i=1;i<m;i++) c[i]+=c[i-1];
		for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		p=1;x[sa[0]]=0;
		for(i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		if(p>=n) break;
		m=p;
	}
	int k=0;
	n--;
	for(i=0;i<=n;i++) rank[sa[i]]=i;
	for(i=0;i<n;i++){
		if(k)k--;
		j=sa[rank[i]-1];
		while(str[i+k]==str[j+k])k++;
		height[rank[i]]=k;
		cout << k << endl;
	}
}*/
void da(int str[],int sa[],int rank[],int height[],int n,int m)
{
n++;
int i, j, p, *x = t1, *y = t2;
for(i = 0;i < m;i++)c[i] = 0;
for(i = 0;i < n;i++)c[x[i] = str[i]]++;
for(i = 1;i < m;i++)c[i] += c[i-1];
for(i = n-1;i >= 0;i--)sa[--c[x[i]]] = i;
for(j = 1;j <= n; j <<= 1)
{
p = 0;
for(i = n-j; i < n; i++)y[p++] = i;
for(i = 0; i < n; i++)if(sa[i] >= j)y[p++] = sa[i] - j;
for(i = 0; i < m; i++)c[i] = 0;
for(i = 0; i < n; i++)c[x[y[i]]]++;
for(i = 1; i < m;i++)c[i] += c[i-1];
for(i = n-1; i >= 0;i--)sa[--c[x[y[i]]]] = y[i];
swap(x,y);
p = 1; x[sa[0]] = 0;
for(i = 1;i < n;i++)
x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
if(p >= n)break;
m = p;
}
int k = 0;
n--;
for(i = 0;i <= n;i++)rank[sa[i]] = i;
for(i = 0;i < n;i++)
{
if(k)k--;
j = sa[rank[i]-1];
while(str[i+k] == str[j+k])k++;
height[rank[i]] = k;
}
}
int rk[MAXN],ht[MAXN];
char s[100010],s1[100010];
int tp[200100];
int sa[200100];
int main(){
	while(~scanf("%s%s",s,s1)){
		int l=strlen(s);
		int l1=strlen(s1);
		int r=0;
		for(int i=0;i<l;i++)
			tp[r++]=s[i]-'a'+1;
		tp[r++]=27;
		int x=r;
		for(int i=0;i<l1;i++)
			tp[r++]=s1[i]-'a'+1;
		tp[r]=0;
		da(tp,sa,rk,ht,r,28);
		int ans=0;
		for(int i=1;i<=r;i++){
//			cout << sa[i] << endl;
//			cout << rk[i] << endl;
//			cout << "~" << ht[i] << endl;
			if(sa[i-1]>=x&&sa[i]<x) ans=max(ans,ht[i]);
			if(sa[i-1]<x&&sa[i]>=x) ans=max(ans,ht[i]);
					
		}
		cout << ans << endl;
	}
}
