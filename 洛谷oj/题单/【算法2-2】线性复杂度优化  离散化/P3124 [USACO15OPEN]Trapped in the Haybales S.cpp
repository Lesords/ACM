#include<iostream>//ac
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

//��⣺����ֻ��ѡ��һ���ɲ������ӹ̣�����
//���Կ��԰��ոɲ�����λ�ý��д�С��������
//Ȼ��ö�����ұ߲��ӹ̵�����£����ÿ��λ����Ҫ�ӹ̶��٣�ȡ��Сֵ
//����ö������߲��ӹ̵�����£��ұ�ÿ��λ����Ҫ�ӹ̶��٣�ȡ��Сֵ
//ע�⣺���ܻ��и�����������Ҫ��0ȡmax

const int MAXN = 1e5+5;
struct node {
    int val,pos;
    friend bool operator < (node a,node b) {
        return a.pos < b.pos;//��С��������
    }
}a[MAXN];
int main() {
    int n,b;
    cin>>n>>b;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].val>>a[i].pos;
    }
    sort(a+1,a+1+n);//����
    int ans = INF,pos = 0;//Ѱ�ҵ�һ������b��λ��
    for(int i = 1;i <= n;i++) {
        if(a[i].pos>b) {
            pos = i;break;//�ҵ��ͽ���
        }
    }
    int l = pos-1,r = pos;//����λ����bΪ��׼��lΪb����ߣ�rΪb���ұ�
    for(;l >= 1;l--) {//ö�������Ҫ�ӹ̵�λ��
        //ע���Ǿ��룬����λ�ò�ɣ�����Ҫ+1������
        while(r<=n&&a[r].pos-a[l].pos>a[r].val) r++;//Ѱ���ұ߲���Ҫ�ӹ̵�λ��
        if(r>n) break;//Խ�磬�����
        //����Ϊa[r].pos-a[l].pos����a[l].val�Ĳ�ֵ��Ϊ�ӹ̵Ĵ�С
        ans = min(ans, max(0, (a[r].pos-a[l].pos)-a[l].val));//�ǵ���0ȡmax
    }
    l = pos-1, r = pos;
    for(;r <= n;r++) {//ö���ұ���Ҫ�ӹ̵�λ��
        while(l>=1&&a[r].pos-a[l].pos>a[l].val) l--;//Ѱ����߲���Ҫ�ӹ̵�λ��
        if(l<1) break;//Խ�磬�����
        ans = min(ans, max(0, (a[r].pos-a[l].pos)-a[r].val));
    }
    if(ans==INF) cout<<"-1\n";//����INF����ʾ�޽�
    else cout<<ans;
    return 0;
}
