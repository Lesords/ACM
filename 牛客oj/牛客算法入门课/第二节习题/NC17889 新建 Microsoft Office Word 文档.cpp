#include<iostream>//ac
#include<queue>
#include<string>
using namespace std;
const int MAXN = 1e5+5;
bool vis[MAXN];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	//old ���ȶ����������ɾ�����ĵ���
	priority_queue<int,vector<int>,greater<int> > old;
	string op;
	int n,num = 1;//��ʼ�ĵ���
	cin>>n;
	while(n--) {
		cin>>op;
		if(op=="New") {//�����ĵ�
			if(old.empty()) {//û��ɾ���ĺ���
				cout<<num<<"\n";
				vis[num] = 1;//1λnum�Ŵ���
				++num;
			}
			else {//��ɾ���ĺ��룬������ɾ���ĺ���
				cout<<old.top()<<"\n";
				vis[old.top()] = 1;//��Ǵ���
				old.pop();
			}
		}
		else {
			int tmp;
			cin>>tmp;
			if(vis[tmp]) {//���ڸ��ĵ���
				old.push(tmp);//old������ú���
				vis[tmp] = 0;//��ǲ�����
				cout<<"Successful\n";
			}
			else cout<<"Failed\n";
		}
	}
	return 0;
}
