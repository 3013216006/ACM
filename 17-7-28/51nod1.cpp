#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;
stack<int> S;
char s[1100001];


int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		while(!S.empty()) S.pop();
		scanf("%s",s);
		int l=strlen(s);
		long long ans=0;
		int sum=0;
		for(int i=0;i<l;i++){
			if(s[i]=='(') S.push(0);
			else if(!S.empty()){
				S.pop();
				int tmp;
				if(!S.empty()){
					tmp=S.top();
					S.pop();
					tmp++;
					ans+=tmp;
					S.push(tmp);
				}
				else{
					sum++;
					ans+=sum;
				}
			}
			else sum=0;
			
		}
		printf("%lld\n",ans);
	}
}
