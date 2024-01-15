#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺���鼯+���
//���ڵ��˵ĵ���������
//����һ����� x+n ��ʾ����
//����x��yΪ���ˣ���ôMerge(x,y+n),Merge(y,x+n)
//    x��zΪ���ˣ���ôMerge(x,z+n),Merge(z,x+n)
//�ڵ�һ���ϲ�ʱ��fa[x+n] = y
//�ڵڶ��κϲ�ʱ��fa[fa[x+n]] = z => fa[y] = z
//�� ʹ��z��y�ϲ���Ϊ���ѹ�ϵ��������˵ĵ���Ϊ����
//��Ҫע����ǣ��ϲ���ʱ���ǰ������ʵ��ϲ�������ֻ�е��˹�ϵ��ʱ�򣬻�©��

const int MAXN = 2e3+5;
int fa[MAXN];
int getf(int pos) {//·��ѹ��
    return fa[pos]==pos?pos:fa[pos]=getf(fa[pos]);
}
void Merge(int x,int y) {//����ϲ������ڵ�Ϊx
    x = getf(x);
    y = getf(y);
    if(x==y) return ;
    fa[y] = x;
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n*2;i++) fa[i] = i;  //��ʼ��Ϊ������������ʼ��
    for(int i = 1;i <= m;i++) {
        char ch;
        int x,y;
        cin>>ch>>x>>y;
        if(ch=='E') {
            Merge(x,y+n);                   //�����ʵ��ϲ�������
            Merge(y,x+n);
        }
        else Merge(x,y);                    //������ֱ�Ӻϲ�����
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {             //ͳ�ƶ����ģ���Ϊ�Ż�����
        if(fa[i]==i) ans++;
    }
    cout<<ans;
    return 0;
}
/*
ֻ�������˹�ϵ������
5
2
E 1 2
E 3 4
*/
