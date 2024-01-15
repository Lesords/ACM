#include<iostream>//ac
#include<string>
using namespace std;
string toChr(string num) {//���ָ�Ϊ��ĸ
	string ans = "";
	int tmp = 0;
	for(int i = 0;i < num.size();i++) {
		tmp = tmp*10+int(num[i]-'0');
	}//�ȸ�Ϊ��������
	char ch;
	while(tmp) {
		ch = (tmp%26-1+26)%26+'A';//��ǰλ
		ans = ch+ans;
		tmp /= 26;
		if(ch=='Z') tmp--;//chΪZ(26)ʱ�����λ���1������
	}
	return ans;
}
int toNum(string chr) {//�ַ�����Ϊ����
	int num = 0;
	for(int i = 0;i < chr.size();i++) {
		num = num*26+int(chr[i]-'A'+1);
	}
	return num;
}
bool check(string s) {//�ж������ָ�ʽ
	if(s[0]=='R'&&s[1]>='0'&&s[1]<='9') {
		for(int i = 2;i < s.size();i++) {
			if(s[i]=='C') return 1;
			//R����C���ָ�ʽ
		}
	}
	return 0;
}
int main() {
	int n;
	string s;
	cin>>n;
	while(n--) {
		cin>>s;
		if(check(s)) {
			string row = "",col= "";
			int flag = 0;
			for(int i = 1;i < s.size();i++) {
				if(s[i]=='C') {//CΪ�ָ��ߣ�����
					flag = 1;continue;
				}
				if(!flag) row += s[i];//���к���
				else col += s[i];
			}
			//��ĸ������Ϊ���к���
			cout<<toChr(col)<<row<<"\n";
		}
		else {
			string row = "",col = "";
			int flag = 0;
			for(int i = 0;i < s.size();i++) {
				if(s[i]>='0'&&s[i]<='9') flag = 1;//�������ͼ�Ϊ�ָ�
				if(!flag) col += s[i];
				else row += s[i];
			}
			cout<<"R"<<row<<"C"<<toNum(col)<<"\n";
		}
	}
	return 0;
}
