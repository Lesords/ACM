#include<iostream>//ac
#include<cstring>
#include<string>
using namespace std;
const int MAXN = 1e5 + 5;
char a[MAXN];
int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>a;
		int flag = 0;
		int len = strlen(a) - 1;
		for(int i = 0;i <= len;i++) {
			if(i+1<=len&&a[i]==a[i+1]&&a[i]!='?') {//�ж��Ƿ���������ַ�
				flag = 1;
				break;
			}
			if(a[i]=='?') {
				if(i==0) a[i] = (a[i+1]-'a'+1)%3 + 'a';//��һ��λ��
				else if(i==len) a[i] = (a[i-1]-'a'+1)%3 + 'a';//���һ��λ��
				else {
					//ǰ����ͬ�ͺ���Ϊ��Ϊһ�����
					//ǰ��ͬ��ʱ��a+b+c = 3*'a' + 3 
					if(a[i-1]==a[i+1]||a[i+1]=='?') a[i] = (a[i-1]-'a'+1)%3 + 'a';
					else a[i] = 'a'+'a'+'a'+3-a[i-1]-a[i+1];
				}
			}
		}
		if(flag) cout<<"-1"<<endl;
		else cout<<a<<endl;
	}
	return 0;
}
