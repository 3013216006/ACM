#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

bool _isup(char x){
	if(x>='A'&&x<='Z') return true;
	else return false;
}

char s[1000];
int main(){
	int n;
	while(~scanf("%d",&n)){
		gets(s);
		gets(s);
		int ans=0;
		for(int i=0;i<n;i++){
			int tmp=0;
			while(i<n&&s[i]!=' '){
				if(_isup(s[i])) tmp++;
				i++;
			}
			ans=max(ans,tmp);
		}
		cout << ans << endl;
	}
}
