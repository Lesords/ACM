#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//��⣺dfsȡ����·�������������һ�����ܷ񵽴����

int a[25],vis[25],cnt,g[25][25],m;
void dfs(int dot,int pos) {//dotΪ��ǰ�㣬posΪ��ǰλ��
    if(pos==20) {//������� һ����ʱ
        if(g[dot][m]==0) return;//�����ܷ񵽴���㣡����
        cout<<++cnt<<":  ";
        for(int i = 1;i <= pos;i++) {
            cout<<a[i]<<" ";
        }
        cout<<m<<"\n";//��������
    }
    for(int i = 1;i <= 20;i++) {
        if(i==dot) continue;//������ǰ��
        if(vis[i]||g[dot][i]==0) continue;//����δ��Ǻ��޷�����ĵ�
        vis[i] = 1;//���
        a[pos+1] = i;//��¼���
        dfs(i,pos+1);
        vis[i] = 0;//ȡ�����
    }
}
int main() {
    for(int i = 1;i <= 20;i++) {
        for(int j = 1;j <= 3;j++) {
            int tmp;
            cin>>tmp;
            g[i][tmp] = 1;
        }
    }
    while(cin>>m&&m) {
        memset(vis,0,sizeof(vis));//��ʼ��
        a[1] = m;//��¼���
        vis[m] = 1;//�����㣡��
        cnt = 0;//cnt��������ʾ��ǰ��·����
        dfs(m,1);
    }
    return 0;
}
