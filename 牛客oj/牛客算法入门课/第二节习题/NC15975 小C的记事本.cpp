#include<iostream>//ac
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int q,op,k;
	while(cin>>q) {//��������
		stack<string> sta;//�����ʷ�ַ���
		string ans,tmp;
		while(q--) {
			cin>>op;
			//�ָ�Ϊǰһ���ַ�������������Ӧ�ַ���
			if(op==4) ans = sta.top(),sta.pop();
			else {
				if(op==3) {
					cin>>k;
					//�±��0��ʼ����-1
					cout<<ans[k-1]<<"\n";
				}
				else if(op==1) {
					cin>>tmp;
					sta.push(ans);//������ʷ�ַ���
					ans += tmp;
				}
				else if(op==2) {
					cin>>k;
					sta.push(ans);//������ʷ�ַ���
					//ɾ���ַ�����k���ַ�
					ans.erase(ans.size()-k,k);
					//erase������һ��������ʾ��㣬�ڶ���Ϊ����
				}
			}
		}
	}
	return 0;
}
