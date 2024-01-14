#include<iostream>//ac
#include<cstring>
#include<queue>
using namespace std;
struct cup {
	int c[4],step;
}now;
int a[4],t,book[105][105];//第一维为可乐杯，第二维为较大杯子
void poor(int i,int j) {//i -> j
	int sum = now.c[i]+now.c[j];//总量
	now.c[j] = (sum>=a[j])?a[j]:sum;//判断是否可装满
	now.c[i] = sum - now.c[j];
}
void bfs() {
	queue<cup> q;
	cup tmp;
	memset(book,0,sizeof(book));//初始化
	q.push(cup{0,a[1],0,0,0});//初始量有c[0]!!!
	book[a[1]][0] = 1;//标记初始状态
	while(!q.empty()) {
		tmp = q.front();q.pop();
		if(tmp.c[1]==tmp.c[2]&&tmp.c[3]==0) {//两个杯子相同
			cout<<tmp.step<<endl;            //另一个为0
			return;
		}
		for(int i = 1;i <= 3;i++) {//i->j 
			for(int j = 1;j <= 3;j++) {
				if(i==j||tmp.c[i]==0) continue;//i为空杯
				now = tmp;
				poor(i,j);
				if(book[now.c[1]][now.c[2]]) continue;//重复
				now.step++;
				q.push(now);
				book[now.c[1]][now.c[2]] = 1;//标记当前情况
			}
		}
	}
	cout<<"NO"<<endl;//无法平分
}
int main() {
	while(cin>>a[1]>>a[2]>>a[3]&&a[1]+a[2]+a[3]) {
		if(a[1]%2) {//奇数无法平分
			cout<<"NO"<<endl;continue;
		}//令a[2]为较大容量杯子
		if(a[2]<a[3]) t = a[2],a[2] = a[3], a[3] = t;
		bfs();
	}
	return 0;
}
