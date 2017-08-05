#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[100][100];
int main(){
	for(int l=0;l<10;l++){
		for(int i=0;i<7;i++){
			scanf("%s",s[i]);
		}
		for(int i=0;i<7;i++){
			for(int j=0;j<4;j++){
				printf("s[%d][%d][%d]=%c;\n",l,i,j,s[i][j]);
			}
		}
	}
}
