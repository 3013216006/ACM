#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[150][150];

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++){
			scanf("%s",s[i]);
		}
		if(s[0][0]==s[0][m-1]){
			if(n%3){
				puts("No");
				continue;
			}
			else{
				int flag=1;
				for(int i=0;i<n/3&&flag;i++){
					for(int j=0;j<m&&flag;j++){
						if(s[i][j]!=s[0][0]) flag=0;
					}
				}
				for(int i=n/3;i<n/3*2&&flag;i++){
					for(int j=0;j<m&&flag;j++){
						if(s[n/3][0]!=s[i][j]) flag=0;
					}
				}
				for(int i=n/3*2;i<n&&flag;i++){
					for(int j=0;j<m&&flag;j++){
						if(s[n-1][0]!=s[i][j]) flag=0;
					}
				}
				if(flag){
					if(s[0][0]!=s[n/3][0]&&s[0][0]!=s[n-1][0]&&s[n/3][0]!=s[n-1][0]) puts("Yes");
					else puts("No");
				}
				else{
					puts("No");
					continue;
				}
			}
		}
		else{
			if(m%3){
				puts("No");
				continue;
			}
			else{
				int flag=1;
				for(int i=0;i<n&&flag;i++){
					for(int j=0;j<m/3&&flag;j++){
						if(s[0][0]!=s[i][j]) flag=0;
					}
				}
				for(int i=0;i<n&&flag;i++){
					for(int j=m/3;j<(m/3)*2;j++){
						if(s[0][m/3]!=s[i][j]) flag=0;
					}
				}
				for(int i=0;i<n&&flag;i++){
					for(int j=m/3*2;j<m;j++){
						if(s[0][m-1]!=s[i][j]) flag=0;
					}
				}
				if(flag){
					if(s[0][0]!=s[0][m/3]&&s[0][0]!=s[0][m-1]&&s[0][m/3]!=s[0][m-1]) puts("Yes");
					else puts("No");
				}else{
					puts("No");
				}
			}
		}
	}
}
