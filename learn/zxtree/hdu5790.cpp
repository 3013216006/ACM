#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Trie{
	int tr[100100][26];
	int L,rt;
	int newnode(){
		for(int i=0;i<26;i++)
			tr[L][i]=-1;
		L++;
		return L-1;
	}

	void init(){
		L=0;
		rt=newnode();
	}
	
	void insert(char s[]){
		int l=strlen(s);
		int nw=rt;
		for(int i=0;i<l;i++){
			if(tr[nw][s[i]-'a']==-1)
				tr[nw][s[i]-'a']=newnode();
			nw=tr[nw][s[i]-'a'];
		}
	}
	int getlen(){
		return L;
	}
	int getrt(){
		return rt;
	}
	int getnext(int x,char c){
		return tr[x][c-'a'];
	}
	
}t;

int cnt;
int ls[100100<<6],rs[100100<<6],tr[100100<<6];

int build(int l,int r){
	int nw=cnt++;
	if(l==r){
		tr[nw]=0;
		return nw;
	}
	int mid=l+r>>1;
	ls[nw]=build(l,mid);
	rs[nw]=build(mid+1,r);
	tr[nw]=0;
}

int add(int x,int v,int rt,int l,int r){
	int nw=cnt++;
	if(l==r){
		tr[nw]=tr[rt]+v;
		return nw;
	}
	int mid=l+r>>1;
	if(x<=mid) ls[nw]=add(x,v,ls[rt],l,mid),rs[nw]=rs[rt];
	else ls[nw]=ls[rt],rs[nw]=add(x,v,rs[rt],mid+1,r);
	tr[nw]=tr[ls[nw]]+tr[rs[nw]];
	return nw;
}

int query(int x,int rt,int l,int r){
	if(l==r) return tr[rt];
	int mid=l+r>>1;
	if(x<=mid) return tr[rs[rt]]+query(x,ls[rt],l,mid);
	else return query(x,rs[rt],mid+1,r);
}

char s[100100],str[100100];
int pre[100100];
int mytr[100100];
int len[100100];

int main(){
	int n,q;
	while(~scanf("%d",&n)){
		cnt=1;
		t.init();
//		sum[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%s",s);
			t.insert(s);
			len[i]=strlen(s);
			for(int j=0;j<len[i];j++)
				str[cnt++]=s[j];
//			sum[i]=sum[i-1]+len[i];
		}
		int l,r;
		cnt=0;
		mytr[0]=build(1,n);
		int ct=1;
		memset(pre,0,sizeof(pre));
		for(int i=1;i<=n;i++){
			//cout << i << endl;
			int tp=t.getrt();
			mytr[i]=add(i,len[i],mytr[i-1],1,n);
			for(int j=0;j<len[i];j++,ct++){
				tp=t.getnext(tp,str[ct]);
//				cout << str[ct] <<  " " << tp << endl;
				if(pre[tp]) mytr[i]=add(pre[tp],-1,mytr[i],1,n);
				pre[tp]=i;
			}
		}
		int ans=0;
		scanf("%d",&q);
		while(q--){
			scanf("%d%d",&l,&r);
//			cout << query(l+1,mytr[r+1],1,n) <<endl;
			l=(l+ans)%n+1;
			r=(r+ans)%n+1;
			if(l>r) swap(l,r);
			ans=query(l,mytr[r],1,n);
			printf("%d\n",ans);
		}
	}
}
