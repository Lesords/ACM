#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;

//��⣺���ݶ�Ԫ��������a����0��ʱ�򿪿�����
//����a��b��c��Ϊ�����������ԶԳ���Ϊ x = -b/2a��Ϊ����
//���Գ�����y�����࣬��ô�����Ҳ��ֵ��˵��Ϊ���������Ҵ���0
//����ֵ���1��ʼ�����Խ����к�����ֵ���������
//����ֵС�ģ�ѡ����֮���ƶ��ú�����ֵ���ٴη��������

const int MAXN = 1e4+5;
struct fun{//��¼������
    int a,b,c;
}f[MAXN];
struct node{
    int val,id;
    friend bool operator < (node a, node b) {
        return a.val > b.val;//����ֵС��
    }
};
int pos[MAXN];//��¼ÿ��������ǰ��ֵ��
int cal(int id) {//����id������ֵ
    return f[id].a*pos[id]*pos[id]+f[id].b*pos[id]+f[id].c;
}
int main() {
    int n,m;
    priority_queue<node> q;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>f[i].a>>f[i].b>>f[i].c;
        pos[i] = 1;//��ʼ��ֵ��Ϊ1
        q.push({cal(i), i});
    }
    for(int i = 1;i <= m;i++) {//�ܹ�ȡm����
        node tmp = q.top();
        q.pop();
        cout<<tmp.val<<" ";
        pos[tmp.id]++;//ֵ��++
        q.push({cal(tmp.id), tmp.id});//���º���ֵ�����ٴη��������
    }
    return 0;
}
