#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
string s[2510];
int cnt = 1,flag;
void solve(int num) {
	int a = 0,b = 0,maxx,minn;
	flag = 1;
	for(int i = 1;i < cnt&&flag;i++) {//flag�жϽ���
		for(int j = 0;j < s[i].size();j++) {//ÿ�еĳ��ȿ��ܲ�һ��
			if(s[i][j]=='E') {//������־
				cout<<a<<":"<<b<<endl;//���ʣ��ȷ�
				//��ʹ����Ϊ0ҲҪ���������
				flag = 0;break;//����
			}
			if(s[i][j]=='W') a++;
			else if(s[i][j]=='L') b++;
			maxx = max(a,b);
			minn = min(a,b);
			if(maxx>=num&&maxx-minn>=2) {
			//�����Ӧ�����ҷֲ����2
				cout<<a<<":"<<b<<endl;
				a = b = 0;//��0
			}
		}
	}
}
int main() {
	while(cin>>s[cnt]) cnt++;//������������
	solve(11);//11����
	cout<<endl;
	solve(21);//21����
	return 0;
}
