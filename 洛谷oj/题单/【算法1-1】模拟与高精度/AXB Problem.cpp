#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 5005;
string s1,s2;
int a[MAXN],b[MAXN],ans[MAXN],pos;
void multi() {//�����˷�
	for(int i = 1;i <= s1.size();i++) {//��λ��
		for(int j = 1;j <= s2.size();j++) {
			ans[i+j-1] += a[i]*b[j];//λ��Ϊ i+j-1
			ans[i+j] += ans[i+j-1]/10;
			ans[i+j-1] %= 10;
		}//���ڸ���λ�õ�ֵΪ��ͬλ����˵ĺͣ������������
	}
}
int main() {
	cin>>s1>>s2;//�ַ���ת����
	for(int i=s1.size()-1,j=1;i >= 0;i--,j++) a[j] = s1[i]-'0';
	for(int i=s2.size()-1,j=1;i >= 0;i--,j++) b[j] = s2[i]-'0';
	multi();
	for(int i = MAXN-1;i >= 1;i--) if(ans[i]) {
		pos = i;break;
	}
	for(int i = max(pos,1);i >= 1;i--) cout<<ans[i];
	return 0;
}
