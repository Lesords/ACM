#include<iostream>//ac
#include<cmath>
using namespace std;
int gcd(int a,int b) {
	return a%b==0?b:gcd(b,a%b);
}
void solve(int a, int b) {
	int flag = 0;
	int cmn = gcd(a,b);//������е� ��ĸ���� ������
	if(a*b<0) flag = 1;//��Ҫ����
	a = abs(a), b = abs(b);
	if(flag) cout<<"-";//��Ҫ�ر�����
	cout<<abs(a/cmn)<<"/"<<abs(b/cmn)<<endl;
}
int main() {
	int t,op;
	cin>>t;
	while(t--) {
		int a,b,c,d;
		cin>>op>>a>>b>>c>>d;
		int down = b*d;//ֱ���㼴�ɣ�gcd����жϼ���
		if(op) {
			int up = a*d + c*b;
			solve(up,down);
		}
		else {
			int up = a*d - c*b;
			solve(up,down);
		}
	}
	return 0;
}
