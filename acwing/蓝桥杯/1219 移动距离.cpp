#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;
int solve(int val,int level,int w) {
	//����ֵ���м����е�λ��
	//�����д����ң�ż���д��ҵ���
	if(level%2) return val-(level-1)*w;//�±��1��ʼ
	return w-(val-(level-1)*w-1);//��w��ʼ���ǵ�-1������
}
int main() {
	int w,m,n,m_level,n_level,m_pos,n_pos;
	cin>>w>>m>>n;
	m_level = ceil(m*1.0/w);//����ȡ������������
	n_level = ceil(n*1.0/w);
	int dis = max(m_level,n_level)-min(m_level,n_level);//�в�
	n_pos = solve(n,n_level,w);
	m_pos = solve(m,m_level,w);
	cout<<dis+abs(n_pos-m_pos);//�в�+�вΪ��
	return 0;
}
