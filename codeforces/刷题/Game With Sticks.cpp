#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	//ÿ�β����ܻ�����һ����ֱ����һ��ˮƽ��
	//�жϴ�ֱ��ˮƽ����С����
	//������������AkshatӮ������MalvikaӮ
	if(min(n,m)%2) cout<<"Akshat"<<endl;
	else cout<<"Malvika"<<endl;
	return 0;
}
