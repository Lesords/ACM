#include<iostream>//ac
using namespace std;
int main() {
	int a,b;
	while(cin>>a>>b&&a&&b) {
		int flag = 0;
		for(int i = a*100;i<(a+1)*100;) {
			if(!(i%b)) {//��������
				if(flag) cout<<' ';//��һ�������
				flag = 1;
				if((i%100)<10) cout<<"0"<<i%100;//��λ������
				else cout<<i%100;
				i += b;//������
			}
			else i++;
		}
		cout<<endl;
	}
	return 0;
}
