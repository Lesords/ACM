#include<iostream>//ac
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;//n����ʼֵ��m��Ŀ��ֵ
	if(n>m) cout<<n-m<<endl;//��ʼֵ��,ֻ���ü�����
	else {//����˼ά,�˱��,����ӣ������޷��жϳ˵�ʱ����
		int cnt = 0;
		while(n<m) {
			m%2?m++:m/=2;
			cnt++;//mС�ڻ����n�Ĳ���
		} 
		cout<<cnt+n-m<<endl;//cnt�ټ�����ֵ��
	}
	return 0;
}
