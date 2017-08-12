#include <iostream>
using namespace std;

int main(){
	int n,m;
	while(~scanf("%d",&n)){
		for(int i=0;i<=100000;i++)
			fa2[i]=fa1[i]=i;
		M.clear();
		int ansl=0;
		v.clear();
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&x,&y,&z);
			ans[ansl]++;
			int fax1=find1(x),fay1=find1(y),fax2=find2(x),fay2=find2(y);
			if(M.count(x)>0); else v.push_pack(x),M[x]=1;
			if(M.count(y)>0); else v.push_pack(y),M[y]=1;
			if(z){
				if(fax2==fay2){
					if(fax1!=fay1){
						ansl++;
						init();
					}
				}
				else{
					fa2[fax2]
				}
			}
			else{
			}
		}
	}
}
