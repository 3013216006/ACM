#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
long long tim[200];
long long all[100],sum[1000];
void init(){
	tim[0]=6;
	tim[1]=2;
	tim[2]=5;
	tim[3]=5;
	tim[4]=4;
	tim[5]=5;
	tim[6]=6;
	tim[7]=3;
	tim[8]=7;
	tim[9]=6;
	tim[10]=6;
	tim[11]=5;
	tim[12]=4;
	tim[13]=5;
	tim[14]=5;
	tim[15]=4;
	long long Sum=0;
	for(int i=0;i<16;i++) Sum+=tim[i];
	all[0]=0;
	for(int i=1;i<8;i++)
		all[i]=all[i-1]*16+Sum*(1ll<<(i*4-4));
	sum[0]=0;
	for(int i=1;i<16;i++)
		sum[i]=sum[i-1]+tim[i-1];
}
long long a[100];
long long b[100];
long long getans(long long x){
//	cout << x << endl;
	long long tmp=0;
	long long ret=0;
	b[0]=0;
	for(int i=0;i<8;i++){
		a[i]=x%16;
		tmp+=(1ll<<(i*4))*a[i];
		b[i+1]=tmp;
		x/=16;
//		cout << a[i] << " " << b[i] << endl;
	}
	for(int i=7;i>=0;i--){
//		cout << a[i] << endl;
		ret+=1ll*a[i]*all[i];
//		cout  << ret << endl;
		ret+=1ll*tim[a[i]]*(b[i]+1);
//		cout << ret << endl;
		ret+=1ll*sum[a[i]]*(1ll<<(i*4));
//		cout << ret << endl;
	}
	return ret;
}
char s[100];
long long k;
long long getnum(){
	int l=strlen(s);
	long long ret=0;
	for(int i=0;i<l;i++)
		if(s[i]>='0'&&s[i]<='9') ret=ret*16+s[i]-'0';
		else ret=ret*16+s[i]-'A'+10;
	return ret;
}
int main(){
	init();
	int haha;
//	while(~scanf("%d",&haha)){
//		cout << getans(haha) << endl;
//	}
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%s",&k,s);
		long long st=getnum();
		long long ed=st+k-1;
//		cout << st << " " << ed << " " << (1ll<<32) << endl;
		if(ed>=(1ll<<32)){
			printf("%lld\n",getans(ed-(1ll<<32))+getans((1ll<<32)-1)-getans(st-1));
		}
		else{
			if(st) printf("%lld\n",getans(ed)-getans(st-1));
			else printf("%lld\n",getans(ed));
		}
	}
}
