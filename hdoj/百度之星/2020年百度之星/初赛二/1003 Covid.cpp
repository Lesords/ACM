#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 2e4+5;
int len[MAXN],vis[15],mark[MAXN];
struct node{
	int num,pos;//编号和位置
};
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<node> tim[105];//100个时间点
		memset(mark,0,sizeof(mark));
		mark[1] = 1;//标记带有荧光粉的人
		int num = 1;
		for(int i = 1;i <= n;i++) {
			cin>>len[i];
			int t,p;
			for(int j = 1;j <= len[i];j++) {
				cin>>t>>p;
				//t时刻i在p位置
				tim[t].push_back(node{i,p});
			}
		}
		node tmp;
		for(int i = 1;i <= 100;i++) {
			int flag = 0;
			set<int> spos;//当前时刻出现荧光粉的位置
			for(int j = 0;j < tim[i].size();j++) {
				tmp = tim[i][j];
				if(mark[tmp.num]) {
					flag = 1;
					spos.insert(tmp.pos);//记录所有出现荧光粉的位置
				}
			}
			if(flag==0) continue;//跳过没有荧光粉的情况
			for(int j = 0;j < tim[i].size();j++) {
				tmp = tim[i][j];
				if(mark[tmp.num]) continue;
				if(spos.count(tmp.pos)) {//当前位置有荧光粉
					mark[tmp.num] = 1;//当前人也沾上荧光粉
				}
			}
		}
		int flag = 0;
		for(int i = 1;i <= 20000;i++) {
			if(mark[i]) {//输出具有荧光粉的人即可
				if(flag) cout<<' ';
				cout<<i;flag = 1;
			}
		}
		cout<<endl;
	}
	return 0;
}
