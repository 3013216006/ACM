#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;
map<int,int> M;
int lson[100000<<7],rson[100000<<7],tr[100000<<7];
int cnt;
int mytree[100010],a[100100];
struct Node{
	int x,y;
}b[100100];
bool cmp(Node a,Node b){
	return a.x<b.x;
}
int build(int l,int r){
	int nw=cnt++;
	if(l==r){
		tr[nw]=0;
		return nw;
	}
	int mid=l+r>>1;
	lson[nw]=build(l,mid);
	rson[nw]=build(mid+1,r);
	tr[nw]=tr[lson[nw]]+tr[rson[nw]];
	return nw;
}

int add(int x,int rt,int l,int r){
	int nw=cnt++;
	if(l==r){
		tr[nw]=tr[rt]+1;
		return nw;
	}
	int mid=l+r>>1;
	if(x<=mid) lson[nw]=add(x,lson[rt],l,mid),rson[nw]=rson[rt];
	else lson[nw]=lson[rt],rson[nw]=add(x,rson[rt],mid+1,r);
	tr[nw]=tr[lson[nw]]+tr[rson[nw]];
	return nw;
}

int query(int k,int rt1,int rt2,int l,int r){
	if(l==r) return l;
	int mid=l+r>>1;
	int t=tr[lson[rt1]]-tr[lson[rt2]];
	if(t>=k) return query(k,lson[rt1],lson[rt2],l,mid);
	else return query(k-t,rson[rt1],rson[rt2],mid+1,r);
}

void print(int rt,int l,int r){
	cout << "rt = " << rt << "   lson = " << lson[rt] << "  rson = " << rson[rt] << endl;
	cout << "tr = " << tr[rt] << " l = " << l << " r = " << r << endl; 
	if(l==r) return;
	int mid=l+r>>1;
	print(lson[rt],l,mid);
	print(rson[rt],mid+1,r);
}

int main(){
	int n,m;
	int x,y,k;
	while(~scanf("%d%d",&n,&m)){
		M.clear();
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			b[i].x=a[i];
			b[i].y=i+1;
		}
		sort(b,b+n,cmp);
		cnt=1;
		for(int i=0;i<n;i++){
			a[b[i].y]=i+1;
		}
		cnt=0;
		mytree[0]=build(1,n);
		for(int i=1;i<=n;i++){
			mytree[i]=add(a[i],mytree[i-1],1,n);
//			print(mytree[i],1,n);
//			puts("");
		}
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&k);
			printf("%d\n",b[query(k,mytree[y],mytree[x-1],1,n)-1].x);
		}

	}
}
