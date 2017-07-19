#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char s[100];
int a[400010];
int main(){
	int T,n,k,cas=1;
	scanf("%d",&T);
	while(T--){
		printf("Case #%d:\n",cas++);
		scanf("%d",&n);
		int l=0,r=-1,t=1,x=200001,y=200000;
		for(int i=0;i<n;i++){
			scanf("%s",s);
			if(s[0]=='P'){
				if(s[1]=='O'){
					if(l<=r){
						if(t){
							if(x<=y&&a[y]==r) y--;
							r--;
						}
						else{
							if(x<=y&&a[x]==l) x++;
							l++;
						}
					}
				}
				else{
					scanf("%d",&k);
					k=1-k;
					if(t){
						r++;
						if(k){
							y++;
							a[y]=r;
						}
					}
					else{
						l--;
						if(k){
							x--;
							a[x]=l;
						}
					}
				}
			}
			else if(s[0]=='R'){
				t=t^1;
			}
			else{
				if(l>r) puts("Invalid");
				else
				if(t){
					int tmp;
					if(x>y){
						tmp=r-l+1;		
					}
					else if(a[y]==l){
						tmp=r-l;
					}
					else{
						tmp=r-a[y]+1;
					}
					if(tmp%2) puts("1");
						else puts("0");
				}
				else{
					int tmp;
					if(x>y){
						tmp=r-l+1;
					}
					else if(a[x]==r){
						tmp=r-l;
					}
					else{
						tmp=a[x]-l+1;
					}
					printf("%d\n",tmp%2);
				}
			}
		}
	}
}
