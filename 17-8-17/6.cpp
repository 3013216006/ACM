#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN=200010;
int t1[MAXN],t2[MAXN],c[MAXN];
char s[100010];
int x,y;

bool cmp(int *r,int a,int b,int l){
	return r[a] == r[b] && r[a+l] == r[b+l];
}

void da(int str[],int sa[],int rank[],int height[],int n,int m){
	n++;
	int i, j, p, *x = t1, *y = t2;
	for(i = 0;i < m;i++)c[i]=0;
	for(i=0;i<n;i++) c[x[i]=str[i]]++;
	for(i=1;i<m;i++) c[i] += c[i-1];
	for(i = n-1;i>=0;i--) sa[--c[x[i]]]=i;
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
		if(p>=n)break;
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
	}
}
int sa[MAXN],ht[MAXN],vis[MAXN],ans1[MAXN],ans2[MAXN],v[MAXN],a[MAXN],b[MAXN];
int rk[MAXN];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		int myl=0;
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			v[i]=myl;
			vis[myl]=i;
			scanf("%s",s);
			int l=strlen(s);
			for(int j=0;j<l;j++){
				a[myl]=s[j]-'a'+1;
				b[myl++]=l-j;
			}
			a[myl]=27;
			b[myl++]=0;
		}
		v[n+1]=myl;
		a[myl]=0;
		b[myl]=0;
		//for(int i=0;i<=myl;i++)
			//cout << a[i] << endl;
		da(a,sa,rk,ht,myl,29);
		for(int i=1;i<=myl;i++)
			ht[i]=min(ht[i],min(b[sa[i]],b[sa[i-1]]));
		//for(int i=0;i<=myl;i++)
			//cout << ht[i] << " " << sa[i] << endl;
		int m;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			memset(ans1,0,sizeof(ans1));
			memset(ans2,0,sizeof(ans2));
			scanf("%d%d",&x,&y);
			int tmp=0;
			for(int i=1;i<=myl;i++){
				if(sa[i]>=v[x]&&sa[i]<v[x+1]) tmp=ht[i+1];
				else tmp=min(tmp,ht[i]);
				//cout << tmp << " " << vis[sa[i]] << endl;
				if(vis[sa[i]]) ans1[vis[sa[i]]]=tmp;
			}
			tmp=0;
			for(int i=myl;i>=0;i--){
				//cout << tmp << " " << vis[sa[i]] << endl;
				if(vis[sa[i]]) ans1[vis[sa[i]]]=max(ans1[vis[sa[i]]],tmp);
				if(sa[i]>=v[x]&&sa[i]<v[x+1]) tmp=ht[i];
				else tmp=min(tmp,ht[i]);
			}

			tmp=0;
			for(int i=1;i<=myl;i++){
				if(sa[i]>=v[y]&&sa[i]<v[y+1]) tmp=ht[i+1];
				else tmp=min(tmp,ht[i]);
				if(vis[sa[i]]) ans2[vis[sa[i]]]=tmp;
			}
			tmp=0;
			for(int i=myl;i>=0;i--){
				if(vis[sa[i]]) ans2[vis[sa[i]]]=max(ans2[vis[sa[i]]],tmp);
				if(sa[i]>=v[y]&&sa[i]<v[y+1]) tmp=ht[i];
				else tmp=min(tmp,ht[i]);
			}

			ans1[x]=b[v[x]];
			ans2[y]=b[v[y]];
			int ans=0;
			for(int i=1;i<=n;i++)
				ans=max(ans,min(ans1[i],ans2[i]));
			cout << ans << endl;
		}
	}
}
