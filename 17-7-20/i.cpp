#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int a[4][10][10];
void init();
int ct=1;
void print(int n){
	for(int i=0;i<n;i++){
		int x=ct+9;
		for(int j=1;j<=8;j++){
			printf("%d",ct+a[2][j][1]);
			for(int k=2;k<=j;k++)
				printf(" %d",ct+a[2][j][k]);
			for(int k=0;k<i;k++){
				x++;
				for(int z=0;z<4;z++)
					printf(" %d",x);
				x++;
				for(int z=0;z<4;z++)
					printf(" %d",x);
			}
			puts("");
		}
		ct=x;
	}
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	ct=0;
	while(T--){
		int n;
		scanf("%d",&n);
		if(n%8==0){
			print(n/8);
		}
		else if(n%8==7){
			print(n/8);
			int x=ct+7;
			int l=n/8;
			for(int j=1;j<=7;j++){
				printf("%d",ct+a[1][j][1]);
				for(int k=2;k<=j;k++)
					printf(" %d",ct+a[1][j][k]);
				for(int k=0;k<l;k++){
					x++;
					for(int z=0;z<4;z++)
						printf(" %d",x);
					x++;
					for(int z=0;z<4;z++)
						printf(" %d",x);
				}
				puts("");
			}
		}
		else puts("-1");
	}
}

void init(){
a[1][1][1]=1;
a[1][2][1]=1;
a[1][2][2]=2;
a[1][3][1]=1;
a[1][3][2]=2;
a[1][3][3]=2;
a[1][4][1]=1;
a[1][4][2]=3;
a[1][4][3]=2;
a[1][4][4]=4;
a[1][5][1]=3;
a[1][5][2]=3;
a[1][5][3]=3;
a[1][5][4]=4;
a[1][5][5]=4;
a[1][6][1]=5;
a[1][6][2]=5;
a[1][6][3]=6;
a[1][6][4]=4;
a[1][6][5]=7;
a[1][6][6]=7;
a[1][7][1]=5;
a[1][7][2]=5;
a[1][7][3]=6;
a[1][7][4]=6;
a[1][7][5]=6;
a[1][7][6]=7;
a[1][7][7]=7;
a[2][1][1]=1;
a[2][2][1]=1;
a[2][2][2]=2;
a[2][3][1]=1;
a[2][3][2]=2;
a[2][3][3]=2;
a[2][4][1]=1;
a[2][4][2]=2;
a[2][4][3]=3;
a[2][4][4]=3;
a[2][5][1]=5;
a[2][5][2]=4;
a[2][5][3]=4;
a[2][5][4]=3;
a[2][5][5]=3;
a[2][6][1]=5;
a[2][6][2]=5;
a[2][6][3]=4;
a[2][6][4]=8;
a[2][6][5]=8;
a[2][6][6]=8;
a[2][7][1]=6;
a[2][7][2]=5;
a[2][7][3]=4;
a[2][7][4]=7;
a[2][7][5]=7;
a[2][7][6]=8;
a[2][7][7]=9;
a[2][8][1]=6;
a[2][8][2]=6;
a[2][8][3]=6;
a[2][8][4]=7;
a[2][8][5]=7;
a[2][8][6]=9;
a[2][8][7]=9;
a[2][8][8]=9;
}
