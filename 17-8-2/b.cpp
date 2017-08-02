#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int x,y,z,v;
	Node(){}
	Node(int _x,int _y,int _z,int _v){
		x=_x,y=_y,z=_z,v=_v;
	}
}a[100],ans[8000];
int pan(int x,int y,int z,int n){
	for(int i=0;i<n;i++){
		if(a[i].v!=x*a[i].x+y*a[i].y+z*a[i].z) return 0;
	}
	return 1;
}

int getans(int x,int y,int z,int cnt){
	int	tmp=x*ans[0].x+y*ans[0].y+z*ans[0].z;
	for(int i=1;i<cnt;i++){
//		cout << i << "/" << cnt << endl;
//		cout << tmp << " " << x*ans[i].x+y*ans[i].y+z*ans[i].z << endl;	
		if(tmp!=x*ans[i].x+y*ans[i].y+z*ans[i].z) return -1;	
	}
	return tmp;

}
char s[1000000];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m),n||m){
		int l,v,x=0,y=0,z=0,cnt=0,j;
		for(int i=0;i<n;i++){
			scanf("%s",s);
			l=strlen(s);
			j=0;
			v=0;
			while(s[j]=='.') v++,j++;
//			cout << x << " " << y << " " << z << " " << v << endl;
			a[i].x=x,a[i].y=y,a[i].z=z,a[i].v=v;
			for(;j<l;j++){
				if(s[j]=='(') x++;
				else if(s[j]==')') x--;
				else if(s[j]=='[') y++;
				else if(s[j]==']') y--;
				else if(s[j]=='{') z++;
				else if(s[j]=='}') z--;
			}
		}
		for(int i=1;i<=20;i++)
			for(int j=1;j<=20;j++)
				for(int k=1;k<=20;k++){
					if(pan(i,j,k,n)) ans[cnt++]=Node(i,j,k,0);
				}
//		for(int i=0;i<cnt;i++){
//			cout << i << ":" << ans[i].x << " " << ans[i].y << " " << ans[i].z << endl;
//		}
		x=0,y=0;z=0;
		for(int i=0;i<m;i++){
//			cout << x << " " << y << " " << z << endl;
			scanf("%s",s);
			l=strlen(s);
			if(i) printf(" ");
			printf("%d",getans(x,y,z,cnt));
			for(int j=0;j<l;j++){
				if(s[j]=='(') x++;
				else if(s[j]==')') x--;
				else if(s[j]=='[') y++;
				else if(s[j]==']') y--;
				else if(s[j]=='{') z++;
				else if(s[j]=='}') z--;
			}
		}
		puts("");
	}
}
