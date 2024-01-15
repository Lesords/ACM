#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//��⣺bfs
//�����в�Ϊ ? ��λ�÷��������
//ÿ�α�������ָ��㣬��ָ���Ϊ ?�������޸�Ϊ�뵱ǰ�෴���ַ�
//ע�⣺������λ�ö�Ϊ ? ʱ������һ������������һ���ַ���Ȼ���������У�����

//�ٷ���������������λ�ã��жϵ�ǰΪ ?������һ����Ϊ ?�������
//����ǰ���ַ� ȡ����һ���ַ� ��ͬ���ַ�
//����ͷ��������һ�μ���
//����Ϊ ? �ַ������������õ�һ��λ�õ��ַ�

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int vis[105];
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n;
        string s;
        cin>>n>>s;
        memset(vis, 0, sizeof(vis));
        if(n==1) {//ֻ��һ��������
            if(s[0]!='?') cout<<s<<"\n";
            else cout<<"B\n";
            continue;
        }
        queue<int> q;
        for(int i = 0;i < s.size();i++) {
            if(s[i]!='?') {
                q.push(i);//�����в�Ϊ ?���ַ�λ�÷��������
            }
        }
        if(q.empty()) {//ע��ȫ�����������
            s[0] = 'B';//ȡ�����ַ�����
            q.push(0);//ȫΪ?�����������Ϊ0
        }
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            if(vis[now]) continue;//�����Ѽ����
            vis[now] = 1;//���
            for(int i = -1;i <= 1;i += 2) {//ֻ����������
                int nxt = now + i;
                if(nxt<0||nxt>=s.size()) continue;//Խ�磬����
                if(s[nxt]!='?') continue;//������Ϊ?��
                s[nxt] = s[now]=='B'?'R':'B';//�෴�ַ�
                q.push(nxt);//����ǰλ�÷��������
            }
        }
        cout<<s<<'\n';
    }
	return 0;
}
