#include<iostream>//ac
#include<algorithm>
using namespace std;
struct program{
	int s,e;
	friend bool operator < (program a,program b) {
		return a.e<b.e;//������ʱ������
	}
}a[105];
int main() {
	int t;
	while(cin>>t&&t) {
		for(int i=1;i<=t;i++) {
			cin>>a[i].s>>a[i].e;
		}
		sort(a+1,a+t+1);
		int last_end = 0,cnt = 0;
		for(int i=1;i<=t;i++) {
			if(a[i].s>=last_end) {//��ʼʱ�����ϴν���ʱ�����
				cnt++;
				last_end = a[i].e;//���½���ʱ��
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
