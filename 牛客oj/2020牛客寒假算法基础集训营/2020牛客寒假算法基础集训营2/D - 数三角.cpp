#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;

//��⣺�۽������ε��ص��� ��ߵ�ƽ�� ���� �������ߵ�ƽ����
//�����ε������� ��� С�� �������ߺ�
//Ҳ���ж� �������� ��б�����ж��Ƿ�Ϊ�����Σ�����

//Ҳ�ɸ��� ������ ������ֵ�ж������ߵĽǶȣ��ж�����
//��Ҳ��Ҫ�ж�������������
//������Ϊ0˵����ֱ������0��Ϊ��ǣ�С��0��Ϊ�۽�

struct node{
	int x,y;
}a[505];
int two(int n) {return n*n;}
bool check(int i,int j,int k) {
	int len[4];
	len[1] = two(a[i].x-a[j].x)+two(a[i].y-a[j].y);//�ߵ�ƽ��
	len[2] = two(a[i].x-a[k].x)+two(a[i].y-a[k].y);
	len[3] = two(a[j].x-a[k].x)+two(a[j].y-a[k].y);
	sort(len+1,len+4);//��С��������
	//��ߵ�ƽ���� ���� �������ߵ�ƽ���� && ��� < �������ߺ�
	if(len[3]>len[2]+len[1]&&sqrt(len[3])<sqrt(len[2])+sqrt(len[1]))
		return true;
	return false;
}
int main() {
	int n,ans = 0;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i].x>>a[i].y;
	for(int i = 1;i <= n;i++) {//��֤���ظ�
		for(int j = i + 1;j <= n;j++) {//i�ĺ�һλ
			for(int k = j + 1;k <= n;k++) {//j�ĺ�һλ
				if(check(i,j,k)) ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
