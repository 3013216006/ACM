#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			int id=0;
			for(int i=0;i<6;i++){
				scanf("%d",&a[i]);
				if(a[i]<a[id]) id=i;
			}
			int l=(id-1+6)%6;
			int r=(id+1)%6;
			if(a[l]<=a[r]){
				for(int i=id,j=0;j<6;j++,i--){
					if(i<0) i+=6;
				}
			}
			if(a[l]>=a[r]){
				
				for(int i=id,j=0;j<6;j++,i++){
					if(i>=6) i-=6;

				}
			}
		}
	}
}
