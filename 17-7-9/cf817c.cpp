#include <iostream>
using namespace std;

int pan(long long a,long long b){
	long long ret=a;
	while(a){
		ret-=a%10;
		a/=10;
	}
	if(ret<b) return 0;
	else return 1;
}
int main(){
	long long a,b;
	while(cin >> a >> b){
		long long ans=max(0ll,a-200-b+1);
		for(long long i=b;i<min(b+200,a+1);i++){
			if(pan(i,b)) ans++;
		}
		cout << ans << endl;
	}
}
