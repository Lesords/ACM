#include<iostream>//ac
using namespace std;
int op[6] = {100,20,10,5,1};
int main() {
	int n,ans = 0,tmp;
	cin>>n;
	//��ֵԽ��������Խ��
	for(int i = 0;i < 5;i++) {//ֱ���ж����ֱ�ֵ������
		tmp = n/op[i];	//��ǰ��ֵ������
		ans += tmp;		//�������
		n %= op[i];		//ȥ����Ӧ�Ľ��
		if(n==0) break;	//������ȫ���꣩
	}
	cout<<ans<<endl;
	return 0;
}
