#include<iostream>//ac
#include<algorithm> 
using namespace std;
char a[200005];
int main() {
	int n,zero = 0,one = 0;
	cin>>n>>a;
	for(int i=0;i<n;i++) {
		if(a[i]=='0') zero++;
		else one++;
	}//0 1�ܻ����ڣ�n -����С������*2
	//����abs(zero-one) 
	cout<<n-(min(one,zero))*2<<endl;
	return 0;
}
