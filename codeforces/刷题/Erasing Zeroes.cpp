#include<iostream>//ac
#include<string>
using namespace std;
int main() {
	int t;
	string s;
	cin>>t;
	while(t--) {
		cin>>s;
		int ans = 0;
		if(s.size()==1) {//�����ַ�����СΪ1
			cout<<"0"<<endl;
			continue;
		}
		while(s[0]=='0') s.erase(0,1);//ɾ��ǰ��0�ͺ���0
		while(s[s.size()-1]=='0') s.erase(s.size()-1,s.size());
		for(int i = 0;i < s.size();i++) {
			if(s[i]!='1') ans++;//�����м䲿���ж��ٲ���1
		}
		cout<<ans<<endl;
	}
	return 0;
}
