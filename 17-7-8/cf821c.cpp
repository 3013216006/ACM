#include <iostream>
#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[600002],mark[300002];
char s[1000];

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n*2;i++){
			scanf("%s",s);
			if(s[0]=='a') scanf("%d",&a[i]);
			else a[i]=0;
		}
		int ans=0;
		int l=n;
		stack<int> S;
		memset(mark,0,sizeof(mark));
		while(!S.empty()) S.pop();
		for(int i=n*2-1;i>=0;i--){
			if(a[i]){
				if(mark[a[i]]&&S.empty()) continue;
				if(a[i]!=S.top()){
					ans++;
					while(!S.empty()){
						mark[S.top()]=1;
						S.pop();
					}
				}
				else{
					S.pop();
				}
			}
			else{
				S.push(l--);
			}
		}
		cout << ans << endl;
	}
}
