#include<iostream>//ac
#include<algorithm>
#define LL long long
using namespace std;

//��⣺�鲢�����������
//�ںϲ���ʱ���ж�����ж��ٸ������ڵ�ǰ�ұߵ�����Ȼ���ۼӼ���

const int MAXN = 5e5+5;
int a[MAXN],b[MAXN],n;//aΪԭ���飬bΪ�м�����
LL ans;//���ƫ��
void Merge(int l,int r,int ll,int rr) {//[l,r]��[ll,rr]����Ա�
    int cnt = l-1;//�м������λ��
    int tl = l,tll = ll;//��¼��ʼ��
    while(l<=r&&ll<=rr) {//����������Ϊ�գ�������Ա�
        if(a[l]<=a[ll]) b[++cnt] = a[l++];//��С�Ҵ������ߵ�ֵ
        else b[++cnt] = a[ll++], ans += (r-l+1);
        //��������ұߵ�ֵ����������ߵĴ�ֵ����
    }
    while(l<=r) b[++cnt] = a[l++];//�������ʣ��ֵ
    while(ll<=rr) b[++cnt] = a[ll++];//�����ұ�ʣ��ֵ
    for(int i = tl;i <= rr;i++) a[i] = b[i];//b����ת�Ƶ�a����
}
void mergesort(int l,int r) {//�鲢����
    if(l==r) return;//ֻʣһ��Ԫ�أ��������
    int mid = (l+r)/2;
    mergesort(l,mid);//�Ȼ��֣���ϲ�
    mergesort(mid+1,r);
    Merge(l,mid,mid+1,r);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    mergesort(1,n);//ԭ��������ǵ�ɾ��������
    cout<<ans;//�������Լ���
    return 0;
}
