#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
struct Node{
	int x,y;
}a[100],b[100],c[10000];
int cnt;
void add(int x,int y){
	c[cnt].x=x;
	c[cnt].y=y;
	cnt++;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,x,y;
		scanf("%d%d%d%d",&n,&m,&x,&y);
		for(int i=0;i<x;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
		}
		for(int i=0;i<y;i++){
			scanf("%d%d",&b[i].x,&b[i].y);
		}
		int l=0,r=0;
		cnt=0;
		while(l<x&&r<y){
			if(a[l].x<=b[r].x){
				if(a[l].y<b[r].x) l++;
				else 
				if(a[l].y<=b[r].y){
					add(b[r].x,a[l].y);
					l++;
				}
				else{
					add(b[r].x,b[r].y);
					r++;
				}
			}
			else{
				if(b[r].y<a[l].x) r++;
				else if(a[l].y<=b[r].y){
					add(a[l].x,a[l].y);
					l++;
				}
				else{
					add(a[l].x,b[r].y);
					r++;
				}
			}
		}
		int ans=0;
		for(int i=0;i<cnt;i++){
			int tmp=c[i].y-c[i].x+1;
			if(tmp>=m) ans+=(tmp-m+1);
		}
		cout << ans << endl;
	}
}
