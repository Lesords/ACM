#include<iostream>//ac
#include<map>
#include<string>
#include<utility>//���pair����
using namespace std;
int main() {
	int t,n;
	string s;
	cin>>t;
	while(t--) {
		cin>>n>>s;
		int flag = 1,L = -1,R = n;//��ʼ��Ϊ������������
		map<pair<int,int>, int> vis;
		pair<int,int> p(0,0);//��ʼ��������
		vis[p] = 0;//�±��Ϊ {0,0}���� vis[{0,0}] = 0;
		//vis������ǵ�ǰ״̬����һλ
		for(int i = 0;i < n;i++) {
			if(s[i]=='L') p.first--;
			if(s[i]=='R') p.first++;
			if(s[i]=='U') p.second++;
			if(s[i]=='D') p.second--;
			if(vis.count(p)) {//���������Ѵ��ڹ�
				if(i-vis[p]+1<R-L+1) {//�����С
					L = vis[p];//�����䲻�ܰ���ԭ״̬������
					R = i;//������Ϊ��ǰ״̬
				}
				flag = 0;
			}
			vis[p] = i+1;//��һλ������ȥ�����Ӵ���ͷ��
		}
		if(flag) cout<<"-1"<<endl;
		else cout<<L+1<<' '<<R+1<<endl;
	}
	return 0;
}
