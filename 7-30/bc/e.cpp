#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
long long mod=1000000007ll;
const int MAXN=1000000;
bool check[MAXN+100];
int prime[MAXN+10];
int mu[MAXN+10];
void Moblus(){
    memset(check,false,sizeof(check));
    mu[1]=1;
    int tot=0;
    for(int i=2;i<=MAXN;i++){
        if(!check[i]){
            prime[tot++]=i;
            mu[i]=-1;
        }
        for(int j=0;j<tot;j++){
            if(i*prime[j]>MAXN) break;
            check[i*prime[j]]=true;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;
                break;
            }
            else{
                mu[i*prime[j]]=-mu[i];
            }
        }
    }
}
int sum[MAXN+10];
long long my[MAXN+10];
long long solve(int n){
    if(my[n]) return my[n];
    long long ans=0;
    int m=n;
    for(int i=1,la=0;i<=n;i=la+1){
        la=min(n/(n/i),m/(m/i));
        ans+=(long long) (sum[la]-sum[i-1])*(n/i)*(m/i);
        ans%=mod;
    }
    return my[n]=ans;
}
 int euler[1000010];
  void getEuler()
  {
      memset(euler,0,sizeof(euler));
      euler[1] = 1;
      for(int i = 2;i <= 1000000;i++)
          if(!euler[i])
              for(int j = i; j <= 1000000;j += i)
              {
                  if(!euler[j])
                      euler[j] = j;
                  euler[j] = euler[j]/i*(i-1);
              }
  }

long long myget(int x,int y){
	
}

int main(){
    int T,x,n;
    scanf("%d",&T);
    //Moblus();
    getEuler();
    sum[0]=0;
    memset(my,0,sizeof(my));
    for(int i=1;i<=MAXN;i++){
        sum[i]=sum[i-1]+euler[i];
        sum[i]%=mod;
    }
    while(T--){
        scanf("%d%d",&x,&n);
        long long ans=0,tmp=1,su=1,test=0;
        long long tmp=getni(x-1);
        for(int i=1;i*i<=n;i++){
            long long num=sum[n/i]*2ll-1;
            long long r=n/i,l=n/(i+1)+1;
	    //ans+=(myget(x,r)-myget(x,l)+mod)%mod*num%mod;
	    ans+=(myget(x,i)-1+mod)%mod*num%mod;
	    ans%=mod;
	    if(i*i<n){
		num=sum[i]*2ll-1;
		ans+=(myget(x,r)-myget(x,l)+mod)%mod*num%mod*tmp%mod;
		ans%=mod;
	    }
        }
        //ans=ans*tmp%mod;
        ans%=mod;
        printf("%lld\n",ans);
    }
}
