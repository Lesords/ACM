#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
//0x3fffffff 为一半
#define INF 0x7fffffff
using namespace std;
const int MAXN = 1e6+5;
int a[MAXN];
map<int,int> mapp;
map<int,int>:: iterator it;
int main() {
	int n,tmp,ans = -INF;
	char op;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>tmp>>op;
		//.为一个区间，后一位数需--！！！
		if(op=='.') mapp[tmp]++,mapp[tmp+1]--;
		else if(op=='+') {
			//+的话答案在tmp前面！！！
			mapp[tmp]--,mapp[-INF]++;
		}//-的话答案在tmp后面
		else mapp[INF]--,mapp[tmp+1]++;
	}
	int h = 0;
	/*for(auto v:mapp) {
		h += v.second;//对差分求前缀和就是当前数值
		ans = max(ans,h);
	}
	cout<<ans;
	*/
	//map容器的两种遍历方式
	for(it = mapp.begin();it!=mapp.end();it++) {
		h += it->second;
		ans = max(ans,h);
	}
	cout<<ans;
	return 0;
}
