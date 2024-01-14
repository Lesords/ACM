#include<cstdio>//ac
using namespace std;
double sum[25],wrong[25]; 
int main() { 
	int n;
	sum[1] = 1;
	for(int i=2;i<25;i++) {//全部情况
		sum[i] = sum[i-1] * i;
	}
	wrong[1] = 0;
	wrong[2] = 1;
	for(int i = 3;i<25;i++) {//都没中的情况（错排）
		wrong[i] = (i-1) * (wrong[i-1]+wrong[i-2]);
	}//第一个人有i-1选择 * 第二个人是否拿了第一个人的字条
	scanf("%d",&n);
	while(n--) {
		int tmp;
		scanf("%d",&tmp);
		printf("%.2f%%\n",wrong[tmp]/sum[tmp]*100);
	}
	return 0;
}
