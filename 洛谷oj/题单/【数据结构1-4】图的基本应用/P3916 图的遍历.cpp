#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//��⣺���򽨱�+dfs
//��Ϊ��Ҫ�ж�ÿ������Ե��������
//��ô�Ӵ�ĵ㿪ʼ����dfs�������ܵ���ĵ��Ӧ��ֵ��Ϊ��ǰ����

const int MAXN = 1e5+5;
int num[MAXN],vis[MAXN];//num��¼��ǰ��ɵ�������㣬vis�жϵ�ǰ���Ƿ��߹�
vector<int> g[MAXN];//��ͼ
void dfs(int root,int dot) {//rootΪ�˴�dfs����㣬dotΪ��ǰִ�еĵ�
    for(int i = 0;i < g[dot].size();i++) {//�������пɵ����
        int to = g[dot][i];
        if(vis[to]) continue;//�������߹������߽����Ϊ���ţ�
        num[to] = max(num[to],root);//�ɵ����ȡ��󣨿��ܵ���n�㣩������
        vis[to] = 1;//��¼�����賷�أ�������
        dfs(root,to);//��������
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) num[i] = i;//��ʼ��Ϊ�����Լ�������
    for(int i = 1;i <= m;i++) {
        int a,b;
        cin>>a>>b;// a�ɵ���b
        g[b].push_back(a);//���򽨱ߣ�����
    }
    for(int i = n;i >= 1;i--) dfs(i,i);//�Ӵ�С���������ܵ���ķ���Ǵ𰸣�
    for(int i = 1;i <= n;i++) cout<<num[i]<<" ";//������
    return 0;
}
