#include<iostream>//ac
#include<queue>
using namespace std;
int book[1005];//内存中存在则为 1
int main() {
	int m, n, ans = 0,tmp;
	cin>>m>>n;
	queue<int> q;
	for(int i = 1;i <= n;i++) {
		cin>>tmp;
		if(book[tmp]) continue;//无需查询（内存中有）
		if(q.size()+1<=m) q.push(tmp);//内存未满
		else {
			book[q.front()] = 0;//删除队首数字
			q.pop();//弹出队首数字
			q.push(tmp);//新数入队
		}
		book[tmp] = 1, ans++;//查询新数并保存
	}
	cout<<ans<<endl;
	return 0;
}
