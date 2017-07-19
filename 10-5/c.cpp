#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[100010];
string ss[20];
char s1[1001][101];
int a[1001],b[10],c[1001],d[10],ssl[10],e[1001];
int pan1(int cnt){
	int flag=0;
	for(int i=0;i<cnt;i++)
	if(c[i]==1){
		if(i>0){
			if(c[i-1]==0) continue;
		}
		if(i>1){
			if(c[i-2]==0) continue;
		}
		if(i+1<cnt){
			if(c[i+1]==3) continue;
		}
		for(int j=0;j<3;j++)
			s[e[i]+j]=ss[6][j];
		flag=1;
	}
	return flag;
}

int pan2(int cnt){
	if(cnt<3) return 1;
	cnt--;
	if(c[cnt]!=4){
		return 1;
	}
	cnt--;
	if(c[cnt]!=2){
		return 1;
	}
	cnt--;
	if(c[cnt]!=4){
		return 1;
	}
	return 0;
}

int pan3(int cnt){
	if(d[3]){
		if(d[5]) return 0;
			else return 1;
	}
	else return 0;
}

int pan4(int cnt){
	if(c[0]==0) return 1;
		else return 0;
}

int pan5(int cnt){
	if(d[1]==0) return 1;
	return 0;
}
void work(int cnt){
	memset(c,-1,sizeof(c));
	memset(d,0,sizeof(d));
	for(int i=0;i<cnt;i++){
		for(int j=0;j<6;j++)
			if(a[i]==ssl[j]){
				int flag=1;
				for(int k=0;k<a[i];k++)
					if(ss[j][k]!=s1[i][k]) flag=0;
				if(flag) c[i]=j;
			}
		if(c[i]==-1) c[i]=6;
		d[c[i]]++;
	}
}

int main(){
	ss[0]="jiggle";
	ss[1]="dip";
	ss[2]="stomp";
	ss[3]="twirl";
	ss[4]="clap";
	ss[5]="hop";
	ss[6]="DIP";
	ssl[0]=6;
	ssl[1]=3;
	ssl[2]=5;
	ssl[3]=5;
	ssl[4]=4;
	ssl[5]=3;
	while(gets(s)){
		int l=strlen(s);
		int cnt=0;
		memset(a,0,sizeof(a));
		for(int i=0;i<l;i++){
			if(s[i]==' '){
				cnt++;
				e[cnt]=i+1;
				continue;
			}
			s1[cnt][a[cnt]++]=s[i];
		}
		cnt++;
		int cntl=0;
		work(cnt);
		if(pan1(cnt)) b[cntl++]=1;
		if(pan2(cnt)) b[cntl++]=2;
		if(pan3(cnt)) b[cntl++]=3;
		if(pan4(cnt)) b[cntl++]=4;
		if(pan5(cnt)) b[cntl++]=5;
		if(cntl==0){
			printf("form ok: %s\n",s);
		}
		else
			if(cntl==1){
				printf("form error %d: %s\n",b[0],s);
			}
			else{

				printf("form errors ");
				for(int i=0;i<cntl-2;i++)
					printf("%d, ",b[i]);
				printf("%d and %d: %s\n",b[cntl-2],b[cntl-1],s);
			}
	}
}
