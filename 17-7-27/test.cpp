#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
vector<int> v;

int main(){
	for(int i=0;i<10;i++)
		v.push_back(i);
	for(int i=0;i<=10;i++){
		cout << lower_bound(v.begin(),v.end(),i)-v.begin() << endl;
	}
}
