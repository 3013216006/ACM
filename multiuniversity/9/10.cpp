#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i = 0;i < n; i++)  
const int size  = 400005,INF = 1<<30;  
int rk[size],sa[size],height[size],w[size],wa[size],res[size];  
int w1[size];
int rmq[200005][18];
void getSa (int len,int up) {  
    int *k = rk,*id = height,*r = res, *cnt = wa;  
    rep(i,up) cnt[i] = 0;  
    rep(i,len) cnt[k[i] = w[i]]++;  
    rep(i,up) cnt[i+1] += cnt[i];  
    for(int i = len - 1; i >= 0; i--) {  
        sa[--cnt[k[i]]] = i;  
    }  
    int d = 1,p = 0;  
    while(p < len){  
        for(int i = len - d; i < len; i++) id[p++] = i;  
        rep(i,len)  if(sa[i] >= d) id[p++] = sa[i] - d;  
        rep(i,len) r[i] = k[id[i]];  
        rep(i,up) cnt[i] = 0;  
        rep(i,len) cnt[r[i]]++;  
        rep(i,up) cnt[i+1] += cnt[i];  
        for(int i = len - 1; i >= 0; i--) {  
            sa[--cnt[r[i]]] = id[i];  
        }   
        swap(k,r);  
        p = 0;  
        k[sa[0]] = p++;  
        rep(i,len-1) {  
            if(sa[i]+d < len && sa[i+1]+d <len &&r[sa[i]] == r[sa[i+1]]&& r[sa[i]+d] == r[sa[i+1]+d])  
                k[sa[i+1]] = p - 1;  
            else k[sa[i+1]] = p++;  
        }  
        if(p >= len) return ;  
        d *= 2,up = p, p = 0;  
    }  
}  
void getHeight(int len) {  
    rep(i,len) rk[sa[i]] = i;  
    height[0] =  0;  
    for(int i = 0,p = 0; i < len - 1; i++) {  
        int j = sa[rk[i]-1];  
        while(i+p < len&& j+p < len&& w[i+p] == w[j+p]) {  
            p++;  
        }  
        height[rk[i]] = p;  
        p = max(0,p - 1);  
    }  
}  

int cmp(int x,int l1,int l){
	int ret=0,i;
	for(i=0;i<l1&&x+i<l;i++){
		if(w1[i]<w[x+i]) return -1;
		if(w1[i]>w[x+i]) return 1;
	}
	if(i<l1) return 1;
	return 0;
}

int find_lower(int l,int r,int l1,int l2){
	int ret=-1;
	while(l<=r){
		int mid=l+r>>1;
		int pan=cmp(sa[mid],l1,l2);
		if(pan<0) r=mid-1;
			else if(pan>0) l=mid+1;
				else r=mid-1,ret=mid;
	}
	return ret;
}

int find_upper(int l,int r,int l1,int l2){
	int ret=-1;
	while(l<=r){
		int mid=l+r>>1;
		int pan=cmp(sa[mid],l1,l2);
		if(pan<0) r=mid-1;
			else if(pan>0) l=mid+1;
				else l=mid+1,ret=mid;
	}
	return ret;
}
void Rmq(int l){
	for(int i=0;i<l;i++)
		rmq[i][0]=height[i];
	for(int k=1;k<18;k++){
		int r=1<<(k-1);
		for(int i=0;i<l-r;i++){
			rmq[i][k]=min(rmq[i][k-1],rmq[i+r][k-1]);
		}
	}

}
char s[size],s1[size];
int main(){
	int T,n,m,cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		int l=0;
		for(int i=0;i<n;i++){
			scanf("%s",s1);
			s[l++]='#';
			int k=strlen(s1);
			for(int j=0;j<k;j++)
				s[l++]=s1[j];
		}
		s[l++]='z'+1;
		int cnt=n;
		for(int i=0;i<l;i++){
		if(s[l-i-1]=='#'){
			w[i]=cnt--;
		}
		else{
			w[i]=s[l-i-1]-'a'+1+n;
		}
		}
		getSa(l,30+n);
		getHeight(l);
		Rmq(l);
		printf("Case #%d:\n",cas++);
		for(int i=0;i<m;i++){
			scanf("%s",s1);
			int l1=strlen(s1);
			for(int j=0;j<l1;j++)
				w1[j]=s1[l1-j-1]-'a'+1+n;
			int x1=find_lower(0,l-1,l1,l);
			int y1=find_upper(0,l-1,l1,l);
			int t=l;
			if(x1==-1){
				puts("0");
				continue;
			}
			int r=1,tt=0;
			while(r*2<y1-x1) r*=2,tt++;
			if(x1==y1){
				int fxz=sa[x1];
				t=l1;
				while(w[fxz+t]>n) t++;
			}
			else t=min(rmq[x1+1][tt],rmq[y1-r+1][tt]);
			int t2=max(height[x1],height[y1+1]);
			cout << t-t2 << endl;
		}

	}
}
