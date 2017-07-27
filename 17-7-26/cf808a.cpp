#include <iostream>
using namespace std;

int main(){
	long long n;
	cin >> n;
	long long x=n,p=0;
	while(x){
		p=x%10;
		x/=10;
	}
	p++;
	while(p<n) p*=10;
	cout << p-n << endl;
}
