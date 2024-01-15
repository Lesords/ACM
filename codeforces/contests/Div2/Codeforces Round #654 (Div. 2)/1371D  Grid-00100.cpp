#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define two(x) (x)*(x)
using namespace std;
int map[303][303],r[303],c[303];
int main() {
	int t,n,k;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		int num = 0;
		memset(map,0,sizeof(map));
		//主对角线排列k个1（对角线向右移动）
		for(int i = 1;i <= n&&num!=k;i++) {
			int x = 1,y = i;//第一个总是从第一行开始
			for(int j = 1;j <= n;j++) {
				x++,y++;
				if(x>n) x -= n;//范围为1-n
				if(y>n) y -= n;
				map[x][y] = 1;num++;
				if(num==k) break;//只排列k个
			}
		}
		int maxr = 0,minr = INF,maxc = 0,minc = INF;
		for(int i = 1;i <= n;i++) {
			r[i] = 0;
			for(int j = 1;j <= n;j++) {
				r[i] += map[i][j];
			}
			maxr = max(maxr,r[i]);//最大行值
			minr = min(minr,r[i]);//最小行值
		}
		for(int i = 1;i <= n;i++) {
			c[i] = 0;
			for(int j = 1;j <= n;j++) {
				c[i] += map[j][i];
			}
			maxc = max(maxc,c[i]);//最大列值
			minc = min(minc,c[i]);//最小列值
		}
		//输出结果
		cout<<two(maxr-minr)+two(maxc-minc)<<endl;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) {
				cout<<map[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
