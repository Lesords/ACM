#include<iostream>//ac
using namespace std;
int rule[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},
{0,0,1,0,1},{1,1,0,0,0}};//��Ӧa->b�ĵ÷ֱ�
int a[205],b[205]; 
int main() {
	int n,na,nb,sc_a = 0,sc_b = 0;
	cin>>n>>na>>nb;
	for(int i = 1;i <= na;i++) cin>>a[i];//Ҳ�ɴ�0��ʼ
	for(int i = 1;i <= nb;i++) cin>>b[i];//��ֱ��%ҲΪѭ��
	for(int i = 1;i <= n;i++) {//�ȼ�һ % ���һ�ɴ�ѭ��
		sc_a += rule[a[(i-1)%na+1]][b[(i-1)%nb+1]];
		sc_b += rule[b[(i-1)%nb+1]][a[(i-1)%na+1]];
	}//���������ÿ�α����ĵ÷�
	cout<<sc_a<<' '<<sc_b;
	return 0;
}
