#include<iostream>//ac
#include<cstdio>
#include<stack>
using namespace std;

//��⣺�жϵ�ǰ��ջ�Ƿ����������ֵ
//�����������������ջ
//����ж�ջ�Ƿ���ʣ����ֵ������������

int main() {
	int n,tmp,num;
	stack<int> s;
	scanf("%d",&n);
	num = n;//������¼��ǰ�����ֵ
	for(int i = 1;i <= n;i++) {
		scanf("%d",&tmp);
		if(tmp==num) {//Ϊ��ǰ���ֵ
			if(num!=n) cout<<' ';//��һ��������ո�
			cout<<tmp;//���
			num--;//�޸ĵ�ǰ���ֵ
		}
		else s.push(tmp);//��ջ
	}
	while(!s.empty()) {
		if(s.top()!=n) cout<<' ';//��һ��������ո�
		cout<<s.top();//��˳���������
		s.pop();
	}
	return 0;
}
