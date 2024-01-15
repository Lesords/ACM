#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺������Ŀ��Ҫ��С�ľ��룬�������еĻ������λ��
//һ���Ǹ��ݸ߶�����һһ��Ӧ��
//��ô���ýṹ��洢�߶Ⱥ��±꣬Ȼ����ݸ߶�����
//���õ����������м�Ϊһһ��Ӧ������
//��ô���ڶ������е��±�posָ���һ��������ͬһλ�õ��±�pos����
//������ɵ����н����Ϊ���ڶ��������е��������Ҫ�ƶ����ĸ�λ��
//��ô�����ƶ�������Ϊ������е�����ԣ��ù鲢������⼴��

const int MAXN = 1e5+5;
const int MOD = 1e8-3;//ģ��
struct node{
    int hei,pos;
    friend bool operator < (node a,node b) {
        //���ݸ߶�����
        if(a.hei!=b.hei) return a.hei < b.hei;
        return a.pos < b.pos;
    }
}one[MAXN],two[MAXN];
int a[MAXN],b[MAXN];//a��¼���Ľ�����У�bΪ�鲢���̵��м�����
int n,ans;//ansΪ��������
void Merge(int l,int r) {
    if(l==r) return;                        //ֻ��һ��Ԫ�أ�ֱ�ӷ���
    int mid = (l+r)/2;                      //ȡ�м�λ��
                                            //�Ȼ��ֺ�ϲ�
    Merge(l,mid);                           //������
    Merge(mid+1,r);                         //������
    int s1 = l,s2 = mid+1,e1 = mid,e2 = r;  //����[s1,e1]������[s2,e2]�Ա�
    int cnt = l;                            //��¼��ֵ�����
    while(s1<=e1&&s2<=e2) {                 //�������䶼������ʱ
        if(a[s1]<=a[s2]) b[cnt++] = a[s1++];//��С�Ҵ�ѡ���
        else b[cnt++] = a[s2++], ans = (ans+(e1-s1+1))%MOD;
                                            //����ѡ�ұߣ���������ߴ������
    }
    while(s1<=e1) b[cnt++] = a[s1++];       //��������ʣ������
    while(s2<=e2) b[cnt++] = a[s2++];       //��������ʣ������
    for(int i = l;i < cnt;i++) a[i] = b[i]; //������b��ֵ�Ƶ�a����
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>one[i].hei,one[i].pos = i;
    for(int i = 1;i <= n;i++) cin>>two[i].hei,two[i].pos = i;
    sort(one+1,one+1+n);
    sort(two+1,two+1+n);
    for(int i = 1;i <= n;i++) {             //��¼�ڶ���������Ҫ�ƶ�����λ��
        a[two[i].pos] = one[i].pos;
    }
    Merge(1,n);                             //�鲢�����������
    cout<<ans;
    return 0;
}
