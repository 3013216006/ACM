#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[510][510];

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++)
			scanf("%s",s[i]);
		int flag=1;
		int lmi=n,rmi=m,lmx=-1,rmx=-1;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(s[i][j]=='X'){
					lmi=min(i,lmi);
					lmx=max(i,lmx);
					rmi=min(j,rmi);
					rmx=max(j,rmx);
				}
//				cout << lmi << " " << lmx << " " << rmi << " " << rmx << endl;
		for(int i=lmi;i<=lmx&&flag;i++)
			for(int j=rmi;j<=rmx&&flag;j++)
				flag=s[i][j]=='X';
		if(flag) puts("YES");
		else puts("NO");
	}
}
