#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;

//��⣺�����������Ҹ�һ�룬��������ʱ���м�һλ���ıߴ���ı�

int a[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int mid = n/2,sum1 = 0,sum2 = 0;
    for(int i = 1;i <= mid;i++) sum1 += a[i];//��һ��
    int st = mid+1,num1 = mid,num2 = mid;//�������ߵ�������һ��
    if(n%2) st++;//����ʱ���ұ�������һλ
    for(int i = st;i <= n;i++) sum2 += a[i];//��һ��
    if(n%2) {//����ʱ�������м��������ı�
        if(sum1>sum2) sum1 += a[mid+1],num1++;//��ߴ󣬸����
        else sum2 += a[mid+1],num2++;//�ұߴ�
    }
    cout<<"Outgoing #: "<<num2<<"\n";//Outgoing�ǻ�Ծ�ȸߵ�
    cout<<"Introverted #: "<<num1<<"\n";
    cout<<"Diff = "<<max(sum1,sum2)-min(sum1,sum2);
    return 0;
}
