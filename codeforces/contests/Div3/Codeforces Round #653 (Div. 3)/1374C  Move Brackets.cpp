#include<iostream>//ac
#include<cstdio>
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

//���⣺�ƶ����ο���ʹ��������ƥ��

int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		getchar();//����س���
		stack<char> sta;
		char tmp;
		for(int i = 1;i <= n;i++) {//ȥ�����кϷ�����
			cin>>tmp;
			if(sta.empty()) sta.push(tmp);
			else {
				//ȥ���Ϸ�����
				if(sta.top()=='('&&tmp==')') sta.pop();
				else sta.push(tmp);
			}
		}
		//ֻҪ��������(��������)�Ƶ���(β)����(һ�������)
		cout<<sta.size()/2<<endl;
	}
	return 0;
}
