#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;

//��⣺dfs�������е�Ҷ�ӵ�·��������·������������è�������Ƿ����m
//������m����ȥ������֦����ʣ���Ҷ�ӽڵ㶼��������

int cat[MAXN],ans,n,m;
vector<int> g[MAXN];//���
void dfs(int pos,int fa,int num) {//��ǰλ�ã���һ��λ�ã���ǰè����������
    int flag = 0;//�ж��Ƿ�ΪҶ�ӽڵ�
    for(int i = 0;i < g[pos].size();i++) {
        int now = g[pos][i];
        if(now==fa) continue;//�������ڵ�
        flag = 1;//��Ҫ�ж���һ��λ���Ƿ���è�������ۼӣ������ؼ�
        int tnum = cat[pos]?(num+cat[now]):cat[now];//ע�����ţ�����
        if(tnum>m) continue;//è������������������
        dfs(now, pos,tnum);
    }
    if(flag) return ;//��Ϊ0������Ҷ�ӽڵ�
    if(num<=m) ans++;//����������Ҷ�ӽڵ��ۼӼ���
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>cat[i];
    for(int i = 1;i < n;i++) {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0,cat[1]);//��ʼ��
    cout<<ans;
    return 0;
}
