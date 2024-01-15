#include<iostream>//ac
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 10;
int monster[MAXN],book[MAXN];
int main() {
	int t,n,m;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i = 1;i <= n;i++) cin>>monster[i],book[i] = 0;
		//怪物位置不可变，必须按顺序消灭怪物！！！ 
		cin>>m;
		int p,s;
		for(int i = 1;i <= m;i++) {
			cin>>p>>s;//book[次数] = 能量
			book[s] = max(p,book[s]);//一天可消灭s个最大的怪物能量
		}
		for(int i = n-1;i >= 1;i--) {
			book[i] = max(book[i],book[i+1]);//更新怪物能量
		}
		int pos = 1,day = 0,flag = 0;
		while(pos<=n) {
			day++;//天数增加
			int t_pos = pos;//临时位置
			int mx = 0;//保存当天所消灭的怪物的最大能量
			while(1) {
				mx = max(mx,monster[t_pos]);
				if(mx>book[t_pos-pos+1]) break;//逐个判断是否可以消灭怪物
				t_pos++;
			}
			if(t_pos==pos) {//未消灭怪物
				flag = 1;
				break;
			}
			pos = t_pos;//更新位置
		}
		if(flag) cout<<"-1"<<endl;//无法消灭
		else cout<<day<<endl;
	}
	return 0;
}
