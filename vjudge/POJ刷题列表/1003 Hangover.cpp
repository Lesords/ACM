#include<iostream>//ac
using namespace std;
int main() {
	double a;
	while(cin>>a) {
		if(a==0) break;//0��������
		double ans = 0,cnt = 1;
		while(ans<a) {//ans������¼���ҵĳ���
			cnt++;//������++
			ans += 1.0/cnt;//��2��ʼ���㣨1����
		}
		cout<<cnt-1<<" card(s)"<<endl;
	}
	return 0;
} 
