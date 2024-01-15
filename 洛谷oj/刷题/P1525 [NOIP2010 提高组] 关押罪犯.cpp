#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺���ಢ�鼯
//����ֻ��������������ô�������������ﷸ���ԣ�Ҫô����ͬһ������Ҫô������ͬһ������
//���a��b����һ��������b��cҲ����һ����������ô����a��cһ����ͬһ��������
//��ô��¼����һ�����������������������ಢ�鼯�����
//����Merge(a,b+n),Merge(b,a+n); Merge(b,c+n),Merge(c,b+n);
//���ڵ�һ�κϲ����ԣ�fa[b+n] = a;
//���ڵڶ��κϲ����ԣ�fa[fa[b+n]] = c  =>  fa[a] = c; ��a��c��ͬһ����
//ע�⣺�ϲ���˳�����������ʵ��ϲ�������
//������Ҫʹ����Ӱ������С��Ҳ����˵�����ﷸ֮���Թ��ֵ��С
//��ô���Ը���Թ��ֵ�Ӵ�С���򣬾���ʹԹ��ֵ����ﷸ����ͬһ����
//�����ǰ�����ﷸ�Ѿ���ͬһ�����ˣ���ô��ǰ�ﷸ��Թ��ֵ��Ϊ���

const int MAXN = 2e4+5;
const int MAXM = 1e5+5;
struct node{
    int a,b,c;
    friend bool operator < (node x,node y) {
        return x.c > y.c;//����Թ��ֵ�Ӵ�С����
    }
}rel[MAXM];
int fa[MAXN*2];//��¼���ȵ�ֵ�������ռ䣩
int getf(int pos) {//·��ѹ���������Ƚڵ�
    return fa[pos]==pos?pos:fa[pos]=getf(fa[pos]);
}
void Merge(int a,int b) {//b��a�ϲ�����b������Ϊa
    a = getf(a);
    b = getf(b);
    if(a==b) return;
    fa[b] = a;
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= 2*n;i++) fa[i] = i;//��ʼ������Ϊ����
    for(int i = 1;i <= m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        rel[i] = {a,b,c};           //��¼���й�ϵ
    }
    sort(rel+1,rel+m+1);            //����
    for(int i = 1;i <= m;i++) {     //�������й�ϵ�������ﷸ
        node tmp = rel[i];
        if(getf(tmp.a)==getf(tmp.b)) {//��ǰ�����ﷸ�Ѿ���ͬһ��������ֱ�����
            cout<<tmp.c<<"\n";
            return 0;
        }
        Merge(tmp.a, tmp.b+n);      //�����ʵ��ϲ�
        Merge(tmp.b, tmp.a+n);
        if(i==m) {                  //������������û��Թ��ֵ����ô���0
            cout<<"0\n";
        }
    }
    return 0;
}
