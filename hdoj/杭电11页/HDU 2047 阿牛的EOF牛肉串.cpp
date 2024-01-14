#include<iostream>//ac
#define ll long long
using namespace std;
ll a[45] = {0,3,8};
int main() {
	//最后一个字符为E或F，大小都为a[n-1]
	//最后一个字符为O,则第n-1个字符只能为E或F
	//大小都是为a[n-2]
	for(int i = 3;i <= 40;i++)
		a[i] = 2*a[i-1] + 2*a[i-2];
	int n;
	while(cin>>n) cout<<a[n]<<endl;
	return 0;
}
