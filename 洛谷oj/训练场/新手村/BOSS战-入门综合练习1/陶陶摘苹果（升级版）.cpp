#include<iostream>//ac
#include<queue>
using namespace std;
struct apple{
	int height,power;
	friend bool operator < (apple a,apple b) {
		return a.power>b.power;//�Ӵ�С���򣬶�ĩΪ��С
	}
};
int main() {
	int n,s,a,b,x,y;
	priority_queue<apple> q;
	cin>>n>>s>>a>>b;
	for(int i = 1;i <= n;i++) {
		cin>>x>>y;
		if(x>a+b) continue;//ժ����������
		q.push({x,y});
	}
	int ans = 0;//��ʼ����Ϊ0
	while(s) {
		apple tmp = q.top();//��ĩ����
		q.pop();
		if(tmp.power>s) break;//��������
		ans++;
		s -= tmp.power;//���µ�ǰʣ������
	}
	cout<<ans<<endl;
	return 0;
}
