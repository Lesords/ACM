#include<iostream>//ac
using namespace std;
int main() {
	int n;
	cin>>n;
	int cnt = 0;
	if(n==1) {//����
		cout<<"Nancy"<<endl;return 0;
	}//Nancy���� 
	//����n���Էֽ�Ϊ���ٸ�������
	for(int i = 2;i <= n;i++) {//n�ڱ仯
		while(n%i==0) {//��n��ȫ�ֽ�󣬲�����ַ�����������
			n /= i;//ÿ�ζ���Ҫ����n��ֵ
			cnt++;//����������++
		}
	}//ż���������� ���Բ���������
	if(cnt%2) cout<<"Nancy"<<endl;
	else cout<<"Johnson"<<endl;//ż����������
	return 0;
}
