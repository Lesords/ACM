#include<iostream>//ac
using namespace std;

//��Ŀ����������Ϊ 1e6* λ�� 7 �����Ӷ�ҲֻΪ 7e6
//���Դ�0��ʼ���������� ǰ׺����� �������
 
const int MAXN = 1e6 + 5;
int book[15] = {1,0,0,0,1,0,1,0,2,1},a[MAXN];
int main() {
	for(int i = 1;i < MAXN;i++) {//����ȫ������
		int tmp = i,cnt = 0;
		while(tmp) {//����ÿ�����ֵ�ȦȦ
			cnt += book[tmp%10];
			tmp /=10;
		}
		a[i] = a[i-1] + cnt;
	}
	int t;cin>>t;
	while(t--) {
		int left,right;
		cin>>left>>right;
		cout<<a[right] - a[left - 1]<<endl;//left����һλ
	}
	return 0;
}
