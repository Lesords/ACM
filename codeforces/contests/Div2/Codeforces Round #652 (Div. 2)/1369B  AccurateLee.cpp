#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
int main() {
	int t,n;
	string s;
	cin>>t;
	while(t--) {
		cin>>n>>s;
		//clear����û���ͷ��ڴ棡����
		int last,first;
		for(int i = 0;i < s.size();i++) if(s[i]=='1') {
			//Ѱ�ҵ�һ�����ֵ�1
			first = i;break;
		}
		for(int i = s.size()-2;i > first;i--) {
			//�ȴӺ���ǰɾ�����п���ɾ����1��������һ��1��
			if(s[i]=='1'&&s[i+1]=='0') s.erase(i,1);
		}
		for(int i = s.size()-1;i >= 0;i--) if(s[i]=='0') {
			//Ѱ�������ֵ�0
			last = i;break;
		}
		for(int i = 0;i < s.size();i++) {
			//�ٴ�ǰ����ɾ�����п���ɾ����0���������һ��0��
			if(s[i]=='1'&&s[i+1]=='0') {
				int pos;
				for(int j = i+1;j < s.size();j++) {
					if(s[j]!='0'||j==last) {
						pos = j;break;
					}
				}
				//iΪ1��posΪ��Ϊ0��λ��
				//pos-iΪ0�ĳ���
				if(pos!=last) s.erase(i+1,pos-i);
				else s.erase(i+1,last-1-i);
			}
		}
		//�����ɾ��һ��1����
		for(int i = 0;i < s.size()-1;i++) {
			if(s[i]=='1'&&s[i+1]=='0') s.erase(i,1);
		}
		cout<<s<<endl;
	}
	return 0;
}
