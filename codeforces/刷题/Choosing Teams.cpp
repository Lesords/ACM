#include<iostream>//ac
using namespace std;
int main() {
	int n,k,tmp,cnt = 0;
	cin>>n>>k;
	while(n--) {
		cin>>tmp;
		if(5-tmp>=k) cnt++;//�ﵽ��׼�Ķ�Ա
	}
	cout<<cnt/3<<endl;//һ����������
	return 0;
}
