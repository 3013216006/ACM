#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
int a[10][10];
int b[10][10];
int ans[10][10];

void init(){
b[0][0]=2;
b[0][1]=3;
b[0][2]=1;
b[0][3]=1;
b[1][0]=1;
b[1][1]=2;
b[1][2]=3;
b[1][3]=1;
b[2][0]=1;
b[2][1]=1;
b[2][2]=2;
b[2][3]=3;
b[3][0]=3;
b[3][1]=1;
b[3][2]=1;
b[3][3]=2;
}


int main(){
	int T;
	int l=16*16;
	init();
	scanf("%d",&T);
	int flag=0;
	while(T--){
	if(flag) puts("");
	flag=1;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				scanf("%x",&a[i][j]);
			}
		}
		memset(ans,0,sizeof(ans));
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				for(int k=0;k<4;k++){
					if(b[i][k]==1)
						ans[i][j]^=a[k][j];
					else{ 
						int tmp=a[k][j]<<1;
						if(tmp>=l) tmp-=l,tmp^=0x1b;
					if(b[i][k]==2)
						ans[i][j]^=tmp;
					else 
						ans[i][j]^=a[k][j]^tmp;
					}
				}
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				printf("%02X%c",ans[i][j]," \n"[j==3]);
		
	}
}
