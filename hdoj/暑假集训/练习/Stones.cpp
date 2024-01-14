#include<iostream>
#include<queue>
using namespace std;
struct node{
	int pos;//石块当前位置 
	int dis;//石块可以扔出去的距离 
	friend bool operator < (node a,node b) {//运算符重载 
		if(a.pos==b.pos) return a.dis>b.dis;//先碰到小的，然后扔大的 
		return a.pos>b.pos;
	}
};
int main() {
	int t;
	cin>>t;
	while(t--) {
		priority_queue<node> q;
		int n,num=1;//石子的次数 
		node temp;
		cin>>n;//石子数量 
		for(int i=1;i<=n;i++) {
			int a,b;
			cin>>a>>b;
			temp.pos=a;//石块当前的位置 
			temp.dis=b;//石块可以扔出去的距离 
			q.push(temp);
		}
		while(!q.empty()) {//判断是否还有石子 
			temp=q.top();
			q.pop();
			if(num%2) {//判断是奇数次还是偶数次 
				temp.pos+=temp.dis;//修改石块位置 
				q.push(temp);
			}
			num++;//石子的次数++ 
		}
		cout<<temp.pos<<endl;//temp保存的就是最后一次扔的石头 
	}
	return 0;
} 
