#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
long long sum[110][110][15];

int main(){
	int n,q,c,x,y,s,xx,yy,t;
	while(~scanf("%d%d%d",&n,&q,&c)){
		memset(sum,0,sizeof(sum));
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&x,&y,&s);
			for(int j=0;j<=c;j++){
				sum[x][y][j]+=s++;
				if(s>c) s=0;
			}
		}
		for(int t=0;t<=c;t++){
			for(int i=0;i<=100;i++)
				for(int j=1;j<=100;j++)
					sum[i][j][t]+=sum[i][j-1][t];
			for(int j=0;j<=100;j++)
				for(int i=1;i<=100;i++)
					sum[i][j][t]+=sum[i-1][j][t];
		}
		for(int i=0;i<q;i++){
			scanf("%d%d%d%d%d",&t,&x,&y,&xx,&yy);
			t=t%(c+1);
			printf("%lld\n",sum[xx][yy][t]-sum[x-1][yy][t]-sum[xx][y-1][t]+sum[x-1][y-1][t]);
		}
	}
}
