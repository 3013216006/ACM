#include <iostream>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		int cnt=1;
		for(int i=0;i<n;i++){
			scanf("%s",s);
			for(int j=0;j<m;j++){
				if(s[i]=='*') a[i][j]=cnt++;
				else a[i][j]=0;
			}
		}
		int l=0,r=n*m,ans=0;
		while(l<=r){
		add(0,cnt,n*m);
		for(int i=1;i<=n;i++){
			add(cnt,i,4);
			add(i+cnt,cnt+cnt,4);
			for(j=1;j<m;j++)
				if(a[i][j]){
					if(a[i-1][j]) add(a[i][j],a[i-1][j]+cnt,1),add(a[i-1][j],a[i][j]+cnt,1);
					if(a[i][j-1]) add(a[i][j],a[i][j-1]+cnt,1),add(a[i][j-1],a[i][j]+cnt,1);
				}
		}
		}
	}
}
