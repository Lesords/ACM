#include<iostream>//ac
#include<string>
using namespace std;
int main() {
	int n;
	string a;
	cin>>n>>a;
	for(int i = 0;i < a.size();i++) {
		a[i] = (a[i] - 'a' + n)%26 + 'a';//26¸ö×ÖÄ¸£¡£¡£¡
	}
	cout<<a<<endl;
	return 0;
}
