#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
queue<int> Q;

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		int ans=0;
		if(m==2){
			ans=n-1;
			cout << ans << endl;
			for(int i=1;i<n;i++)
				cout << i << " " << i+1 << endl;
		}
		else{
			int t=n/m;
			t--;
			if(n%m<=1){
				ans=t+t+2;
			}
			else if(n%m==2) ans=t+t+3;
			else ans=t+t+4;
			cout << ans << endl;
			t=1;
			while(t+m<=n) cout << t << " " << t+m << endl,t+=m; 
			for(int i=2;i<=m;i++){
				int j=i;
				while(j+m<=n) cout << j << " " << j+m << endl,j+=m;
				cout << t <<  " " << j << endl;
			}
		}
	}
}
