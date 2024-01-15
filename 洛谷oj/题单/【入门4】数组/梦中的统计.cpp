#include<iostream>//ac
using namespace std;
int ans[11],n,m;
int main() {
	cin>>n>>m;
	for(int i = n;i <= m;i++) {//遍历n到m
		int tmp = i;
		while(tmp) {//统计所有数码出现的次数
			ans[tmp%10]++;
			tmp /= 10;
		}
	}
	for(int i = 0;i <= 9;i++) {//输出
		if(i) cout<<' ';
		cout<<ans[i];
	}
	return 0;
}
