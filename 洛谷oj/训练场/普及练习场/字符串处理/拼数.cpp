#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
string a[25];//字符串数组
bool cmp(string a,string b) {//string本身具有大小比较
	return a+b>b+a;//按顺序的值更大
}
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i <= n;i++) cout<<a[i];
	return 0;
}
