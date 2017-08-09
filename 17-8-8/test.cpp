#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct Trie{
	int next[2000][2],fail[2000],end[2010];
	vector<int> v[2000];
	int root,L;
	int newnode(){
		for(int i=0;i<2;i++){
			next[L][i]=-1;
		}
		end[L++]=0;
		return L-1;
	}
	void init(){
		L = 0;
		root = newnode();
		for(int i=0;i<1000;i++)
			v[i].clear();
	}
	void insert(char buf[],int x){
		int l=strlen(buf);
		int now = root;
		for(int i=0;i<l;i++){
			if(next[now][buf[i]-'0']==-1)
				next[now][buf[i]-'0']=newnode();
			now = next[now][buf[i]-'0'];
		}
		end[now]++;
		v[now].push_back(x);
	}
	void build(){
		queue<int>Q;
		fail[root]=root;
		for(int i=0;i<2;i++)
			if(next[root][i]==-1)
				next[root][i]=root;
			else{
				fail[next[root][i]]=root;
				Q.push(next[root][i]);
			}
		while(!Q.empty()){
			int now=Q.front();
			Q.pop();
			for(int i=0;i<2;i++){
				if(next[now][i]==-1){
					next[now][i]=next[fail[now]][i];
				}
				else{
					fail[next[now][i]]=next[fail[now]][i];
					Q.push(next[now][i]);
				}
			}
		}
	}

	int query(char buf[],int &x){
		int len = strlen(buf);
		int now=root;
		int res=0;
		for(int i=0;i<len;i++){
			now=next[now][buf[i]-'0'];
			int temp=now;
			while(temp!=root){
				for(int j=0;j<v[temp].size();j++)
					if(v[temp][j]%2==0)
					res|=(1<<v[temp][j]/2);
				temp=fail[temp];
			}
		}
		x=now;
		return res;
	}
	int getnext(int x,int &y){
		y=next[y][x];
		int res=0;
		int temp=y;
		while(temp!=root){
			for(int j=0;j<v[temp].size();j++)
				res|=(1<<v[temp][j]/2);
			temp=fail[temp];
		}
		return res;
	}
	int getsum(){
		return L;
	}

};
char s[100];
void inv(){
	int l=strlen(s);
	for(int i=0;i<l/2;i++){
		swap(s[i],s[l-i-1]);
	}
}

Trie ac;

int dp[110][1<<8][200];
int mod=998244353;

int main(){
	int T;
	int n,l;
	scanf("%d",&T);
	while(T--){
		ac.init();
		scanf("%d%d",&n,&l);
		for(int i=0;i<n;i++){
			scanf("%s",s);
			ac.insert(s,i*2);
			inv();
			ac.insert(s,i*2+1);
		}
		ac.build();
		if(l<=20){
			int x=1<<l;
			int ans=0;
			int aaa;
			for(int i=0;i<x;i++){
				int tp=i;
				for(int i=0;i<l;i++){
					s[i]=tp%2+'0';
					tp/=2;
				}
				for(int i=0;i<l;i++){
					s[l+i]='1'-s[l-i-1]+'0';
				}
				s[l+l]='\0';
				if(ac.query(s,aaa)==(1<<n)-1) ans++;
			}
			cout << ans << endl;
		}
		else{
			memset(dp,0,sizeof(dp));
			int x=1<<10,aaa;
			for(int i=0;i<x;i++){
				int tp=i;
				for(int i=0;i<10;i++){
					s[i]=tp%2+'0';
					tp/=2;
				}
				for(int i=0;i<10;i++){
					s[l+i]='1'+'0'-s[l-i-1];
				}
				s[20]='\0';
				int tmp=ac.query(s,aaa);
				dp[10][tmp][aaa]++;
			}
			int y=1<<n;
			y--;
			int z=ac.getsum();
			for(int i=10;i<l;i++){
				for(int j=0;j<=y;j++){
					for(int k=0;k<=z;k++){
						int my1,my2=k;
						my1=ac.getnext(0,my2);
						dp[i+1][j|y][my2]+=dp[i][j][k];
						dp[i+1][j|y][my2]%=mod;

						my2=k;
						my1=ac.getnext(1,my2);
						dp[i+1][j|y][my2]+=dp[i][j][k];
						dp[i+1][j|y][my2]%=mod;
					}
				}
			}
			long long ans=0;
				for(int j=0;j<=z;j++)
					ans+=dp[l][y][j];
			ans%=mod;
			cout << ans << endl;
		}
	}
}
