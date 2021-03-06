#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1000 + 10;
const int MOD = 6;
struct Matrix{
	int n,m;
	int mat[maxn][maxn];

	void init(){
		n = 0;m = 0;
		memset(mat,0,sizeof(mat));
	}
		
	void input(){
//		scanf("%I64d%I64d",&n,&m);
		for(int i = 1;i <= n;i++) 
			for(int j = 1;j <= m;j++)
				scanf("%d",&mat[i][j]);
	}
	
	Matrix() {init();}
	
	void output(){
		printf("n:  %I64d, m:  %I64d\n",n,m);
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				printf("%I64d\t",mat[i][j]);
			}
			printf("\n");
		}
	}
	
	Matrix operator * (const Matrix & x){
		Matrix ans;
		ans.n = n;ans.m = x.m;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= x.m;j++){
				for(int k = 1;k <= m;k++){	
					ans.mat[i][j] += mat[i][k] * x.mat[k][j];
				}
				ans.mat[i][j] = (ans.mat[i][j] + MOD) % MOD;
			}
		}
		return ans;
	}
}; 
	
Matrix q_pow(Matrix x,int k){
	if(k == 1) return x;
	if(k == 2) return x * x;
	Matrix temp = q_pow(x,k / 2);
	Matrix ans = temp * temp;
	if(k % 2==1) ans = ans * x;
	return ans;
}
Matrix x1,x3,x2;
int main()
{
	int n = 5,k = 5;
	while(~scanf("%d%d",&n,&k) && n && k){
		x1.init();x2.init();x3.init();
		x1.n = n;x1.m = k;
		x1.input(); 
		x2.n = k;x2.m = n;
		x2.input();
		x3.init();
		cout << "yes" << endl;
		x3 = x2 * x1;
		cout << "yes" << endl;
		x3 = q_pow(x3,n * n - 1);
		cout << "yes" << endl;
		Matrix x4 = x1 * x3;x4 =x4 * x2;
		int ans = 0;
		for(int i = 1;i <= x4.n;i++){
			for(int j = 1;j <= x4.m;j++){
				ans = ans + (x4.mat[i][j] %  6);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
