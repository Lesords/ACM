#include<iostream>//ac
using namespace std;
int f(int i,int pos) {//posΪ������
	int ans = 0;
	while(i) {
		ans += i%pos;
		i /= pos;
	}
	return ans;
} 
int main() {
	for(int i = 2992;i <= 9999;i++) {
		//���ֽ��Ƶ����ֺ����ʱ���
		if(f(i,10)==f(i,16)&&f(i,10)==f(i,12))
			cout<<i<<endl;
	}
	return 0;
} 
