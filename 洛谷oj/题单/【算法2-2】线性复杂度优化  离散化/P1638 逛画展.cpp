#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺˫ָ�룬���ݱ������book����¼�����ڳ��ֲ�ͬ��ʦ������
//���l-r�����ڵ���������m�����´�
//Ȼ����ָ���ƶ�����ɾ��lλ�ö�Ӧ��ʦ������Ȼ���ж������Ƿ���Ҫ�޸ģ�
//������ָ���ƶ������Ӷ�Ӧrλ�õĻ�ʦ���������ж��Ƿ���Ҫ�޸�����

const int MAXN = 1e6+6;
int a[MAXN],book[2005];//book��ǻ�ʦ������
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    int l = 1,r = 1,cnt = 1,ll,rr,ans = MAXN;//ans��ʼ��Ϊ�ϴ�ֵ
    //l��rΪ����㣬������book����
    book[a[1]]++;
    while(r<=n) {//��ָ�뻹�ڷ�Χ�������
        if(cnt==m) {//��������m
            if(r-l+1<ans) {//�ж��Ƿ���Ҫ���´�
                ans = r-l+1;
                ll = l,rr = r;
            }
            book[a[l]]--;//��ָ���Ӧλ���޸�
            if(book[a[l]]==0) cnt--;//�ж������Ƿ���Ҫ����
            l++;//�ƶ���ָ��
        }
        else {
            book[a[++r]]++;//��ָ���λ���޸�
            if(book[a[r]]==1) cnt++;//��Ϊ��һ�������޸�����
        }
    }
    cout<<ll<<" "<<rr<<"\n";
    return 0;
}
