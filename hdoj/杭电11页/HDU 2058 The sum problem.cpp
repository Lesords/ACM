#include<iostream>//ac
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	long long a,b;
	while(cin>>a>>b&&a+b) {
		//(1+len)/2*len = m
		//=> len < sqrt(2 * m)
		for(int i = sqrt(2*b);i >= 1;i--) {
			//�������˵�����ԽС,�����С��������!!!
			//�Ȳʽ�Ƶ����׼�β��2��n
			long long begin = ((2*b)/i - i + 1) / 2;
			//(begin+begin+(len-1))/2*len = m
			//=> begin = ((2*m)/len - len +1) / 20
			if((2*begin + i - 1) * i == 2 * b) {
				printf("[%lld,%lld]\n",begin,begin+i-1);
			}
		}
		cout<<endl;
	}
	return 0;
} 
