#include<iostream>//ac
#include<queue>
#include<string>
using namespace std;
const int MAXN = 1e5+5;
bool vis[MAXN];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	//old 优先队列用来存放删除的文档号
	priority_queue<int,vector<int>,greater<int> > old;
	string op;
	int n,num = 1;//初始文档号
	cin>>n;
	while(n--) {
		cin>>op;
		if(op=="New") {//创建文档
			if(old.empty()) {//没有删除的号码
				cout<<num<<"\n";
				vis[num] = 1;//1位num号存在
				++num;
			}
			else {//有删除的号码，优先用删除的号码
				cout<<old.top()<<"\n";
				vis[old.top()] = 1;//标记存在
				old.pop();
			}
		}
		else {
			int tmp;
			cin>>tmp;
			if(vis[tmp]) {//存在该文档号
				old.push(tmp);//old里输入该号码
				vis[tmp] = 0;//标记不存在
				cout<<"Successful\n";
			}
			else cout<<"Failed\n";
		}
	}
	return 0;
}
