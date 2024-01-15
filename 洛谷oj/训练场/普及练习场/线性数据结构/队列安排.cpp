#include<iostream>//ac
#include<set>
using namespace std;
const int MAXN = 1e5 + 5;
int leftt[MAXN],rightt[MAXN];
int main() {
	int n,m,a,b,start = 1;//初始起点为1
	leftt[1] = rightt[1] = 0;//初始化1的左右都为0（即空）
	cin>>n;
	for(int i = 2;i <= n;i++) {
		cin>>a>>b;//0左，1右
		if(b) {//将 i 放在a的右边
			int tmp = rightt[a];//取原队列a的右数字
			rightt[a] = leftt[tmp] = i;//更新原队列左右状态
			rightt[i] = tmp;//更新插入数字的左右数字
			leftt[i] = a;
		}
		else {//将 i 放在a的左边
			int tmp = leftt[a];//取原队列a的左数字
			leftt[a] = rightt[tmp] = i;//更新原队列左右状态 
			leftt[i] = tmp;//更新插入数字的左右数字
			rightt[i] = a;
			if(tmp==0) start = i;//左为空，更新起点
		}
	}
	cin>>m;//移去学生数量
	set<int> s;
	while(m--) cin>>a,s.insert(a);//将 移出的数 放入set容器中
	while(start) {
		if(!s.count(start)) {//若不在set容器中则输出
			cout<<start<<(start?' ':'\n');
		}//否则移到下一位
		start = rightt[start];
	}
	return 0;
}
