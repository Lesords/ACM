#include<iostream>//ac
#include<string>
#include<map>
#include<algorithm>
using namespace std;
string num[30] = {"","one","two","three","four","five","six","seven",
"eight","nine","ten","eleven","twelve","thirteen","fourteen",
"fifteen","sixteen","seventeen","eighteen","nineteen","twenty",
"a","both","another","first","second","third"};
string a[10],cnt[10];
int uno[10] = {1,2,1,1,2,3};//���������֣�����
bool cmp(string a,string b) {//�ַ����Դ��Ƚ�
	return a+b < b+a;//��С����
}
int main() {
	map<string,int> map;//����Ӣ��ת���ֺ�Ľ��
	for(int i = 1;i <= 20;i++) map[num[i]] = (i*i)%100;
	for(int i = 0;i <= 5;i++) map[num[i+21]] = (uno[i]*uno[i])%100;
	int cas = 1;
	for(int i = 1;i <= 7;i++) {
		cin>>a[i];
		if(i==7) continue;//ֻ��6����Ч����
		if(map[a[i]]) {//���ڴ��ַ���
			int tmp = map[a[i]];
			if(tmp<10) {//ֻ��һλ��
				char ch = tmp%10 + '0';//��λ��
				cnt[cas] = '0';//ǰ�油��һλ0
				cnt[cas] += ch;
			}
			else {
				char left = tmp/10%10 + '0';//ʮλ���ַ�
				char right = tmp%10 + '0';//��λ���ַ�
				cnt[cas] = left;
				cnt[cas] += right;
			}
			cas++;//��������ָ�������һλ
		}
	}
	if(cas==1) {//����������
		cout<<'0';return 0;
	}
	sort(cnt+1,cnt+cas,cmp);//�Զ�������
	string ans = "";//���ڱ�����
	for(int i = 1;i < cas;i++) ans += cnt[i];
	while(ans[0]=='0'&&ans.size()>1) ans.erase(0,1);//ȥ����ͷ0
	cout<<ans<<endl;
	return 0;
}
