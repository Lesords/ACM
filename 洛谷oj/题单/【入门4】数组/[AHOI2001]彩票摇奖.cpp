#include<iostream>//ac
#include<set>
using namespace std;
int ans[10],n,tmp;
int main() {
	set<int> win;//保存中奖号码
	cin>>n;
	for(int i = 1;i <= 7;i++) cin>>tmp,win.insert(tmp);
	while(n--) {
		int num = 0;//初始化为0
		for(int i = 1;i <= 7;i++) {
			cin>>tmp;
			if(win.count(tmp)) num++;//统计中奖数目
		}
		ans[num]++;//对应奖数++
	}
	for(int i = 7;i >= 1;i--) {//大到小输出
		if(i!=7) cout<<' ';
		cout<<ans[i];
	}
	return 0;
}
