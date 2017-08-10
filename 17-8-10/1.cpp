#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
int sum[100010];
struct Trie{
	int next[600010][28],fail[600010];
	int v[600010];
	int rt,L; 
	int to;
	int newnode(){ 
		for(int i=0;i<28;i++)
			next[L][i]=-1;
		v[L++]=-1;
		return L-1;
	}
	void init(){
		L=0;
		to=0;
		rt=newnode();
	}
	int insert(char buf[]){
//		cout << "insert: " <<  buf << endl;
		int len=strlen(buf);
		int now=rt;
		for(int i=0;i<len;i++){
			if(next[now][buf[i]-'a'] == -1)
				next[now][buf[i]-'a'] = newnode();
			now = next[now][buf[i]-'a'];
		}
		if(v[now]==-1) v[now]=to++;
		return v[now];
	}
	void build(){
		queue<int>Q;
		fail[rt] = rt;
		for(int i=0;i<28;i++)
			if(next[rt][i]==-1)
				next[rt][i]=rt;
			else{
				fail[next[rt][i]] = rt;
				Q.push(next[rt][i]);
			}
		while(!Q.empty()){
			int nw=Q.front();
			Q.pop();
			for(int i=0;i<28;i++)
				if(next[nw][i]==-1)
					next[nw][i]=next[fail[nw]][i];
				else{
					fail[next[nw][i]]=next[fail[nw]][i];
					Q.push(next[nw][i]);
				}
		}
	}
}t;
int ans[100010],a[100010],n,m;
int ma[100100];
int query(char buf[]){
	//cout << "query: " << buf << endl;
	int len=strlen(buf);
	int nw=t.rt;
	int my=0;
	for(int i=0;i<len;i++){
		if(buf[i]=='a'+27) my++;
		nw=t.next[nw][buf[i]-'a'];
		int temp=nw;
		while(temp!=t.rt){
			if(t.v[temp]!=-1) if(sum[t.v[temp]]<=a[my]) ans[t.v[temp]]++;
			temp=t.fail[temp];
		}
	}
}
char s1[100010],s2[100010],s3[200010],s[100010],sav[1300010];
void gets2(char s1[],char s2[]){
	int l1=strlen(s2),l2=strlen(s1);
	for(int i=0;i<l1;i++){
		s3[i]=s2[i];
	}
	s3[l1]='a'+26;
	for(int i=0;i<l2;i++){
		s3[i+l1+1]=s1[i];
	}
	s3[l1+l2+1]='\0';
}

int main(){
	time_t st=clock();
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		int l=0;
		for(int i=0;i<n;i++){
			scanf("%s",s);
			a[i]=strlen(s);
			for(int j=0;j<a[i];j++)
				sav[l++]=s[j];
			sav[l++]='a'+26;
			for(int j=0;j<a[i];j++)
				sav[l++]=s[j];
			sav[l++]='a'+27;
		}
		sav[l++]='\0';
		t.init();
		for(int i=0;i<m;i++){
			scanf("%s%s",s1,s2);
			gets2(s1,s2);
			ma[i]=t.insert(s3);
			sum[ma[i]]=strlen(s1)+strlen(s2);
		}
		t.build();
		l=0;
		memset(ans,0,sizeof(ans));
		//for(int i=0;i<n;i++)
			//cout << a[i] << endl;
		/*
		for(int i=0;i<n;i++){
			for(int j=0;j<a[i];j++)
				s1[j]=sav[l++];
			s1[a[i]]='\0';
			gets2(s1,s1);
			query(s3);
		}
		*/
		query(sav);
		for(int i=0;i<m;i++)
			printf("%d\n",ans[ma[i]]);
	}
	time_t ed=clock();
//	cout << (ed-st)/CLOCKS_PER_SEC;
}
