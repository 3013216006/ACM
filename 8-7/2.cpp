#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int x,y,a[1010];
int main(){
	int n;
	while(~scanf("%d",&n)){
		int tim=1,sum=0;
		int cnt=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			if(y) tim+=y-1,sum+=x;
				else a[cnt++]=x;
		}
		sort(a,a+cnt);
		if(cnt<=tim) tim=cnt;
		cnt--;
		for(int i=0;i<tim;i++){
			sum+=a[cnt];
			cnt--;
		}
		cout << sum << endl;
	}
}
