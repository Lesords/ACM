#include<iostream>//ac
#include<string>
using namespace std;
string a[205];
int main() {
	int len = 0,cnt = 1,num = 0,op = '0';//��һ���ַ�ʱ�ж�'0'
	//�����������������õ�ϵͳ��һ�������Իس���Ҳ��һ��
	//getline����һ���س���
	while(cin>>a[cnt]) {
		if(!len) len = a[cnt].size();//��¼len
		cnt++;
	}
	cout<<len;//�ַ������ȼ�Ϊ�����N
	for(int i = 1;i < cnt;i++) {//���������ַ���
		for(int j = 0;j < a[i].size();j++) {//�����ַ����������ַ�
			if(a[i][j]==op) num++;//����뵱ǰ�ַ�һ��
			else {//��һ��
				cout<<" "<<num;//���num
				num = 1;//����num����ǰ��һ����
				op = (op=='0')?'1':'0';//op�ַ�Ϊ�෴
			}
		}
	}
	cout<<' '<<num;//���϶�����һ��num����ĩβδ���
	return 0;
}
