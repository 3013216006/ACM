#include <iostream>
#include <bitset>
using namespace std;


int main(){
	bitset<5> a;
	for(int i=0;i<5;i++)
		a[i]=1;
	a.set(2,0);
	a.set(4,0);
	for(int i=0;i<5;i++)
		cout << a[i] << endl;
	a.set(2);
	cout << a << endl;
	cout <<  a.all() << endl;
	cout << a.any() << endl;
	cout << a.none() << endl;
}
