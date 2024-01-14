#include<iostream>
#include<cstring>
#define INF 99999999
#define min(a,b) a<b?a:b
using namespace std;
const int MAXN=105;
int a[MAXN][MAXN],b[MAXN],path[MAXN][MAXN];
void print_path(int u, int v) {
	if(path[u][v]==v) {
		cout<<"-->"<<v;
		return ;
	}
	cout<<"-->"<<path[u][v];
	int k=path[u][v];
	print_path(k,v);
	return ;
}
int main() {
	int n;
	while(cin>>n) {
		if(n==0) break;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) {
				cin>>a[i][j];
				if(a[i][j]==-1) a[i][j]=INF;//-1不通 
				path[i][j]=j;//path记录的是终点（转折点） 
			}
		for(int i=1;i<=n;i++)
			cin>>b[i];
		int s,e;
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				if(a[i][k]!=INF)
				for(int j=1;j<=n;j++) {
					if(a[i][j]>a[i][k]+a[k][j]+b[k]) {//>符号很关键 
						a[i][j]=a[i][k]+a[k][j]+b[k];
						path[i][j]=path[i][k];
					}
					else if(a[i][j]==a[i][k]+a[k][j]+b[k]) {
						if(path[i][j]>path[i][k])//字典序 
						path[i][j]=path[i][k];
					}
				}
		while(cin>>s>>e){
			if(s==-1&&e==-1) break;
			cout<<"From "<<s<<" to "<<e<<" :"<<endl;
			cout<<"Path: "<<s;//输出起点 
			if(s!=e) print_path(s,e);//起始点和终点一样（wrong answer） 
			cout<<endl<<"Total cost : "<<a[s][e]<<endl<<endl;
		}
	}
	return 0;
} 
