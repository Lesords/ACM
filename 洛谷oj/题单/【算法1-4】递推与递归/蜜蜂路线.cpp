#include<iostream>//ac
using namespace std;
const int MAXN = 305;
int a[MAXN],b[MAXN],ans[MAXN];
void bigadd() {
	//����ֵ������һ������ֱ�ӽ�λ����ѽ�λ�����ˣ�����
	int rest = 0;//���Կ���ʱ���������λ��
	for(int i = 1;i < MAXN;i++) {
		ans[i] = a[i]+b[i]+rest;//�ȺŻ�����ԭ�ȵĽ�λ��
		rest = ans[i]/10;		//�ӺŵĻ���Ҫ�������
		ans[i] %= 10;
	}
}
int main() {
	int n,m,pos;
	a[1] = b[1] = 1;
	cin>>m>>n;
	if(n-m+1<=2) cout<<'1'<<endl;
	else {
		for(int i = 3;i <= n-m+1;i++) {
			bigadd();//�ۼӲ���
			for(int j = 1;j < MAXN;j++) {
				b[j] = a[j];//����ǰ����
				a[j] = ans[j];//����ǰһ��
			}
		}
		for(int i = MAXN-1;i >= 1;i--) if(ans[i]) {
			pos = i;break;//�ҵ������
		}
		for(int i = pos;i >= 1;i--) cout<<ans[i];
		cout<<endl;
	}
	return 0;
}
