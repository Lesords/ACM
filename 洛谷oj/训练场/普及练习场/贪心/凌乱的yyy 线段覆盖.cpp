#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;
struct node{
	int s,e;
	friend bool operator < (node a,node b) {//���価����С
		if(a.e!=b.e) return a.e > b.e;//����ʱ���С����
		return a.s < b.s;//��ʼʱ��Ӵ�С
	}
};
int main() {
	int n,a,b,ans = 0;
	priority_queue<node> q;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a>>b;
		q.push(node{a,b});
	}
	node tmp;
	int start = 0;//start��ʾ��ǰʱ��
	while(!q.empty()) {
		tmp = q.top();q.pop();
		//��ǰ��Ŀ��ʼʱ�����startʱ
		//���++������startʱ��Ϊ ��ǰ��Ŀ������ʱ��
		if(tmp.s>=start) ans++,start = tmp.e;
	}
	cout<<ans;
	return 0;
}
