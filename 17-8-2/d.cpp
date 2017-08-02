#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define eps 1e-9
using namespace std;
const int MAXN=10;

double a[MAXN][MAXN],x[MAXN];
int equ,var;
double v[MAXN];

int _is(double x,int i){
	if(fabs(x-v[i])<1e-5) return 1;
	return 0;
}

int Gauss(){
	int i,j,k,col,max_r;
	for(k=0,col=0;k<equ&&col<var;k++,col++){
		max_r=k;
		for(i=k+1;i<equ;i++)
			if(fabs(a[i][col])>fabs(a[max_r][col]))
				max_r=i;
		if(fabs(a[max_r][col])<eps) return 0;
		if(k!=max_r){
			for(j=col;j<var;j++)
				swap(a[k][j],a[max_r][j]);
			swap(x[k],x[max_r]);
		}
		x[k]/=a[k][col];
		for(j=col+1;j<var;j++) a[k][j]/=a[k][col];
		a[k][col]=1;
		for(i=0;i<equ;i++)
			if(i!=k){
				x[i]-=x[k]*a[i][k];
				for(j=col+1;j<var;j++) a[i][j]-=a[k][j]*a[i][col];
				a[i][col]=0;
			}
	}
	return 1;
}

int n;
int getans(){
	equ=n+1,var=n+1;
	for(int i=0;i<=n+2;i++){
		for(int j=i+1;j<=n+2;j++){
			int cnt=0;
			for(int k=0;k<=n+2;k++){
				if(k==i||k==j) continue;
				double tmp=1;
				for(int l=0;l<=n;l++){
					a[cnt][l]=tmp;
					tmp*=k;
				}
				x[cnt++]=v[k];
			}
			if(Gauss()){
				double tmpi=1,tmpj=1;
				double ansi=0,ansj=0;
				for(int l=0;l<=n;l++){
					ansi+=tmpi*x[l];
					ansj+=tmpj*x[l];
					tmpi*=i;
					tmpj*=j;
				}
				if(_is(ansi,i)){
					return j;
				}
				else{
					if(_is(ansj,j)) return i;
				}
			}

		}
	}
	return -1;
}

int main(){
	while(~scanf("%d",&n),n){
		for(int i=0;i<=n+2;i++){
			scanf("%lf",&v[i]);
		}
		cout << getans() << endl;
	}
}
