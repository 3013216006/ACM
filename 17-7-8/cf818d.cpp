#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[100001],s[100001],ans[100001];
int main(){
	int n,A;
	while(~scanf("%d%d",&n,&A)){
		int l=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]==A) l++;
			s[i]=l;
		}
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;i++)
		if(ans[a[i]]!=-1){
			ans[a[i]]++;
			if(ans[a[i]]<=s[i]) ans[a[i]]=-1;
		}
		int out=-1;
		for(int i=0;i<n;i++)
			if(ans[a[i]]>=l){
				out=a[i];
				break;
			}
		cout << out << endl;
	}
}
