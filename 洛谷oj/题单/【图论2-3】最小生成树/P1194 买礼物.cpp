#include<iostream>//ac
#include<set>
#include<algorithm>
using namespace std;

//��⣺�������ж����ļ۸�Ϊa�����������I���������J��ֻ��Ҫ��Kij
//��ô���Խ�����С���������������еıߣ�Ȼ���ټӸ�����ֵ����
//��Ҫע����ǣ��Żݲ�һ����ԭ�۱��ˣ�����

const int MAXN = 505;
struct node{
    int u,v,w;
    friend bool operator < (node a,node b) {
        return a.w < b.w;//����С��
    }
}a[MAXN*MAXN];
int dis[MAXN];//��¼����
int getf(int p) {//Ѱ��p�����ȣ�·��ѹ��
    return dis[p]==p?p:dis[p]=getf(dis[p]);
}
int main() {
    int n,m,cnt = 0;//cnt��¼����
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= m;j++) {
            int tmp;
            cin>>tmp;
            if(i<=j) continue;//ֻ��Ҫ��¼һ��ı߼��ɣ������ֻ��Ҫ��¼һ��
            if(tmp==0) continue;//�������Żݵı�
            a[++cnt] = {i,j,tmp};
        }
        dis[i] = i;//��ʼ������Ϊ����
    }
    sort(a+1,a+cnt+1);//����
    int ans = n;
    for(int i = 1;i <= cnt;i++) {//�ܹ�ֻ��cnt����
        node tmp = a[i];
        if(getf(tmp.u)!=getf(tmp.v)) {//����δ���������У�������
            ans += tmp.w;
            dis[getf(tmp.u)] = dis[getf(tmp.v)];//������
        }
    }
    cout<<min(n*m,ans);//����������û��ԭ��(n*m)���ˣ�����
    return 0;
}
