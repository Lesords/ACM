#include<iostream>//ac
using namespace std;

//��⣺��������ݳʽ���������д�����ҵ�����
//�����㣺�Ӵ�С / ��С���� (��ΧΪ 1 - lay)
//ż���㣺��С���� / �Ӵ�С (��ΧΪ 1 - lay)

//         1/1
//      2/1   1/2 <- 
// -> 3/1  2/2  1/3
//  4/1 3/2 2/3 1/4 <-

int main() {
	int n,cnt = 1,lay = 1;
	cin>>n;
	while(cnt<n) lay++,cnt += lay;//���lay����
	int rest = n - (cnt-lay);//��ǰ����ʣ�༸��
	if(lay%2) cout<<lay-rest+1<<'/'<<rest;
	else cout<<rest<<'/'<<lay-rest+1;
	return 0;
} 
