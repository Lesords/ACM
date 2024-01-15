#include<iostream>//ac ����dp
#include<vector>
#include<algorithm>
using namespace std;

//��⣺����dp��������dfs�Ĺ����н���״̬ת�ƣ������Ϊ���Ͻ�������
//ÿ��ְԱֻ������״̬��0��1��ȥ�Ͳ�ȥ��
//Ψһ��Լ���� ֱ����˾��ְԱ
//����Լ�����н�ͼ��Ȼ���ҹ�ϵͼ�ĸ��ڵ㣨û��ֱ����˾���ˣ�����dfs

const int MAXN = 6e3+5;
int dp[MAXN][2];//dp[i][0]: iְԱ��ȥ��ֵ��dp[i][1]��iְԱȥ
vector<int> g[MAXN];//������˾���µ�ְԱ
bool is_root[MAXN],vis[MAXN];
//is_root�жϵ�ǰ�Ƿ�Ϊ��ϵ�ĸ���vis��ʾ��ǰ���Ƿ�����
void dfs(int pos) {
    vis[pos] = 1;//��ǵ�ǰ�㣬��ʾ�Ѿ���
    for(int i = 0;i < g[pos].size();i++) {//������������
        int now = g[pos][i];
        if(vis[now]) continue;//�����Ѽ������
        dfs(now);//��dfs�����״̬
        //����������˾���ԣ������ۼӵ�״̬������
        dp[pos][0] += max(dp[now][0], dp[now][1]);//��ǰְԱ��ȥ������������ȥҲ���Բ�ȥ
        dp[pos][1] += dp[now][0];//��ǰְԱȥ��������ֻ�ܲ�ȥ
    }
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>dp[i][1];//�洢��ֵ��Ϊ ��ǰְԱȥ��״ֵ̬
    //�����ֵҲ�����Ϊ��ʼ״̬
    for(int i = 1;i < n;i++) {
        int l,k;
        cin>>l>>k;//k��l����˾
        is_root[l] = 1;//�������
        g[k].push_back(l);//��˾��Ӧ�ĵ���ְԱ
    }
    for(int i = 1;i <= n;i++) {
        if(!is_root[i]) {//�������е㣬Ѱ��δ��ǹ��ļ�Ϊ��
            dfs(i);
            cout<<max(dp[i][0], dp[i][1])<<"\n";//��ǰְԱ������״̬ȡ��ֵ
            return 0;
        }
    }
}
