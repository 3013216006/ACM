#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char s[100][100];
struct Node{
	int x,y;
}to[10];

void init(){
	to[0].x=1,to[0].y=1;
	to[1].x=1,to[1].y=-1;
	to[2].x=1,to[2].y=0;
	to[3].x=0,to[3].y=1;
}

int _is(int x,int y){
	if(x<0||y<0||x>=10||y>=10) return 0;
	if(s[x][y]=='X') return 1;
	return 0;
}

int pan(int x,int y){
	for(int i=0;i<4;i++){
		int sum=0;
		for(int j=1;j<5;j++)
			if(_is(x+to[i].x*j,y+to[i].y*j)) sum++;
			else break;
		for(int j=1;j<5;j++)
			if(_is(x-to[i].x*j,y-to[i].y*j)) sum++;
			else break;
		if(sum>=4) return 1;
	}
	return 0;
}

int main(){
	init();
	for(int i=0;i<10;i++){
		scanf("%s",s[i]);
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)
		if(s[i][j]=='.'){
			if(pan(i,j)){
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}
