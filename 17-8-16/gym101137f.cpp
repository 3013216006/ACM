#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cstring>
using namespace std;
int vis[1000];
vector<pair<int,int> > v1,v2;

void print1(){
	cout << "%[";
	for(int i=0;i<v1.size();i++){
		if(i+1<v1.size()){
			if(v1[i].first==v1[i+1].first) continue;
		}
		if(v1[i].second-v1[i].first==0){
			printf("%c",v1[i].first);
		}
		else if(v1[i].second-v1[i].first==1){
			printf("%c%c",v1[i].first,v1[i].second);
		
		}
		else{
			printf("%c-%c",v1[i].first,v1[i].second);
		}
	}
	printf("]\n");
}

void print2(){
	cout << "%[^" ;
	if(v2.size()==0) cout << "!";
	for(int i=0;i<v2.size();i++){
		if(i+1<v2.size()){
			if(v2[i].first==v2[i+1].first) continue;
		}
		if(v2[i].second-v2[i].first==0){
			printf("%c",v2[i].first);
		}
		else if(v2[i].second-v2[i].first==1){
			printf("%c%c",v2[i].first,v2[i].second);
		
		}
		else{
			printf("%c-%c",v2[i].first,v2[i].second);
		}
	}
	printf("]\n");
}
char s[1000100];
int main(){
	while(gets(s)){
		int l=strlen(s);
		memset(vis,-1,sizeof(vis));
		vis[' ']=0;
		for(char i='0';i<='9';i++) vis[i]=0;
		for(char i='a';i<='z';i++) vis[i]=0;
		for(char i='A';i<='Z';i++) vis[i]=0;
		vis[' '-1]=0;
		for(int i=0;i<l;i++) vis[s[i]]=1;
		v1.clear(),v2.clear();
		for(int i=32;i<='z';i++){
			if(vis[i]==1){
				int r=i;
				int sum=1;
				while(vis[r+1]==1) r++,sum++;
				int l=i;
				while(vis[l-1]!=0) l--,sum+=vis[l]==1?1:0;
				//cout << l << endl;
				//cout << i << " " << sum << endl;
				if(sum>=3){
					v1.push_back(make_pair(l,r));
				}
				else{
					v1.push_back(make_pair(i,r));
				}
				i=r;
			}
		}
		for(int i=32;i<='z';i++){
			if(vis[i]==0){
				int r=i;
				int sum=1;
				while(vis[r+1]==0) r++,sum++;
				int l=i;
				while(l-1>=32&&vis[l-1]<=0) l--,sum+=vis[l]==0?1:0;
				if(sum>=3){
					v2.push_back(make_pair(l,r));
				}
				else{
					v2.push_back(make_pair(i,r));
				}
				i=r;
			}
		}
		int l1=0,l2=0;
		for(int i=0;i<v1.size();i++){
			if(i+1<v1.size()){
				if(v1[i].first==v1[i+1].first) continue;
			}
			if(v1[i].second-v1[i].first>=2) l1+=3;
			else l1+=(v1[i].second-v1[i].first+1);
		}
		for(int i=0;i<v2.size();i++){
			if(i+1<v2.size()){
				if(v2[i].first==v2[i+1].first) continue;
			}
			if(v2[i].second-v2[i].first>=2) l2+=3;
			else l2+=(v2[i].second-v2[i].first+1);
		}
		l2++;
		if(l2<l1){
			print2();
		}
		else
		if(l2==l1){
			if(v1[0].first>='^'){
	//	if(v1[0].first>=v2[0].first){
				print2();
			}
			else{
				print1();
			}
		}
		else{
			print1();
		}
	}
}
