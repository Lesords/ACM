#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺��������ɵã��й��׵�һ��ӦΪͬΪ������ż��λ�õ�ͬɫ���ӣ�y����
//��ô���Խ����е����ݷ�Ϊͬɫ������λ�ü��ɣ���2*m��
//ÿ�������棬���������й���
//��ô������ͳ�����������������ܺ�
//����ֵΪ ��ź����֣�û����ɫ������
//���ݹ�ʽ�����У�
//score = (x+y)*(num[x]+num[y])
//      = x*num[x] + x*num[y] + y*num[x] + y*num[y]
//����{i}�ĵ÷�Ϊ��
//(i1*num[1]+i1*num[2]+i2*num[1]+i2*num[2]) + (i2*num[2]+i2*num[3]+i3*num[2]+i3*num[3])+������
//�����У� score[i_n] = i_n(num[1������n] + (n-2)*num[i_n])

//Ҳ����˵������Ԫ���е�ÿ��ֵ���� �� ������num����n-1����
// i_n * num[i_n] ���� n-1 ����һ����ƥ����n-1�Σ�

//������ i_n(num[1������n]) �ж����һ�� i_n * num[i_n]��
//��ô�� i_n * num[i_n] ����Ҫ��ȥһ��Ϊ (n-2) * i_n *num[i_n]

//��Ϊ i_n * (num[1������n]) + i_n * num[i_n] * (n-2)
//����Ϊ�� i_n(num[1������n] + (n-2)*num[i_n])

const int MAXN = 1e5+5;
const int MOD = 10007;
int num[MAXN],color[MAXN],sum[MAXN][2],cnt[MAXN][2];
int main() {
    int n,m,ans = 0;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>num[i];
    for(int i = 1;i <= n;i++) {
        cin>>color[i];
        cnt[color[i]][i%2]++;//ͳ������
        sum[color[i]][i%2] = (sum[color[i]][i%2]+num[i])%MOD;//�ۼ�
    }
    for(int i = 1;i <= n;i++) {
        int tsum = sum[color[i]][i%2]%MOD;//��ǰ�������
        int tnum = cnt[color[i]][i%2]%MOD;//��ǰ����ܺ�
        ans = (ans+(i%MOD)*(tsum + (tnum-2)*num[i]%MOD)%MOD)%MOD;//ȡģ������
    }
    cout<<ans;
    return 0;
}
