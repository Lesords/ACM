#include<iostream>//ac
#include<deque>
#include<algorithm>
#define ll long long
#define INF 0x7fffffff7fffffff
using namespace std;

//��⣺�趨����ָ��l��r��lһ��ʼΪ1��rһ��ʼΪc
//ÿ�δ�l��r�ҵ�û��ѡ�й���������С��һ�������������Ϊ��ѡ��
//l������ǰһ��δ��ѡ�е�����r��һ�����r�Ѿ���������ĩβ���򲻼�һ����
//ջ��ԭ������lֻ��Ϊǰһ��δѡ�е���������
//l����ֱ��for������Ѱ��

const int MAXN = 1e4+5;
ll a[MAXN],in[MAXN];//in�������浱ǰλ���Ƿ�ѡ���
int main() {
    ll n,c;
    cin>>n>>c;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    ll l = 1,r = c,cnt = 0;//cnt��¼���������
    while(cnt<n) {//��δȫ�����
        ll minn = INF, pos = 0;
        for(int i = l;i <= r;i++) {
            if(in[i]) continue;//������ѡ����
            if(a[i]<minn) {//���½�Сֵ
                minn = a[i];
                pos = i;
            }
        }
        in[pos] = 1;//���ѡ��
        cout<<a[pos]<<" ";
        cnt++;//��������
        for(int i = 1;i < pos;i++) {//Ѱ��posǰ��һ��δѡ�е�λ��
            if(in[i]) continue;//������ѡ����
            l = i;//���ϸ��£����һ�� ��Ϊ ǰ��һ��
        }
        if(r<n) r++;//r����ĩβ����Ҫ����
    }
    return 0;
}
