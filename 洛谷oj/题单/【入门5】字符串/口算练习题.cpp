#include<iostream>//ac
#include<string>
#include<cstdio>
#define to(i) to_string(i)
using namespace std;
int change(string n) {//�ַ���ת������
	int ans = 0;
	for(int i = 0;i < n.size();i++) {
		ans = ans*10+(n[i]-'0');
	}
	return ans;
}
int main() {
	int t,tmp,a,b,ans;
	string op;
	cin>>t;
	while(t--) {
		cin>>op;
		if(op.size()==1) {//��Ϊ����
			if(op=="a") tmp = 1;//tmpΪ��������
			else if(op=="b") tmp = 2;
			else tmp = 3;
			cin>>a>>b;
		}
		else a = change(op),cin>>b;//�޸�a��ֵ
		if(tmp==1) ans=a+b,printf("%d+%d=%d\n",a,b,ans);
		else if(tmp==2) ans=a-b,printf("%d-%d=%d\n",a,b,ans);
		else ans=a*b,printf("%d*%d=%d\n",a,b,ans);
		cout<<to(a).size()+to(b).size()+to(ans).size()+2<<endl;
		//���������תΪ�ַ��������жϳ��ȣ��������������
	}
	return 0;
}
