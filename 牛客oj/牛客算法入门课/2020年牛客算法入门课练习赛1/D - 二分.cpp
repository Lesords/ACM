#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
//0x3fffffff Ϊһ��
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
		//.Ϊһ�����䣬��һλ����--������
		if(op=='.') mapp[tmp]++,mapp[tmp+1]--;
		else if(op=='+') {
			//+�Ļ�����tmpǰ�棡����
			mapp[tmp]--,mapp[-INF]++;
		}//-�Ļ�����tmp����
		else mapp[INF]--,mapp[tmp+1]++;
	}
	int h = 0;
	/*for(auto v:mapp) {
		h += v.second;//�Բ����ǰ׺�;��ǵ�ǰ��ֵ
		ans = max(ans,h);
	}
	cout<<ans;
	*/
	//map���������ֱ�����ʽ
	for(it = mapp.begin();it!=mapp.end();it++) {
		h += it->second;
		ans = max(ans,h);
	}
	cout<<ans;
	return 0;
}
