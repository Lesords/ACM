#include<iostream>//ac
#define ll long long
using namespace std;
ll a[45] = {0,3,8};
int main() {
	//���һ���ַ�ΪE��F����С��Ϊa[n-1]
	//���һ���ַ�ΪO,���n-1���ַ�ֻ��ΪE��F
	//��С����Ϊa[n-2]
	for(int i = 3;i <= 40;i++)
		a[i] = 2*a[i-1] + 2*a[i-2];
	int n;
	while(cin>>n) cout<<a[n]<<endl;
	return 0;
}
