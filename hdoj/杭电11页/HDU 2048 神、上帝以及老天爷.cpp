#include<cstdio>//ac
using namespace std;
double sum[25],wrong[25]; 
int main() { 
	int n;
	sum[1] = 1;
	for(int i=2;i<25;i++) {//ȫ�����
		sum[i] = sum[i-1] * i;
	}
	wrong[1] = 0;
	wrong[2] = 1;
	for(int i = 3;i<25;i++) {//��û�е���������ţ�
		wrong[i] = (i-1) * (wrong[i-1]+wrong[i-2]);
	}//��һ������i-1ѡ�� * �ڶ������Ƿ����˵�һ���˵�����
	scanf("%d",&n);
	while(n--) {
		int tmp;
		scanf("%d",&tmp);
		printf("%.2f%%\n",wrong[tmp]/sum[tmp]*100);
	}
	return 0;
}
