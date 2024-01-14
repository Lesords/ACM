#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

//��⣺̰��˼·���Ȱ��ս�ֹʱ���С��������
//Ȼ����ݶѵ������ͼ�ֵ������
//�����ǰ�Ľ�ֹʱ�ڵ��ڶѵĴ�С����Աȵ�ǰ�ļ�ֵ�ͶѶ��ļ�ֵ��ȡ�ϴ�ֵ
//����ֱ����Ѽ��ɣ���ʱ��˳��ѡ�������С�ڶѴ�С�����

const int MAXN = 1e4+5;
struct node{
    int val,time;
    friend bool operator < (node a, node b) {
        if(a.time!=b.time) return a.time < b.time;//�Ȱ���ʱ���С��������
        return a.val > b.val;//Ȼ���ռ�ֵ�Ӵ�С����
    }
}a[MAXN];
int tree[MAXN],cnt,n;
void down(int pos) {//���µ���
    while(pos*2<=cnt) {//�ӽڵ���������
        int tmp = pos*2;
        if(tmp+1<=cnt&&a[tree[tmp+1]].val<a[tree[tmp]].val) tmp++;//�ҽڵ��С
        if(a[tree[pos]].val>a[tree[tmp]].val) swap(tree[pos], tree[tmp]);//���������򽻻�
        else break;//�������
        pos = tmp;//��ǰ�ڵ��Ƶ��ӽڵ�
    }
}
void up(int pos) {//���ϵ���
    while(pos>1) {//��Ϊ���ڵ������
        int tmp = pos/2;
        if(a[tree[pos]].val<a[tree[tmp]].val) swap(tree[pos],tree[tmp]);//���������򽻻�
        else break;//�������
        pos = tmp;
    }
}
int main() {
    while(cin>>n) {
        cnt = 0;
        memset(tree,0,sizeof(tree));
        for(int i = 1;i <= n;i++) {
            cin>>a[i].val>>a[i].time;
        }
        sort(a+1,a+n+1);//������
        for(int i = 1;i <= n;i++) {
            if(cnt==0) {//��һ��
                tree[++cnt] = i;
                up(cnt);
            }
            else {
                int root = tree[1];//root��¼���ڵ����ֵ
                if(a[i].time==cnt) {//��ֹʱ����ڶѵ�����
                    if(a[i].val>a[root].val) {//��ǰ��ֵ���������
                        tree[1] = i;
                        down(1);//���¸���
                    }
                }
                else if(a[i].time>cnt) tree[++cnt] = i,up(cnt);//��ֹʱ��δ�����ǵ����ϸ��£�����
            }
        }
        ll ans = 0;
        for(int i = 1;i <= cnt;i++) {
            ans += a[tree[i]].val;//�����������ݼ�Ϊ���
        }
        cout<<ans<<"\n";
    }
    return 0;
}
