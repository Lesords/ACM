#include<iostream>//ac
#include<string>
using namespace std;
int main() {
	string a;
	while(cin>>a) {
		if(a.size()%2) {//����
			cout<<"NO"<<endl;
		}
		else {
			int mid = a.size()/2;
			int flag = 0;//0 �� mid �ֱ�Ϊ���
			for(int i = 0,j = mid;j < a.size();i++,j++) {
				if(a[i]!=a[j]) {//�����
					flag = 1;break;
				}
			}
			if(flag) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
	}
	return 0;
}
