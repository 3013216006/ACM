#include <iostream>
#include <stdio.h>
using namespace std;

int _is(int x){
	if(x%400==0) return 1;
	if(x%4==0&&x%100) return 1;
	return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int y,m,d;
		scanf("%d-%d-%d",&y,&m,&d);
		if(m==2&&d==29){
			long long sum=0;
			while(true){
				if(_is(y+4)){
					y+=4;
					sum+=4*365;
				}
				else
					y+=8,sum+=8*365;
				sum++;
				if(sum%7==0) break;
			}
		}
		else if(m<=2){
			int sum=0;
			while(true){
				sum+=365+_is(y);
				y++;
				if(sum%7==0) break;
			}
		}
		else{
			int sum=0;
			while(true){
				y++;
				sum+=365+_is(y);
				if(sum%7==0) break;
			}
		}
		cout << y << endl;
	}
}
