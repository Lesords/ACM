#include<iostream>//ac
#include<string>
using namespace std;
string solve(int n) {
	string ans = "";//��ʼ���ַ���
	int pos = 0;//��ʾ��ǰ����λ��
	if(n==0) return "0";//0��ֵֻΪ0
	while(n) {
		if(n&1) //�������ж��Ƿ���Ҫ����ַ�
		ans = "2"+(pos==1?"":("("+solve(pos)+")"))+(ans==""?"":"+")+ans;
		//2�Ǳر��ַ���Ȼ���ж��Ƿ���Ҫ����
		//���ָ��Ϊ1����posΪ1ʱ�����������
		//����ݹ����solve�����ó������ڵ��ַ���
		//����ж��Ƿ���"+"�����ԭ�ַ���Ϊ������Ҫ
		n >>= 1,pos++;
	}
	return ans;
}
int main() {
	int n;
	cin>>n;
	cout<<solve(n)<<endl;
	return 0;
}
