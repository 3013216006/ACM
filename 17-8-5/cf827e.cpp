#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	long long x,y;
	Node(){}
	Node(long long _x,long long _y){
		x=_x,y=_y;
	}
	friend bool operator<(Node a,Node b){
		if(a.y==b.y) return a.x<b.x;
		else return a.y<b.y;
	}
};

priority_queue<Node> Q;

int main(){
	long long n,m;
	while(~scanf("%lld%lld",&n,&m)){
		while(!Q.empty()) Q.pop();
		for(long long i=1;i*i<=n;i++)
		if(n%i==0){
			Q.push(Node(i,m/i*i));
			long long tp=n/i;
			Q.push(Node(tp,m/tp*tp));
		}
		long long ans=0;
		long long now=1;
		while(!Q.empty()){
			Node tmp=Q.top();
			Q.pop();
//			cout << tmp.x << " " << tmp.y << endl;
			ans+=(m-tmp.y)/now;
//			cout << "now = " << now << endl; 
			m=(m-tmp.y)%now+tmp.y;
			if(tmp.y==m) now=max(now,tmp.x);
//			cout << m << endl;
//			cout << now << endl;
//			cout << ans << endl << endl;
		}
		ans+=m/now;
		cout << ans << endl;
	}
}
