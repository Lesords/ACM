#include<iostream>//ac
#include<cmath>//����floor����������ȡ����
#include<algorithm>
using namespace std;
struct node{
	int num,score;
	friend bool operator < (node a, node b) {
		if(a.score == b.score)
			return a.num<b.num;
		else return a.score > b.score;
	}
}a[5005];
int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) {
		cin>>a[i].num>>a[i].score;
	}
	sort(a+1,a+n+1);//�ṹ������
	int cnt = 0,minn = floor(m*1.5),ans = 0;
	for(int i = 1;i <= n;i++) {
		if(cnt>=minn) break;//�������˼���
		else cnt++;
	}//cnt��ȷ�����Է�����
	for(int i = 1;i <= n;i++) {//��ans����
		if(a[i].score<a[cnt].score) break;
		else ans++;//����ﵽ���Է����ߵ�����
	}
	cout<<a[cnt].score<<' '<<ans<<endl;
	for(int i = 1;i <= n;i++) {
		if(a[i].score<a[cnt].score) break;//û�ﵽֱ���˳�
		cout<<a[i].num<<' '<<a[i].score<<endl;
	}
	return 0;
}
