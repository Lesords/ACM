#include<iostream>//ac
using namespace std;
int main() {
	int n;
	while(cin>>n) {
		int sum = 0,cnt = 0,floor = 0;
		while(sum<=n) {
			cnt++;//����++
			floor += cnt;//ÿ��ĸ���
			sum += floor;//ȫ������
		}
		cout<<--cnt<<endl;//��ȥ�����һ��
	}
	return 0;
}
