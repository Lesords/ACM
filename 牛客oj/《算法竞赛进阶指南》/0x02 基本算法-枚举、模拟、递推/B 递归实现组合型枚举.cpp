#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺dfs����������һ������+1Ϊ���
//���ѡ����m���������������

int a[30];
int n,m;
void dfs(int pos) {//��ǰ�Ѿ�ѡ��pos��
    if(pos==m) {//�Ѿ�ѡ����m��
        //�����Ӧ���������
        for(int i = 1;i <= pos;i++) cout<<a[i]<<" ";
        cout<<"\n";
        return;
    }
    //����һ��+1Ϊ��㣬�����������
    //���ں���ѡ�����϶���ǰ������Կ��Բ��ñ�����飡����
    for(int i = a[pos]+1;i <= n;i++) {
        a[pos+1] = i;//��¼��ǰֵ
        dfs(pos+1);
    }
}
int main() {
    cin>>n>>m;
    dfs(0);
    return 0;
}
