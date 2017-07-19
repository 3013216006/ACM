#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int num[10],f,next;
}q[100];
int head[1500],cnt;
char s[1500];
int a[1000],b[1000];
Node work(int &l){
	int r=0;
	Node tmp;
	for(int i=0;i<10;i++) tmp.num[i]=0;
	tmp.f=0;
	for(int i=0;i<l;i++){
		if(a[i]==0) a[i]=10,r++;
		else{
			tmp.f|=(1<<a[i]);
			tmp.num[a[i]]++;
		}
	}
	sort(a,a+l);
	l-=r;
	return tmp;
}

void print(int l){
	for(int i=0;i<l;i++)
		printf("%d",a[i]);
	puts("");
}

int  getnext(int l){
	a[l]=0;a[l+1]=0;
	for(int i=0;i<l;i++)
		b[l-1-i]=a[i];
	for(int i=0;i<l;i++){
		a[i]=a[i]+b[i];
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	while(a[l]) l++;
	return l;
}


int main(){
	int n,cas,T,m;
	scanf("%d",&T);
	while(T--){
		memset(head,-1,sizeof(head));
		cnt=0;
		scanf("%d%d%s",&cas,&n,s);
		m=n;
		int l=strlen(s);
		for(int i=0;i<l;i++)
			a[i]=s[i]-'0';
	//	q[cnt]=work(l);
	//	q[cnt].next=head[q[cnt].f];
	//	head[q[cnt].f]=cnt;
	//	cnt++;
		int flag=0,myans=0;
		for(int i=1;i<=m;i++){
			//il=getnext(l);
			q[cnt]=work(l);
			q[cnt].next=head[q[cnt].f];
			int ls=10,rs=0;
			for(int k=1;k<=9;k++)
				if(q[cnt].num[k]){
					ls=min(ls,k);
					rs=k;
				}
			if(rs==7&&ls==5){
				if(q[cnt].num[7]>=4&&q[cnt].num[5]==2&&q[cnt].num[6]>=2) flag=2;
			}
			if(rs==4&&ls==1){
				if(q[cnt].num[1]==1&&q[cnt].num[2]==1&&q[cnt].num[4]>=3&&q[cnt].num[3]>=2) flag=2;
			}
			for(int j=head[q[cnt].f];j!=-1;j=q[j].next){
				int sum=0;
				for(int k=1;k<10;k++){
					if(q[j].num[k]!=q[cnt].num[k]) {sum=-1;break;}
				}
				if(sum==-1) continue;
				flag=1;break;
					
			}
			if(flag) {myans=i;break;}
			head[q[cnt].f]=cnt;
			cnt++;
			l=getnext(l);
		}
		printf("%d ",cas);
		if(flag){
			if(flag==1) printf("R %d\n",myans);
				else printf("C %d\n",myans);
		}
		else{
			print(l);
		}
	}
}
