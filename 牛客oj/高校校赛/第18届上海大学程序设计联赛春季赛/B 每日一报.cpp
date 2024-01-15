#include<iostream>//ac
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
	int date,num;
	double val;
	friend bool operator < (node a,node b) {
		//�����ں����£����ѧ��
		if(a.date!=b.date) return a.date<b.date;
		else if(a.val!=b.val) return a.val<b.val;
		else return a.num>b.num;
	}
};
int main() {
	int n;
	priority_queue<node> q;
	node tmp;
	cin>>n;
	while(n--) {
		cin>>tmp.date>>tmp.num>>tmp.val;
		if(tmp.val>=38) q.push(tmp);//ֻ��Ҫͳ�ƴ���38�ȵ�
	}
	cout<<q.size()<<endl;
	while(!q.empty()) {
		tmp = q.top();q.pop();
		printf("%d %d %.1f\n",tmp.date,tmp.num,tmp.val);
	}
	return 0;
}
