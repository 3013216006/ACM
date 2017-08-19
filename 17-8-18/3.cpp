#include <bits/stdc++.h>
using namespace std;
const int maxn = 12;
int map1[maxn][maxn],n,a;
char c;
int getnum(){
    c = '\0';
    while(c = getchar()) {if(c >= '0' && c <= '9') break;}
    int ret = c - '0';
    while(c = getchar()){
        if(c < '0' || c > '9') return ret;
        ret = ret * 10 + c - '0';
    }
}
int main()
{
     int kase;scanf("%d",&kase);
     while(kase--){
         n = getnum();
         for(int i = 1;i <= n;i++){
             for(int j = i + 1;j <= n;j++) {
                 a = getnum();
                 if(n < 6) map1[j][i] = map1[i][j] = a;
             }
         }
         if(n >= 6) {printf("Bad Team!\n");continue;}
        int flag = 1;
        for(int i = 1;i <= n;i++){
             for(int j = i + 1;j <= n;j++){
                 for(int k = j + 1;k <= n;k++){
                     if(map1[i][j] == 1 && map1[j][k] == 1 && map1[k][i] == 1) flag = 0;
                     if(map1[i][j] == 0 && map1[j][k] == 0 && map1[k][i] == 0) flag = 0;
                 }
             }
         }
         if(flag) printf("Great Team!\n");
         else printf("Bad Team!\n");
     }
     return 0;
}
         
