#include<iostream>//ac
#include<set>
using namespace std;
const int MAXN = 1005;
int main() {
	set<int> s[MAXN];
	int n,m,k,tmp;
	cin>>n>>m>>k;
	for(int i = 1;i <= n;i++) {//i代表学生
		for(int j = 1;j <= m;j++) {//j代表模拟赛题号
			cin>>tmp;//tmp为有空的时间点
			s[tmp].insert(j);//在对应时间点放入赛题号
		}
	}
	for(int i = 1;i <= k;i++) {
		if(i!=1) cout<<' ';
		cout<<s[i].size();//最后输出对应的赛题数量即可
	}
	return 0;
}
