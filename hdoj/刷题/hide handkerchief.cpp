#include<iostream>//ac
using namespace std;
int gcd(int a,int b) {
	return a%b==0?b:gcd(b,a%b);
}
int main() {
	int a,b;
	//�ж���Ӧ�ļ���Ƿ�����ҵ�������ʵ�����ж��������
	while(cin>>a>>b) {
		if(a==-1&&b==-1) break;
		if(gcd(a,b)!=1) cout<<"POOR Haha"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
} 
