#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include <iostream>
using namespace std;
int n,k,x[15],y[15],r[15],temp;
bool vis[115][115],flag;
int ans,cnt;
int main()
{
    while(~scanf("%d",&n))
    {
    	if(n==0) break;
        scanf("%d",&k);
        flag=false;
        ans=20;
        for(int i=0;i<k;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
            x[i]*=2;
            x[i]--;
            y[i]*=2;
            y[i]--;
        }
        for(int i=0;i<k;i++)
        {
            scanf("%d",&r[i]);
            r[i]*=2;
        }
        n*=2;
        n--;
        for(int i=0;i<(1<<k);i++)
        {
            cnt=temp=0;
            memset(vis,false,sizeof(vis));
            for(int j=0;j<k;j++)
            {
                if(i&(1<<j))
                {
                    temp++;
                    for(int a=1;a<=n;a++)
                    {
                        for(int b=1;b<=n;b++)
                        {
                            if(abs(a-x[j])+abs(b-y[j])<=r[j])
                            {
                                if(!vis[a][b])
                                {
                                    cnt++;
                                    vis[a][b]=true;
                                }
                            }
                        }
                    }
                }
            }
            cout << cnt << endl;
            if(cnt==n*n)
            {
                if(!flag)
                    flag=true;
                if(temp<ans)
                    ans=temp;
            }
        }
        if(flag)
            printf("%d\n",ans);
        else
            puts("-1");
    }
}

