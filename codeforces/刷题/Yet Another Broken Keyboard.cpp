#include<iostream>//ac
#include<map>
#include<string>
#define ll long long
using namespace std;
ll ans,cnt;//cntΪ �����ַ��� ����
int main() {
	int n,k;
	string s;
	cin>>n>>k>>s;
	map<char,int> map;
	char tmp;
	for(int i = 1;i <= k;i++) cin>>tmp,map[tmp] = 1;//��¼���õ��ַ�
	for(int i = 0;i < n;i++) {
		if(!map[s[i]]||i == n-1) {//����ַ������û���Ϊ�ַ�ĩβ
			if(map[s[i]]) cnt++;//�����ַ�ĩβ�Ƿ����
			ans += cnt*(cnt + 1)/2;//�Ӵ�����Ϊ cnt*(cnt + 1)/2
			cnt = 0;//����
		}
		else cnt++;//�ַ�����
	}
	cout<<ans<<endl;
	return 0;
}
