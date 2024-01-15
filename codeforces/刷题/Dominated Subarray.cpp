#include<iostream>//ac
#include<cstring>
//最短的主导区间可以理解为出现两个相同的数字的区间
//更新数字的位置，并判断最小区间
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5; 
int book[MAXN];
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		memset(book,0,sizeof(book));
		int minn = INF,tmp;
		for(int i = 1;i <= n;i++) {
			cin>>tmp;
			if(book[tmp]) {//取最小值
				minn = min(minn,i-book[tmp]+1);
			}
			book[tmp] = i;//更新数字位置
		} 
		if(minn!=INF) cout<<minn<<endl;
		else cout<<"-1"<<endl;//不存在输出-1 
	}
	return 0;
}
