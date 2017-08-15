#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[110];

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		int sum=0;
		int ans=-1;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++){
			sum+=a[i];
			if(sum>=8){
				m-=8;
				sum-=8;
			}
			else{
				m-=sum;
				sum=0;
			}
			if(m<=0) {
				ans=i+1;
				break;
			}
		}
		cout << ans << endl;
	}
}
