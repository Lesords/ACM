#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺zkw�߶���
//��ÿ���������Ϊ���޸ģ�������Ϊ�����ѯ����

const int MAXN = 1e5+5;
int q,m;
ll tree[MAXN<<2];
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>q>>m;
        //��ʼ�����������е�ֵΪ1
        for(int i = 0;i <= 2*q;i++) tree[i] = 1;
        for(int i = 1;i <= q;i++) {
            int op,x;
            cin>>op>>x;
            int pos = op==1?i:x;//��Ӧλ��
            int val = op==1?x:1;//��Ӧֵ
            pos += q-1;//��ӦҶ�ӽڵ��ţ����湲 q-1 ���ڵ�
            tree[pos] = val%m;//�޸Ķ�ӦҶ�ӽڵ��ֵ
            //���µ��ϣ����¶�Ӧ���Ƚڵ��ֵ
            //posΪ��ǰ�㣬����������λһ��
            for(pos>>=1; pos; pos>>=1) {
                tree[pos] = (tree[pos*2]*tree[pos*2+1])%m;
            }
            cout<<tree[1]<<"\n";//���ڵ㼴Ϊֵ
        }
    }
    return 0;
}
