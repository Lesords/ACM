#include<iostream>//ac
#include<string>
#include<map>
#include<algorithm>
using namespace std;

//���⣺����ַ���ƴ�ӳ�һ�����Ĵ�
//��⣺���԰�Ŀ�Ļ��Ĵ������������֣�������
//��ߵ����ұߵķ������м�Ϊ���Ĵ�
//�����м䴮ֻ����һ�����������Ĵ�ƴ�ӾͲ��ǻ��Ĵ��ˣ���Ψһ��

string s[105];
string change(string n) {//����һ������
	string tmp = "";
	if(n=="") return n;
	for(int i = n.size()-1;i>=0;i--) tmp += n[i];
	return tmp;
}
int main() {
	string mid,l,r,tmp;
	mid = l = r = "";
	map<string,int> map;
	int n,m,ans = 0;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) {
		cin>>s[i];
		tmp = change(s[i]);
		if(mid==""&&tmp==s[i]) mid = s[i];//mid������Ĵ�
		else {
			if(map[tmp]) {//�練������
				l += s[i];//���Ϊ����
				r = tmp + r;//�ұ�Ϊ����
			}
			map[s[i]] = 1;//��ǵ�ǰ��
		}
	}
	ans = mid.size()+l.size()+r.size();//��¼�ܴ���С
	if(ans==0) cout<<ans<<"\n\n";
	else cout<<ans<<"\n"<<l<<mid<<r<<"\n";
	return 0;
}
