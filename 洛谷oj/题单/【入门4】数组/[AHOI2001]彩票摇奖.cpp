#include<iostream>//ac
#include<set>
using namespace std;
int ans[10],n,tmp;
int main() {
	set<int> win;//�����н�����
	cin>>n;
	for(int i = 1;i <= 7;i++) cin>>tmp,win.insert(tmp);
	while(n--) {
		int num = 0;//��ʼ��Ϊ0
		for(int i = 1;i <= 7;i++) {
			cin>>tmp;
			if(win.count(tmp)) num++;//ͳ���н���Ŀ
		}
		ans[num]++;//��Ӧ����++
	}
	for(int i = 7;i >= 1;i--) {//��С���
		if(i!=7) cout<<' ';
		cout<<ans[i];
	}
	return 0;
}
