#include<iostream>//ac
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

//��⣺�����������������µ���ĳ����������ʱ��
//���ȡ���е�����ֵ��Ϊ��

const int MAXN = 1e4+5;
int in[MAXN],out[MAXN],tim[MAXN],to[MAXN],n;
//in�洢��ȣ�out�洢���ȣ�tim��¼�õ㱾������ʱ�䣬to��¼����õ������ʱ��
vector<int> g[MAXN];//��ͼ
int main() {
    cin>>n;
    int ans = 0;//��ʼ��Ϊ0
    for(int i = 1;i <= n;i++) {
        int tmp,len,val;
        cin>>tmp>>len;
        ans = max(ans,len);//���µ�ÿ����ʱ��
        tim[tmp] = len;
        while(cin>>val&&val) {//val��ǰ��������val->tmp
            g[val].push_back(tmp);//��¼��ϵ
            in[tmp]++;out[val]++;//��¼��Ⱥͳ���
        }
    }
    queue<int> q;//��������
    for(int i = 1;i <= n;i++) if(in[i]==0) q.push(i);//���Ϊ0�������
    while(!q.empty()) {
        int tmp = q.front();q.pop();
        for(int i = 0;i < g[tmp].size();i++) {//��������ָ���
            int now = g[tmp][i];//��¼ָ���ı��
            out[tmp]--;//���Ⱥ���ȶ�Ӧ�޸�
            to[now] = max(to[now],tim[tmp]);//���µ���now���ʱ�䣨��ʼ�㻨�ѵ�ʱ�䣩
            in[now]--;
            if(in[now]==0) {//���Ϊ0�����������
                tim[now] += to[now];//���µ���now����ʱ�䣨��ʱnow����ǰ��������������
                q.push(g[tmp][i]);
            }
        }
    }
    for(int i = 1;i <= n;i++) ans = max(ans,tim[i]);//ȡ���ֵ
    cout<<ans<<endl;
    return 0;
}
