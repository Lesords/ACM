#include<iostream>//ac
#include<algorithm>
//����������֮����������룬�ټ����ܺ� 
using namespace std;
int main() {
	int a,b,c;
	cin>>a>>b>>c;
	a = min(a,c+b);
	b = min(b,c+a);
	c = min(c,a+b);
	cout<<a+b+c<<endl;
	return 0;
} 
