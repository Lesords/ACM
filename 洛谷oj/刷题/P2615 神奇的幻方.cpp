#include<iostream>//ac
#include<cmath>
using namespace std;
const int MAXN = 50;
int a[MAXN][MAXN];
struct node{
	int x,y;
}last;//������һ�����λ��
int main() {
	int n,maxx;
	cin>>n;
	//2.0����С�����ܹؼ�������
	a[1][(int)ceil(n/2.0)] = 1;//��ʼ���λ��
	maxx = n*n;//����
	last.x = 1,last.y = int(ceil(n/2.0));
	
	for(int i = 2;i <= maxx;i++) {
		//�ڵ�һ�е��������һ��
		if(last.x==1&&last.y!=n) {
			a[last.x=n][++last.y] = i;
		}
		//�����һ�е����ڵ�һ��
		else if(last.x!=1&&last.y==n) {
			a[--last.x][last.y=1] = i;
		}
		//�ڵ�һ�����һ��
		else if(last.x==1&&last.y==n) {
			a[++last.x][last.y] = i;
		}
		//�Ȳ��ڵ�һ�У�Ҳ�������һ��
		else if(last.x!=1&&last.y!=n) {
			if(a[last.x-1][last.y+1]==0) {
				a[--last.x][++last.y] = i;
			}
			else {
				a[++last.x][last.y] = i;
			}
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(j!=1) cout<<' ';
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}
