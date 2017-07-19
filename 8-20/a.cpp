#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
using namespace std;

const int maxn =  222;

char c[maxn][maxn];
int cv[maxn][maxn];
int vx1[5] = {-1,0,1,0,-1};
int vy1[5] = {0,1,0,-1,0};
int vx2[5] = {0,1,0,-1,0};
int vy2[5] = {1,0,-1,0,1};
int v[maxn];
vector<pii> p;

int n,m,ans,sz,cntp,cnts;

void dfs(int d,int s){
	if(d==sz){
		if(cntp==sz&&cnts==0){
			ans = ans == -1 ? s : min(s,ans);
		}else{
			/*
			for(int i=0;i<sz;i++){
				printf("%d %d\n",p[i].X,p[i].Y);
			}
			*/
			for(int i=0;i<sz;i++){
				if(v[i]){
					int x = p[i].X;
					int y = p[i].Y;
					for(int j=1;j<5;j++){
						int px1 = x+vx1[j-1];
						int py1 = y+vy1[j-1];
						int px2 = x+vx2[j-1];
						int py2 = y+vy2[j-1];
						int nx1 = x+vx1[j];
						int ny1 = y+vy1[j];
						int nx2 = x+vx2[j];
						int ny2 = y+vy2[j];
						if(px1>=0&&px1<n&&py1>=0&&py1<m){
							cv[px1][py1]--;
							if(!cv[px1][py1]){
								if(c[px1][py1]=='.') cntp--;
								else cnts--;
							}
						}
						if(px2>=0&&px2<n&&py2>=0&&py2<m){
							cv[px2][py2]--;
							if(!cv[px2][py2]){
								if(c[px2][py2]=='.') cntp--;
								else cnts--;
							}
						}
						if(nx1>=0&&nx1<n&&ny1>=0&&ny1<m){
							if(!cv[nx1][ny1]){
								if(c[nx1][ny1]=='.') cntp++;
								else cnts++;
							}
							cv[nx1][ny1]++;
						}
						if(nx2>=0&&nx2<n&&ny2>=0&&ny2<m){
							if(!cv[nx2][ny2]){
								if(c[nx2][ny2]=='.') cntp++;
								else cnts++;
							}
							cv[nx2][ny2]++;
						}
						if(cntp==sz&&cnts==0){
							ans = ans == -1 ? s : min(s,ans);
						}
					}
				}
			}
		}
	}else{
		dfs(d+1,s);
		v[d] = 1;
		int x = p[d].X;
		int y = p[d].Y;
		if(!cv[x][y]){
			cntp++;
		}
		cv[x][y]++;
		if(x-1>=0){
			if(!cv[x-1][y]){
				if(c[x-1][y]=='.') cntp++;
				else cnts++;
			}
			cv[x-1][y]++;
		}
		if(y+1<m){
			if(!cv[x][y+1]){
				if(c[x][y+1]=='.') cntp++;
				else cnts++;
			}
			cv[x][y+1]++;
		}
		dfs(d+1,s+1);
		v[d] = 0;
		cv[x][y]--;
		if(!cv[x][y]){
			cntp--;
		}
		if(x-1>=0){
			cv[x-1][y]--;
			if(!cv[x-1][y]){
				if(c[x-1][y]=='.') cntp--;
				else cnts--;
			}
		}
		if(y+1<m){
			cv[x][y+1]--;
			if(!cv[x][y+1]){
				if(c[x][y+1]=='.') cntp--;
				else cnts--;
			}
		}
	}
}

int main(){
	while(~scanf("%d%d",&n,&m)&&n){
		cntp = cnts = 0;
		memset(v,0,sizeof v);
		memset(cv,0,sizeof cv);
		ans = -1;
		sz = 0;
		for(int i=0;i<n;i++){
			scanf("%s",c[i]);
		}
		p.clear();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(c[i][j]=='.') p.push_back(mp(i,j)),sz++;
			}
		}
		if(sz==0){
			printf("%d\n",0);
			continue;
		}
		//printf("sz=%d\n",sz);
		dfs(1,0);
		v[0] = 1;
		int x = p[0].X;
		int y = p[0].Y;
		if(x-1>=0){
			cv[x-1][y]++;
			if(c[x-1][y]=='.') cntp++;
			else cnts++;
		}
		if(y+1<m){
			cv[x][y+1]++;
			if(c[x][y+1]=='.') cntp++;
			else cnts++;
		}
		cntp++;
		cv[x][y]++;
		dfs(1,1);
		printf("%d\n",ans);
	}
	return 0;
}
