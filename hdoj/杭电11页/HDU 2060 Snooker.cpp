#include<iostream>//ac
using namespace std;
int main() {
	int T;
	cin>>T;
	while(T--) {
		int ball,p,o;
		cin>>ball>>p>>o;
		if(ball<=6) {//ֻ�в���
			for(int i=7;ball>0;i--,ball--) {
				p += i;
			}
		}
		else p += 27 + (ball-6) * 8;//���� + ��ڽ��
		if(p>=o) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
