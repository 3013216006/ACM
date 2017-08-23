#include <iostream>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",&s,&s1);
		int l=strlen(s);
		while(!Q.empty()) Q.pop_front();
		while(!Q1.empty()) Q1.pop_front();
		Q.push_back(Node(s[0],1,0));
		Q1.push_back(Node(s1[0],1,0));
		for(int i=1;i<l;i++){
			if(s[i]==Q.back().x) Q.back().y++;
			else{
				Q.push_back(Node(s[i],1,0));
			}
		}
		l=strlen(s1);
		for(int i=1;i<l;i++){
			if(s1[i]=='*'){
				Q1.back().y--;
				Q1.back().z=1;
			}
			else if(s1[i]=='.'){
				Q1.push_back(Node(s1[i],1,0));
			}
			else{
				if(Q1.back().x==s1[i]){
					Q1.back().y++;
				}
				else{
					Q1.push_back(Node(s1[i],1,0));
				}
			}
		}
		int flag=1,pre=0,hav=0;
		while(!Q.empty()){
			if(Q1.empty()){
				flag=0;
				break;
			}
			Node tp=Q1.front();
			Q1.pop_front();
			if(tp.x=='.'){
				if(pre>=Q.front().y){
					
				}
				else{
					hav+=
				}
			}
		}
	}
}
