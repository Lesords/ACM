#include<iostream>//ac
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
string tmp,a[10004];
string change(string tmp) {//ȥ�� < �������ַ���
	stack<char> sta;//��ջ����ʣ���ַ�
	for(int i = 0;i < tmp.size();i++) {
		if(sta.empty()) {//ջΪ��ʱ��Ϊ<�ͱ���
			if(tmp[i]!='<') sta.push(tmp[i]);
		}
		else if(tmp[i]=='<') sta.pop();//����ջ��
		else sta.push(tmp[i]);//��ջ
	}
	tmp = "";
	while(!sta.empty()) {//����ʣ���ַ�
		tmp = sta.top() + tmp;//���ű��棬top��������
		sta.pop();
	}
	return tmp;
}
int main() {
	int cnt = 1,ans = 0,cos;
	while(getline(cin,tmp)) {	//��������
		if(tmp=="EOF") break;	//EOFֹͣ
		tmp = change(tmp);		//�޸�tmp�е�<
		a[cnt++] = tmp;			//�����Ӧ�ַ���
	}
	int num = 1;
	while(getline(cin,tmp)) {	//��������
		if(tmp=="EOF") break;	//EOF����
		if(num>=cnt) continue;	//����������
		tmp = change(tmp);		//�޸�tmp�е�<
		//ȡ���ĺ͵�ǰtmp�Ľ϶�ֵ
		int siz = min(tmp.size(),a[num].size())-1;
		for(int i = 0;i <= siz;i++) {//�����ж��Ƿ�����ͬ�ַ�
			if(a[num][i]==tmp[i]) ans++;
		}
		num++;//�ƶ�����
	}
	cin>>cos;//����cos��
	cout<<int(ans*60.0/cos)<<endl;//�� ��/����
	return 0;
}
