#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
char s[10][10],s1[10],c;
int l[5][5],r[5][5],ans[5][5];
int main(){
	int T;
	scanf("%d",&T);
	getchar();
	while(T--){
		int flag=0;
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		memset(ans,0,sizeof(ans));
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++){
				c=getchar();
				while(c!='.'&&c!='x'&&c!='o') c=getchar();
				s[i][j]=c;
			}
		scanf("%s",s1);
		getchar();
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(s[i][j]=='.') l[i][0]++,r[j][0]++;
				if(s[i][j]==s1[0]) l[i][1]++,r[j][1]++;
			}
		}
		for(int i=0;i<3;i++){
			if(l[i][0]==2&&l[i][1]==1){
				for(int j=0;j<3;j++)
					if(s[i][j]=='.') ans[i][j]++;
			}
			if(l[i][0]==1&&l[i][1]==2) flag=1;
			if(l[i][1]==3) flag=1;
			if(r[i][0]==2&&r[i][1]==1){
				for(int j=0;j<3;j++)
					if(s[j][i]=='.') ans[j][i]++;
			}
			if(r[i][0]==1&&r[i][1]==2) flag=1;
			if(r[i][1]==3) flag=1;
		}
		int ans0=0,ans1=0;
		for(int i=0;i<3;i++){
			if(s[i][i]=='.') ans0++;
			if(s[i][i]==s1[0]) ans1++;
		}
		if(ans0==1&&ans1==2) flag=1;
		if(ans1==3) flag=1;
		if(ans0==2&&ans1==1){
			for(int i=0;i<3;i++)
				if(s[i][i]=='.') ans[i][i]++;
		}
		ans0=0,ans1=0;
		for(int i=0;i<3;i++){
			if(s[i][2-i]=='.') ans0++;
			if(s[i][2-i]==s1[0]) ans1++;
		}
		if(ans0==1&&ans1==2) flag=1;
		if(ans1==3) flag=1;
		if(ans0==2&&ans1==1){
			for(int i=0;i<3;i++)
				if(s[i][2-i]=='.') ans[i][2-i]++;
		}
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if(ans[i][j]>=2) flag=1;
		if(flag) puts("Kim win!");
		else puts("Cannot win!");
	}
}
