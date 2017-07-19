#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Node{
	int x,y;
}a[1010];
bool cmp(Node a,Node b){
	return a.x<b.x;
}
int main(){
	int T,cas=1,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i].x);
			a[i].y=i;
		}
		sort(a+1,a+n+1,cmp);
		int sum=0;
		for(int i=1;i<=n;i++)
			if(a[i].x<i){
				sum+=a[i].x;
			}
			else {sum=-1;break;}
		printf("Case #%d: ",cas++);
		if(sum<0) puts("No");
		else{
			puts("Yes");
			printf("%d\n",sum);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=a[i].x;j++)
					printf("%d %d\n",a[i].y,a[j].y);
		}
	}
}
