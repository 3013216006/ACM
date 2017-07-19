#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
#define rep(i,n) for(int i = 0;i < n; i++)  
const int size  = 200005,INF = 1<<30;  
int rk[size],sa[size],height[size],w[size],wa[size],res[size];  
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
int le[size],my[size];
char s[10],s1[size];
int main(){
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		scanf("%s",s1);
		int l=strlen(s1);
		int r=-1;
		for(int i=0;i<l;i++){
			w[l-1-i]=s1[i]-'a'+1;
			if(s1[i]==s[0]) r=i;
			le[i]=r;
		}
		w[l++]=0;
		getSa(l,30);
		getHeight(l);
		long long ans=0;
		stack<int> S;
		stack<int> S1;
		stack<int> s2;
		S.push(sa[1]);
		S1.push(sa[l-1]);
		s2.push(l);
		int maxl=l,maxr=l;
		memset(my,0,sizeof(my));
		for(int i=2;i<l;i++){
			if(!S.empty()){
				maxl=height[i];
				while(!S.empty()&&S.top()>sa[i]){
					my[S.top()]=maxl;
					S.pop();
					
					maxl=min(maxl,s2.top());
					s2.pop();
				}
				if(S.empty()) maxl=l;
				S.push(sa[i]);
				s2.push(maxl);
			}
			else{
				S.push(sa[i]);
				maxl=l;
			}
		}
		while(!s2.empty()) s2.pop();
		s2.push(l);
		for(int i=l-1;i>=2;i--){
			if(!S1.empty()){
				maxr=height[i];
				while(!S1.empty()&&S1.top()>sa[i-1]){
					my[S1.top()]=max(my[S1.top()],maxr);
					S1.pop();
					maxr=min(maxr,s2.top());
					s2.pop();
				}
				if(S1.empty()) maxr=l;
				S1.push(sa[i-1]);
				s2.push(maxr);
			}
			else{
				S1.push(sa[i]);
				maxr=l;
			}
		}
		maxl=l;
		l--;
		for(int i=0;i<l;i++){
			ans+=min(le[i]+1,i+1-my[l-i-1]);
		}
		printf("Case #%d: %lld\n",cas++,ans);
	}
}
