#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int MAXN = 210;
struct node{//保存斜率
	int x,y;
}a[MAXN];
int gcd(int x,int y) {//最大公约数
	return y==0?x:gcd(y,x%y);
}
int main() {
	pair<int,int> tmp;
	set<pair<int,int>> s;
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i].x>>a[i].y;
	for(int i = 1;i < n;i++) {
		for(int j = i+1;j <= n;j++) {
			tmp.first = a[i].x-a[j].x;
			tmp.second = a[i].y-a[j].y;
			int ttt = gcd(tmp.first,tmp.second);
			tmp.first /= ttt;//化简
			tmp.second /= ttt;
			s.insert(tmp);
		}
	}
	cout<<s.size();//输出大小
	return 0;
}
