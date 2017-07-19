#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
double sum=0;
int all;
double x1;
int a[100];
int dfs(int x,int y){
	int ret=0;
	if(y==0){
		if(x!=0) return 0;
		for(int i=1;i<=all;i++){
			double tmp=a[i]-x1;
			sum+=tmp*tmp;
			cout << a[i] << endl;
		}
		cout << endl;
		return 1;
	}
	for(int i=0;i<=x;i++){
		a[y]=i;
		ret+=dfs(x-i,y-1);
	}
	return ret;
}

void getans(int n,int m){
	sum=0;
	all=m;
	x1=(double) (n)/m;
	cout << n << " " << m << endl;
	cout << dfs(n,m)*m << endl;
	cout << sum << endl;
	cout << endl;
}

int main(){
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			getans(i,j);
}
