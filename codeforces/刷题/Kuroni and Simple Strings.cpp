#include<iostream>//ac
#include<string>
using namespace std;
int ansa[1005],ansb[1005];
int main() {
	string s;
	cin>>s;
	int l = 0,r = s.size()-1;
	int a = 0,b = 0;
	while(l<=r) {//��ͬʱ�������һ��λ��
		while(l<=r&&s[l]!='(') l++;//��������
		while(l<=r&&s[r]!=')') r--;//��������
		if(l<=r) {
			ansa[++a] = l+1;//���Ϊ0�����1
			ansb[++b] = r+1;
			l++,r--;//ɸ��֮���ƶ�ָ�룡����
		}
	}
	if(!a||!b) cout<<"0\n";//û���㹻������
	else {
		cout<<"1\n"<<a+b<<endl;//һ��ɸ�����еĿ�ƥ������
		for(int i = 1;i <= a;i++) cout<<ansa[i]<<' ';//�������±�
		for(int i = b;i >= 1;i--) cout<<ansb[i]<<' ';//�������±�
	}//�������
	return 0;
}
