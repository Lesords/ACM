#include<iostream>//ac
#include<cmath>
#include<queue>
using namespace std;
int m,n,k;
struct node {
	int x,y,num;
	friend bool operator < (node a,node b) {
		return a.num < b.num;//�����Ҷ�Ļ���
	}
};
int main() {
	cin>>m>>n>>k;
	int tmp,ans = 0,time = 0,tx,ty;//�����ʱ�䶼��ʼ��Ϊ0
	priority_queue<node> q;
	for(int i = 1;i <= m;i++) {
		for(int j = 1;j <= n;j++) {
			cin>>tmp;
			if(tmp) q.push(node{i,j,tmp});
		}
	}
	node tri;
	//��ֹ������ʱ���û�л��������������
	while(!q.empty()) {//��Ҫ�ж��Ƿ��л�����
		tri = q.top();q.pop();
		if(!time) {//��һ���һ��� 
			tx = tri.x,ty = tri.y,time = tx+1;//���û���λ�ú�ʱ��
			if(time+tri.x<=k) ans = tri.num;//��ʱ���ȥ���´�
			else break;//û�о��˳�
		}
		else {//�ƶ�ʱ�� + �ɻ�����ʱ��
			time += (abs(tri.x-tx)+abs(tri.y-ty))+1;
			tx = tri.x,ty = tri.y;//������һ������λ��
			if(time+tri.x<=k) ans += tri.num;//��ʱ���ȥ���´�
			else break;//û�о��˳�
		}
	}
	cout<<ans<<endl;
	return 0;
}
