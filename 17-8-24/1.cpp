#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
map<long long,int> M;
int a[100],b[10][10];
int x,y;
struct Node{
	long long f;
	int sum;
	int x,x1,y;
	Node(){}
	Node(long long _f,int _x,int _sum,int _x1,int _y){
		f=_f,sum=_sum,x=_x,x1=_x1,y=_y;
	}
	friend bool operator<(Node a,Node b){
		return a.sum/2+a.sum%2+a.x>b.sum/2+b.sum%2+b.x;
	}
};
priority_queue<Node> Q;
int sum,ans;
long long ed;
int add(int x,int x1,int y){
	if(sum/2+sum%2+x>20) return 0;
	long long tp=0;
	int l=0;
	for(int i=5;i>=0;i--){
		for(int j=i;j>=0;j--){
			tp=tp*6+b[i][j];
		}
	}
	if(tp==ed){
		ans=x;
		return 1;
	}
	else{
		if(M.count(tp)==0){
			M[tp]=1;
			Q.push(Node(tp,x,sum,x1,y));
		}
		return 0;
	}
}

int myabs(int x){
	if(x<0) return -x;
	else return x;
}


int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		sum=0;
		int l=0;
		for(int i=0;i<=5;i++)
		for(int j=0;j<=i;j++,l++){
			scanf("%d",&a[l]);
			sum+=myabs(a[l]-i);
			if(a[l]==0) x=i,y=j;
		}
		long long tp=0;
		for(int i=20;i>=0;i--)
			tp=tp*6+a[i];
		ed=0;
		sort(a,a+21);
		for(int i=20;i>=0;i--)
			ed=ed*6+a[i];
		while(!Q.empty()) Q.pop();
		Q.push(Node(tp,0,sum,x,y));
		ans=-1;
		M.clear();
		M[tp]=1;
		if(tp==ed) {puts("0");continue;}
		while(!Q.empty()){
			Node tmp=Q.top();
			Q.pop();
			tp=tmp.f;
			for(int i=0;i<=5;i++){
				for(int j=0;j<=i;j++){
					b[i][j]=tp%6;
					tp/=6;
					if(b[i][j]==0) x=i,y=j;
				}
			}
//			for(int i=0;i<=5;i++){
//				for(int j=0;j<=i;j++){
//					printf("%d%c",b[i][j]," \n"[j==i]);
//				}
//			}
			x=tmp.x1;
			y=tmp.y;
			sum=tmp.sum;
			if(x-1>=0){
				if(y-1>=0){
					sum-=myabs(b[x][y]-x);
					sum-=myabs(b[x-1][y-1]-x+1);
					swap(b[x][y],b[x-1][y-1]);
					sum+=myabs(b[x][y]-x);
					sum+=myabs(b[x-1][y-1]-x+1);
					
					if(add(tmp.x+1,x-1,y-1)) break;
					
					sum-=myabs(b[x][y]-x);
					sum-=myabs(b[x-1][y-1]-x+1);
					swap(b[x][y],b[x-1][y-1]);
					sum+=myabs(b[x][y]-x);
					sum+=myabs(b[x-1][y-1]-x+1);
					
				}
				if(y<=x-1){
					sum-=myabs(b[x][y]-x);
					sum-=myabs(b[x-1][y]-x+1);
					swap(b[x][y],b[x-1][y]);
					sum+=myabs(b[x][y]-x);
					sum+=myabs(b[x-1][y]-x+1);
					
					if(add(tmp.x+1,x-1,y)) break;
					
					sum-=myabs(b[x][y]-x);
					sum-=myabs(b[x-1][y]-x+1);
					swap(b[x][y],b[x-1][y]);
					sum+=myabs(b[x][y]-x);
					sum+=myabs(b[x-1][y]-x+1);
				}
			}
			if(x+1<=5){
					sum-=myabs(b[x][y]-x);
					sum-=myabs(b[x+1][y]-x-1);
					swap(b[x][y],b[x+1][y]);
					sum+=myabs(b[x][y]-x);
					sum+=myabs(b[x+1][y]-x-1);
					
					if(add(tmp.x+1,x+1,y)) break;
					
					sum-=myabs(b[x][y]-x);
					sum-=myabs(b[x+1][y]-x-1);
					swap(b[x][y],b[x+1][y]);
					sum+=myabs(b[x][y]-x);
					sum+=myabs(b[x+1][y]-x-1);
					
					sum-=myabs(b[x][y]-x);
					sum-=myabs(b[x+1][y+1]-x-1);
					swap(b[x][y],b[x+1][y+1]);
					sum+=myabs(b[x][y]-x);
					sum+=myabs(b[x+1][y+1]-x-1);
					
					if(add(tmp.x+1,x+1,y+1)) break;
					
					sum-=myabs(b[x][y]-x);
					sum-=myabs(b[x+1][y+1]-x-1);
					swap(b[x][y],b[x+1][y+1]);
					sum+=myabs(b[x][y]-x);
					sum+=myabs(b[x+1][y+1]-x-1);
			}
		}
		if(ans==-1) puts("too difficult");
		else cout << ans << endl;
	}
}
