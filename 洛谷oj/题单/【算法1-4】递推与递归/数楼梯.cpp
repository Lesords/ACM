#include<iostream>//ac
using namespace std;
const int MAXN = 1205;
int _two[MAXN],_one[MAXN],ans[MAXN];
void bigadd() {//�����ӷ�
	int rest = 0;
	for(int i = 1;i < MAXN;i++) {
		ans[i] = _one[i]+_two[i]+rest;
		rest = ans[i]/10;
		ans[i] %= 10;
	}
}
int main() {
	int n,pos;
	_one[1] = 2,_two[1] = 1;
	cin>>n;
	if(n==0) cout<<'0'<<endl;//����0��������
	else if(n<=2) cout<<'1'<<endl;//����ǰ���㣡����
	else {
		for(int i = 3;i <= n;i++) {
			bigadd();
			for(int j = 1;j < MAXN;j++) {
				_two[j] = _one[j];//����ǰ����
				_one[j] = ans[j];//����ǰһ��
			}
		}
		//��λ����λ����Ѱ��pos
		for(int i = MAXN;i >= 1;i--) if(ans[i]) {
			pos = i;break;
		}
		for(int i = pos;i >= 1;i--) cout<<ans[i];
		cout<<endl;
	}
	return 0;
}
