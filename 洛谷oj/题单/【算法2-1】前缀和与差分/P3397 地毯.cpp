#include<iostream>//ac
using namespace std;
const int MAXN = 1005;
int map[MAXN][MAXN];
int main() {
	int n,m,x1,y1,x2,y2;
	//��̺ÿ����һ�ξ��൱�������ڼ�1
	//�������ӣ�����ʹ�ò��+ǰ׺��
	cin>>n>>m;
	while(m--) {
		cin>>x1>>y1>>x2>>y2;
		//��ά���
		//��x1��x2���ж�β��
		for(int i = x1;i <= x2;i++) {
			map[i][y1]++;//���
			map[i][y2+1]--;//ĩ������
		}
	}
	for(int i = 1;i <= n;i++) {
		int tmp = 0;//��ʼ��Ϊ0������ǰ׺��
		for(int j = 1;j <= n;j++) {
			if(j!=1) cout<<' ';
			tmp += map[i][j];
			cout<<tmp;//���ֵ
		}
		cout<<"\n";
	}
	return 0;
}
