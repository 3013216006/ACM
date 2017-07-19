#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

#define LL long long

const int N = 10000010;

bool prime[N];
LL p[N];
LL pr[N];
LL k=0,c;

void isprime()
{
    LL i,j;
    memset(prime,true,sizeof(prime));
    for(i=2;i<N;i++)
    {
        if(prime[i])
        {
            p[k++]=i;
            for(j=i+i;j<N;j+=i)
            {
                prime[j]=false;
            }
        }
    }
}

void cal(LL n)
{
    LL t=n,i,a;c=0;
    for(i=0;p[i]*p[i]<=n;i++)
    {
        if(n%p[i]==0)
        {
            pr[c]=p[i];
            while(n%p[i]==0) n/=p[i];
            c++;
        }
    }
    if(n>1)
    {
        pr[c]=n;
        c++;
    }
}

LL quick_mod(LL aa,LL bb,LL m)
{
    __int128 ans=1,a=aa,b=bb;
    a%=m;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%m;
            b--;
        }
        b>>=1;
        a=a*a%m;
    }
    return (long long)ans;
}

int main()
{
    LL P,i,t,g,root;
    isprime();
    while(cin>>P)
    {
    	P=(75ll<<51)+1ll;
        cal(P-1);
        for(g=2;g<P;g++)
        {
            bool flag=true;
            for(i=0;i<c;i++)
            {
                t=(P-1)/pr[i];
                if(quick_mod(g,t,P)==1)
                {
                   flag=false;
                   break;
                }
            }
            if(flag)
            {
                root=g;
                cout<<root<<endl;
            }
        }
    }
    return 0;
}

