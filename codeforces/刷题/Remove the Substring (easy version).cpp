#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int ans = 0;
	string s,t;
	cin>>s>>t;
	for(int i = 0;i < s.size();i++) {
		for(int j = i;j < s.size();j++) {//���������Ӵ�
			int pos = 0;//��ʼ����ʱλ��
			for(int k = 0;k < s.size();k++) {
				if(i<=k&&k<=j) continue;//�����Ӵ�����
				if(pos<t.size()&&s[k]==t[pos]) pos++;
			}
			//�ж�������Ƿ����ƥ��t�����������ֵ
			//���������Ӵ���Ϊɾ�����֣�����
			if(pos==t.size()) ans = max(ans,j-i+1);
		}
	}
	cout<<ans;
	return 0;
}
