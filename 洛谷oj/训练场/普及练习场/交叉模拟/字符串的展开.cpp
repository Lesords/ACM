#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//ע�⣺�ж�����Ų��е�����

string s;
void solve(int p1,int p2,int p3) {
	//p1��������, p2��������, p3��˳�����
	string ans = "",tmp;
	for(int i = 0;i < s.size();i++) {
		tmp = "";//ÿ�β������ַ�������ʼ��Ϊ0
		if(s[i]!='-') ans += s[i];//��Ϊ���Ų���Ӱ��
		else {
			//�����ڳ�ʼλ�ã�ǰһ��λ��ҲΪ����
			//����ǰ�������ַ�һ�£������������������
			if(s[i-1]==s[i+1]||i==0||s[i-1]=='-') {
				ans += s[i];continue;
			}
			//����չ������ʱ
			if(s[i-1]<='9'&&s[i+1]<='9'|| 	//ͬΪ����
			s[i-1]>='a'&&s[i+1]>='a') {     //ͬΪСд��ĸ
				if(s[i-1]+1==s[i+1]) continue;//ǰ��һ������
				for(char c = s[i-1]+1;c < s[i+1];c++) {//��������һλ
					for(int t = 1;t <= p2;t++) {//�ظ�����
						if(p1==3) tmp += '*';
						else if(c>='a') {
							tmp += p1==1?c:toupper(c);
						}
						else tmp += c;
					}
				}//p3Ϊ2������
				if(p3==2) reverse(tmp.begin(),tmp.end());
				//ǰһλ���ں�һλʱtmpΪ�գ����ű���
				if(tmp=="") tmp = '-';
				ans += tmp;
			}
			else ans += s[i];//����չ��
		}
	}
	cout<<ans<<endl;
}
int main() {
	int p1,p2,p3;
	cin>>p1>>p2>>p3;
	cin>>s;
	solve(p1,p2,p3);
	return 0;
}
/*
����1:
2 2 2
9-a-a

9-a-a

����2:
1 1 1
---9-9

---9-9

����3:
1 1 1
4-1-2

4-12
*/
