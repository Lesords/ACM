#include<iostream>//ac
using namespace std;

//���⣺���(x,y) ���Ϸ��ĵ�̺��ţ�����������������
//��⣺�������е�ֱ̺���ж�(x,y)�Ƿ��ڵ�̺��Χ�ڼ��ɣ���������ң�

const int MAXN = 1e6 + 5;
struct node{
	int x,y,xl,yl;
}map[MAXN];
int main() {
	int n,a,b,g,k,x,y;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>map[i].x>>map[i].y>>map[i].xl>>map[i].yl;
	}
	int ans = 0;
	cin>>x>>y;
	for(int i = 1;i <= n;i++) {//��������ң��ҵ�ֱ���˳���
		//�ȼ����̺�����ҷ�Χ
		int l_x = map[i].x, r_x = map[i].x + map[i].xl;
		int l_y = map[i].y, r_y = map[i].y + map[i].yl;
		if(l_x<=x&&x<=r_x&&l_y<=y&&y<=r_y) ans = i;//ʵʱ����
	}
	cout<<(ans?ans:-1)<<endl;//�������
	return 0;
}
