#include<iostream>//ac
using namespace std;

//��⣺dfs�����������
//ָ��Ϊ�� 1-n ��ʼѡֵ
//��ѡ���� n ��ʱ�������Ӧ���������

int a[15],vis[15];
int n;
void dfs(int pos) {//��ǰѡ��pos��
    if(pos==n) {//��ѡ��n�����������Ӧ���������
        for(int i = 1;i <= n;i++) cout<<a[i]<<" ";
        cout<<"\n";
        return ;
    }
    for(int i = 1;i <= n;i++) {//������������
        if(vis[i]) continue;//������ѡ���
        a[pos+1] = i;
        vis[i] = 1;//���
        dfs(pos+1);
        vis[i] = 0;//ȡ�����
    }
}
int main() {
    cin>>n;
    dfs(0);
    return 0;
}
