#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
	int n,tmp,ans = 0;
	cin>>n;//���ڵ��������ģ����Դ� 0 ��ʼ
	for(int i = 0;i < n;i++) {//��Ҫ������Ϊ �±� + ��������
		cin>>tmp, ans = max(ans, tmp + i);
	}
	cout<<ans<<endl;
	return 0;
}
