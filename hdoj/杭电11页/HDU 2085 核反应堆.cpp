#include<iostream>//ac
#define ll long long
using namespace std;
int main() {
	int n;
	while(cin>>n) {
		if(n==-1) break;
		ll high = 1,low = 0;
		while(n--) {
			//���� = 3 * ���� + 2 * ����
			//���� = ���� + ����
			//����ʱ��������ߡ������ʵ���,Ȼ��ʵʱ���¼���
			ll tmp_high = 3*high + 2*low;
			ll tmp_low = high + low;
			high = tmp_high;
			low = tmp_low;
		}
		cout<<high<<", "<<low<<endl;
	}
	return 0;
}
