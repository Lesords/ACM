#include<iostream>//ac
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

//���⣺����ʳ������������������ʳ�������˵�·�����ܺͣ�
//��⣺�����������������˼�룬�����ʳ�����׶˵�������·����
//ͳ�Ƴ���Ϊ0��ʳ�������ˣ��ĵ��·������Ϊ�𰸣����Ϊ0�ĵ�·������ʼ��Ϊ1��

const int MAXN = 5e3+5;
const int MOD = 80112002;
int in[MAXN],out[MAXN],dp[MAXN],n,m;
//in������ȣ�out������ȣ�dp[i]:��ʳ�����׶˵���i��·������
vector<int> g[MAXN];//����ʳ������ϵͼ
int main() {
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {
        int a,b;
        cin>>a>>b;//a��b��
        g[a].push_back(b);//��¼��ϵͼ
        out[a]++,in[b]++;//��¼��Ӧ����Ⱥͳ���
    }
    queue<int> q;
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        if(!in[i]) dp[i] = 1,q.push(i);//���Ϊ0����У�·����Ϊ1
    }
    while(!q.empty()) {
        int tmp = q.front();q.pop();
        for(int i = 0;i < g[tmp].size();i++) {//��������ָ���
            dp[g[tmp][i]] = (dp[g[tmp][i]]+dp[tmp])%MOD;//ָ������·����
            in[g[tmp][i]]--;//ָ������--�����Ȳ�������
            if(in[g[tmp][i]]==0) {//�����Ϊ0������ж��Ƿ���Ҫ�����
                if(out[g[tmp][i]]) q.push(g[tmp][i]);//���Ȳ�Ϊ0�������
            }
        }
    }
    //ʳ�������˲�ֹһ����������Ϊ0��ֹһ��������
    for(int i = 1;i <= n;i++) if(out[i]==0) ans = (ans+dp[i])%MOD;//���ۻ�
    cout<<ans<<endl;
    return 0;
}
