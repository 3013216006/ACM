#include <iostream>
using namespace std;

int main(){
	cout << 1 << endl;
	cout << 60000 << endl;
	int tmp=1<<20;
	tmp--;
	for(int i=0;i<60000;i++)
		cout << tmp-i << " ";
	cout << endl;
	cout << tmp-1 << " " ;
	for(int i=1;i<60000;i++)
		cout << tmp-i << " ";
	cout << endl;
}
