#include<iostream>//ac
using namespace std;
int ans[105],n,m,book[105];
int main() {
	ans[0] = 1;//设置初始起点
	cin>>n>>m;
	for(int i = 1;i <= n;i++) {//总共n个
		for(int j = ans[i-1],cnt = 0;;j = j%n + 1) {//%n防超n
			if(book[j]) continue;//跳过已选过的
			cnt++;//报数ing
			if(cnt==m) {//报到m时
				ans[i] = j,book[j] = 1;//记录答案并标记已选过的
				break;
			}
		}
	}
	for(int i = 1;i <= n;i++) {
		if(i!=1) cout<<' ';
		cout<<ans[i];
	}
	return 0;
} 
