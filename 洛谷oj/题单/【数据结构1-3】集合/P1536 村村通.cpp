#include<iostream>//ac ���鼯
#include<cstring>
#include<algorithm>
using namespace std;

//��⣺���ò��鼯�ѵ�·���ӵ����������Ϊһ����Ķ�������
//������ж��ж��ٸ��������򼴿ɣ�������Ϊ ������-1

const int MAXN = 1e3+5;
int fa[MAXN];
int getf(int x) {//·��ѹ��
    return x==fa[x]?x:fa[x]=getf(fa[x]);
}
int main() {
    int n,m;
    while(cin>>n>>m&&n) {
        for(int i = 1;i <= n;i++) fa[i] = i;//��ʼ��
        for(int i = 1;i <= m;i++) {//m��·����
            int x,y;
            cin>>x>>y;
            x = getf(x);
            y = getf(y);
            if(x!=y) fa[y] = x;//���Ȳ�һ����������ϲ�
        }
        int ans = 0;//��¼�����ĵ���
        for(int i = 1;i <= n;i++) ans += fa[i]==i;//û�кϲ��Ķ�Ϊ������
        //�ϲ������Ƚڵ�Ҳ��һ�������㣨��Ķ����㣩
        cout<<ans-1<<"\n";//ans�������ٵı���������Ϊ ans-1
    }
    return 0;
}
