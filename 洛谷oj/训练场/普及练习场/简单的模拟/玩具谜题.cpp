#include<iostream>//ac
#include<cstdio>
using namespace std;

//��⣺ģ���ж�ÿ���ߵķ��򼴿�
//��ʱ�룺����+���ߣ�0+1��������+���ߣ�1+0��
//˳ʱ�룺����+���ߣ�0+0��������+���ߣ�1+1��

const int MAXN = 1e5+5;
int a[MAXN];
char name[MAXN][15];//��ά����
int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i]>>name[i];
	int op,step,now = 1;
	for(int i = 1;i <= m;i++) {
		cin>>op>>step;//ע��a���±�Ϊ��ǰλ�ã�now��������
		if((a[now]+op)%2) {//��ʱ��
			now = (now+step)%n;
			if(!now) now = n;//Ϊ0ʱתΪn
		}
		else {//˳ʱ��
			now -= step;
			if(now<=0) now += n;//Ϊ������ʱ+n
		}
	}
	cout<<name[now]<<endl;
	return 0;
}
