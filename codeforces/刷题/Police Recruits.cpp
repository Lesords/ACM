#include<iostream>//ac
using namespace std;
int main() {
	int n,tmp,ans = 0,man = 0;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>tmp;
		if(tmp!=-1) man+=tmp;//�о���
		else man?man--:ans++;//ץ�ﷸ���о�����--������ans++
	}
	cout<<ans<<endl;
	return 0;
} 
