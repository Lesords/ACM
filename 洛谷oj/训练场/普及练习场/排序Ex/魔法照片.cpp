#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 2e4 + 5;
int e[15];//保存额外权值
struct node {
	int num,w;
	friend bool operator < (node a, node b) {
		if(a.w!=b.w) return a.w>b.w;//先排权值
		return a.num < b.num;//后排编号
	}
}p[MAXN];
int main() {
	int n,k;
	cin>>n>>k;
	for(int i = 1;i <= 10;i++) cin>>e[i];//额外权值
	for(int i = 1;i <= n;i++) {
		cin>>p[i].w;
		p[i].num = i;
	}
	sort(p+1,p+n+1);//未加额外值 排序求序号
	for(int i = 1;i <= n;i++) {//当前i即为d[i]序号
		p[i].w += e[(i-1)%10+1];
	}
	sort(p+1,p+n+1);//再次排序
	for(int i = 1;i <= k;i++) {//输出k个人
		if(i!=1) cout<<' ';
		cout<<p[i].num;
	}
	return 0;
}
