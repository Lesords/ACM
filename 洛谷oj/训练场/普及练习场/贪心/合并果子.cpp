#include<iostream>//ac
#include<queue>
using namespace std;
int main() {
	int n,a,ans = 0;
	priority_queue<int, vector<int>, greater<int> >q;//�������
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a;
		q.push(a);
	}
	int tmp1, tmp2;
	while(!q.empty()) {//������ԭ��
		tmp1 = q.top();q.pop();
		if(!q.empty()) {//��Ϊ��ʱ���еڶ�����
			tmp2 = q.top();q.pop();
		}
		else tmp2 = 0;//����Ϊ0
		ans += tmp1+tmp2;
		if(!q.empty()) q.push(tmp1+tmp2);//��Ϊ��ʱ����Ҫ���
	}
	cout<<ans<<endl;
	return 0;
}
