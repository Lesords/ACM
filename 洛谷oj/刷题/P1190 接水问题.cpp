#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 1e4+5;
int a[MAXN];
int main() {
	int n,m,ans = 0;
	priority_queue<int,vector<int>,greater<int> > q;
	//�������У���С��
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	for(int i = 1;i <= m;i++) {//m��ˮ��ͷ
		q.push(a[i]);
	}//ǰ��Ľ����˺����ͬѧ����
	//�൱�ڵ�ǰˮ��ͷ����ʱ��Ϊ����֮��
	while(m<=n) {//ʣ���ͬѧ
		int tmp = q.top();//�ٵ�ˮ��ͷ
		q.pop();
		q.push(tmp+a[++m]);//����һ��ͬѧ��ˮ������
	}
	while(!q.empty()) {//m��ˮ��ͷ�����ʱ�伴Ϊ���
		ans = max(ans,q.top());
		q.pop();
	}
	cout<<ans;
	return 0;
}
