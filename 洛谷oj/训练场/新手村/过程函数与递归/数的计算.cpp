#include<iostream>//ac  ֱ�ӵݹ�ᳬʱ
using namespace std;
int book[1005];
int solve(int n) {//n����ԭ��
	int tmp = 0;
	if(book[n]) return book[n];//�Ѽ��㣬ֱ�ӷ���
	for(int i = 1;i <= n/2;i++) {
		tmp += solve(i);//ÿ�εݹ��ʱ�򶼻ᱣ�����ֵ
	}
	return book[n] = tmp + 1;//���仯����
}
int main() {
	int n;
	cin>>n;
	cout<<solve(n)<<endl;
	return 0;
}
