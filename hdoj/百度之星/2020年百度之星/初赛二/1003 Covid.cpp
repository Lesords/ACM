#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 2e4+5;
int len[MAXN],vis[15],mark[MAXN];
struct node{
	int num,pos;//��ź�λ��
};
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<node> tim[105];//100��ʱ���
		memset(mark,0,sizeof(mark));
		mark[1] = 1;//��Ǵ���ӫ��۵���
		int num = 1;
		for(int i = 1;i <= n;i++) {
			cin>>len[i];
			int t,p;
			for(int j = 1;j <= len[i];j++) {
				cin>>t>>p;
				//tʱ��i��pλ��
				tim[t].push_back(node{i,p});
			}
		}
		node tmp;
		for(int i = 1;i <= 100;i++) {
			int flag = 0;
			set<int> spos;//��ǰʱ�̳���ӫ��۵�λ��
			for(int j = 0;j < tim[i].size();j++) {
				tmp = tim[i][j];
				if(mark[tmp.num]) {
					flag = 1;
					spos.insert(tmp.pos);//��¼���г���ӫ��۵�λ��
				}
			}
			if(flag==0) continue;//����û��ӫ��۵����
			for(int j = 0;j < tim[i].size();j++) {
				tmp = tim[i][j];
				if(mark[tmp.num]) continue;
				if(spos.count(tmp.pos)) {//��ǰλ����ӫ���
					mark[tmp.num] = 1;//��ǰ��Ҳմ��ӫ���
				}
			}
		}
		int flag = 0;
		for(int i = 1;i <= 20000;i++) {
			if(mark[i]) {//�������ӫ��۵��˼���
				if(flag) cout<<' ';
				cout<<i;flag = 1;
			}
		}
		cout<<endl;
	}
	return 0;
}
