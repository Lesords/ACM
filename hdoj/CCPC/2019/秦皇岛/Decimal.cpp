#include<iostream>//ac
#include<cstring>
//�ⷨ1���ж��Ƿ�Ϊѭ��С����ֻ��Ҫ�ж������Ƿ��ظ�����
//�ⷨ2:1ֻ�г���2��5�ſ��Գ��������Կ���ֻ�жϳ����Ƿ��а���2��5�ı���
using namespace std;
int book[105];//��������������С��Ϊ��������
int main() {
	int t,a;
	cin>>t;
	while(t--) {
		cin>>a;
		int flag = 1,num = 1;//Ĭ��Ϊ����С��
		memset(book,0,sizeof(book));//��ʼ��
		while(num) {
			if(num<a) num *= 10;
			else {
				if(book[num%a]) {
					flag = 0;
					break;
				}
				book[num%a] = 1;//�������
				num %= a;
			}
		}
		if(flag) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
