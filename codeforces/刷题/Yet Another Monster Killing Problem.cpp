#include<iostream>//ac
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 10;
int monster[MAXN],book[MAXN];
int main() {
	int t,n,m;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i = 1;i <= n;i++) cin>>monster[i],book[i] = 0;
		//����λ�ò��ɱ䣬���밴˳������������ 
		cin>>m;
		int p,s;
		for(int i = 1;i <= m;i++) {
			cin>>p>>s;//book[����] = ����
			book[s] = max(p,book[s]);//һ�������s�����Ĺ�������
		}
		for(int i = n-1;i >= 1;i--) {
			book[i] = max(book[i],book[i+1]);//���¹�������
		}
		int pos = 1,day = 0,flag = 0;
		while(pos<=n) {
			day++;//��������
			int t_pos = pos;//��ʱλ��
			int mx = 0;//���浱��������Ĺ�����������
			while(1) {
				mx = max(mx,monster[t_pos]);
				if(mx>book[t_pos-pos+1]) break;//����ж��Ƿ�����������
				t_pos++;
			}
			if(t_pos==pos) {//δ�������
				flag = 1;
				break;
			}
			pos = t_pos;//����λ��
		}
		if(flag) cout<<"-1"<<endl;//�޷�����
		else cout<<day<<endl;
	}
	return 0;
}
