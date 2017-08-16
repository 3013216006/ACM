#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN=20110;
int t1[MAXN],t2[MAXN],c[MAXN];

bool cmp(int *r,int a,int b,int l){
	return r[a]==r[b]&&r[a+l]==r[b+l];
}

void da(int str[],int sa[],int rank[],int height[],int n,int m){
	n++;
	int i, j, p, *x = t1, *y = t2;
	for(i = 0;i < m;i++) c[i] = 0;
	for(i = 0;i < n;i++) c[x[i] = str[i]]++;
	for(i = 1;i < m;i++) c[i] += c[i-1];
	for(i = n-1;i >= 0;i--) sa[--c[x[i]]] = i;
	for(j = 1;j <= n; j <<= 1)
	{
		p = 0;
		for(i = n-j; i < n; i++)y[p++] = i;
		for(i = 0;i < n; i++) if(sa[i] >= j)y[p++]=sa[i] - j;
		for(i = 0;i < m; i++)c[i]=0;
		for(i = 0;i < n; i++)c[x[y[i]]]++;
		for(i = 1;i < m; i++)c[i] += c[i-1];
		for(i = n-1; i >= 0;i--) sa[--c[x[y[i]]]] = y[i];
		swap(x,y);
		p = 1; x[sa[0]] = 0;
		for(i = 1;i < n;i++)
			x[sa[i]] =cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		if(p >= n) break;
		m = p;
	}
	int k = 0;
	n--;
	for(i = 0;i <= n;i++) rank[sa[i]]=i;
	for(i = 0;i < n;i++)
	{
		if(k)k--;
		j = sa[rank[i]-1];
		while(str[i+k] == str[j+k]) k++;
		height[rank[i]]=k;
	}
}

int rk[MAXN],ht[MAXN],sa[MAXN];
int n;
int pan(int x){
	for(int i=1;i<=n;i++)
	if(ht[i]>=x)
	{
		int mi=min(sa[i],sa[i-1]);
		int mx=max(sa[i],sa[i-1]);
		while(i+1<=n&&ht[i+1]>=x){
			i++;
			mi=min(mi,sa[i]);
			mx=max(mx,sa[i]);
		}
		if(mx>=mi+x)return 1;
	}
	return 0;
}
int a[MAXN];

int main(){
	while(~scanf("%d",&n),n){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<n-1;i++)
			a[i]=a[i]-a[i+1]+88;
		n--;
		a[n]=0;
		//for(int i=0;i<=n;i++) 
			//cout << a[i] << endl;
		//cout << "__________________________________\n";
		da(a,sa,rk,ht,n,180);
		//for(int i=0;i<=n;i++)
		//cout << sa[i] << endl;
		//cout << "__________________________________\n";
		//for(int i=0;i<=n;i++) 
		//cout << ht[i] << endl;
		int l=4,r=n/2,ans=-1;
		while(l<=r){
			int mid=l+r>>1;
			if(pan(mid)){
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		cout << ans+1 << endl;
	}
}
