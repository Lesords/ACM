#include<iostream>//ac
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
int main() {
	string s;
	int n;cin>>n;
	cin>>s;
	int six = 0, one = 0;
	for(int i = 0;i < s.size();i++) {
		if(s[i]=='6') six++;
		else if(s[i]=='1') one++;
	}//�ֱ�ͳ��6��1������
	cout<<min(six-1,one);//6���˿�ͷһ����������ظ�
	//����61616
	return 0;
}
