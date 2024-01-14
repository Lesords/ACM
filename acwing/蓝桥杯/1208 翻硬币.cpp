#include<iostream>//ac
#include<string>
using namespace std;
char change(char ch) {//翻转硬币
	return ch=='o'?'*':'o';
}
int main() {
	string a,b;
	cin>>a>>b;
	int ans = 0;
	for(int i = 0;i < a.size();i++) {//直接遍历
		if(a[i]!=b[i]) {//碰到不一样的翻转两个硬币
			ans++;
			a[i] = change(a[i]);
			a[i+1] = change(a[i+1]);
		}
	}
	cout<<ans;
	return 0;
}
