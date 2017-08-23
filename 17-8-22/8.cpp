#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[125550],ans[125550];
int l,r;
map<int,int> M;


int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		l=0,r=0;
		ans[l++]=a[r++];
		ans[l++]=a[r++];
		M.clear();
		M[ans[0]+ans[1]]=1;
		for(int i=r;i<n;i++){
			if(M.count(a[i])>0){
				if(M[a[i]]!=0) M[a[i]]--;
				else{
					ans[l]=a[i];
					for(int j=0;j<l;j++)
						M[a[i]+ans[j]]++;
					l++;
				}
			}
				else{
					ans[l]=a[i];
					for(int j=0;j<l;j++)
						M[a[i]+ans[j]]++;
					l++;
				}
			
		}
		cout << l << endl;
		for(int i=0;i<l;i++)
			printf("%d%c",ans[i]," \n"[i==l-1]);

	}
}
