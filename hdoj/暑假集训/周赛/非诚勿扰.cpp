#include<iostream>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
struct node {
	char name[17];
	int data;
	int cnt;//先后顺序 
	friend bool operator < (node a, node b) {
		if(a.data!=b.data) return a.data>b.data;//先推荐能力值小的 
		else return a.cnt>b.cnt;//然后按先后顺序推荐 
	}
};
int main() {
	int t;
	cin>>t; 
	for(int k=1;k<=t;k++) {
		int n,cnt=1;//cnt为顺序，初始化为1 
		cin>>n;//操作数 
		cout<<"Case #"<<k<<":"<<endl;
		priority_queue<node> q;//每次定义可以初始化优先队列 
		for(int i=1;i<=n;i++) {
			string op;
			cin>>op;
			if(op=="Add") {//加的操作 
				node tmp;
				cin>>tmp.name>>tmp.data;
				tmp.cnt=cnt++;//顺序++ 
				q.push(tmp);
				cout<<q.size()<<endl;//输出人员数 
			}
			else {
				int num, cc=1, flag=0;
				node tmp[1000];//用来存储临时数据的结构体数组 
				memset(tmp,0,sizeof(tmp));
				cin>>num;
				if(q.empty()) {//人才库为空的情况 
					cout<<"WAIT..."<<endl;
					continue;
				}
				while(!q.empty()) {
					tmp[cc]=q.top();
					q.pop();
					if(tmp[cc].data>=num) {//满足条件 
						flag=1;
						for(int i=cc-1;i>=1;i--) {
							q.push(tmp[i]);
						}//其余的放入队列中 
						break;
					}
					else cc++;//临时数据的编号++ 
				}
				if(flag) cout<<tmp[cc].name<<endl;
				else {//所有数据都要放入队列中 
					for(int i=cc-1;i>=1;i--) q.push(tmp[i]);
					cout<<"WAIT..."<<endl;
				}
			}
		}
	}
}
