#include <isotream>
using namespace std;

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		int l=1;
		for(int i=0;i<m;i++){
			l*=3;
			scanf("%d%d",&x,&y);
			scanf("%d",&a[x][y]);
			a[y][x]=a[x][y];
		}
		int ans=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<l;i++){
			int s=0,tmp=i;
			
		}
	}
}
