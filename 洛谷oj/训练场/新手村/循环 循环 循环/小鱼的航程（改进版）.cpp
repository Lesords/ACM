#include<iostream>//ac
using namespace std;
int main() {
	int x,n,ans = 0;
	cin>>x>>n;
	while(n--) {//ʱ����
		if(x<=5) ans += 250;//����ĩ
		//x = x%7 + 1; �Ƚ�����
		x++;
		if(x>7) x = 1;
	}
	cout<<ans<<endl;
	return 0;
} 
