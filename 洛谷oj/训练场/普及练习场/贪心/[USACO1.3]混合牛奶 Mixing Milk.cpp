#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;
struct node {
	int price,num;
	friend bool operator < (node a, node b) {//����
		return a.price > b.price;//�۸�͵�����
	}
};
int main() {
	int n,m,ans = 0,num = 0;
	cin>>n>>m;
	node tmp;
	priority_queue<node> q;//�������ȶ���
	for(int i = 1;i <= m;i++) {
		cin>>tmp.price>>tmp.num;
		q.push(tmp);
	}
	while(num<n) {
		tmp = q.top();q.pop();
		//ֻ��Ҫ�жϵ�ǰ��ţ����������ţ������С
		//Ȼ��ʵʱ���� �ܼ�Ǯ �� ��ǰţ������
		if(n-num>=tmp.num) ans += tmp.num*tmp.price,num += tmp.num;
		else ans += (n-num)*tmp.price, num = n;//ţ��������
	}
	cout<<ans<<endl;
	return 0;
}
