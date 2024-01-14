#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//��⣺���ִ�+̰��
//���������ü��㣬���ǽ�ķ�Χ��һ���ķ�Χ��
//���Ҷ�Ӧ���֧���ж��Ļ�����ô���Կ��Ƕ��ִ�

//���ڼ�����Ǳ任���۵����ֵ�����Ҹ������ݵķ�Χ���Ϊ 1e6
//���Ҹ�����������ֻ�� 1e5��С�����ݷ�Χ��С
//Ҳ����ÿ��ֵ һһ��Ӧ һ��λ�ü�����������
//��ô��������ǣ����ֵ(1e6)���ڵ�ǰλ�ã���Сֵ(1)���ں�һ��λ��
//��ô��Ҫ�����ֵ�޸�Ϊ ��Сֵ-1���� 1e6-1e6 = 1-1 = 0
//�������Ϊ1e6

//���ڽ������۲�Ϊ������������СֵΪ0
//�����Զ������� [0, 1e6]
//��ôÿ���ж�val�����Դ�ǰ������λ���㣨���ȵ�ǰλ�þ���С��
//1. ��һ��λ�õ�ֵ���Ծ���С
//2. �����ǰλ�ô���ǰһ��λ�ã��򽫵�ǰλ�õ�ֵ������С
//�������Ӧ����������������Ҫ����ǰһ��λ�õ�ֵ��
//3. �����ǰλ��С��ǰһ��λ�ã���ô��Ҫ�޸ģ��Ӳ�����
//�����ǰλ�ú�ǰһ��λ�õĲ�ֵ����val�����޽⣡����
//�����޸�Ϊ ǰһ��λ�õ�ֵ - 1����ʱ�����������Ҿ�����С��

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int a[MAXN],b[MAXN];//aΪԭ���飬bΪ�ж�ʱ�Ĳ�������
int n;
bool judge(int val) {//�ж�val�����Ƿ������������
    for(int i = 1;i <= n;i++) {
        if(i==1) b[i] = a[i] - val;//��ʼλ��ֵ����С
        else {
            //��ǰλ�ô���ǰһ��λ��ֵ
            //b[i-1]+1����������������ǰһ��λ�õ�ֵ��
            //a[i]-val���ڸ��������ڵ���Сֵ
            if(a[i]>b[i-1]) b[i] = max(b[i-1]+1, a[i]-val);//���߶����㣬��ȡmax
            else {//������Ҫ+����
                //�ڸ��������ڿ���������������ȡ ��һ����+1
                if(a[i]+val>b[i-1]) b[i] = b[i-1]+1;
                else return false;//�����޽�
            }
        }
    }
    return true;
}
int main() {
    fast;
    int t;
    cin>>t;
    for(int cas = 1;cas <= t;cas++) {
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        //[0, 1e6]��Χ�ڶ��ִ�
        int l = 0, r = int(1e6+5), ans = 0;//ansΪ���
        while(l<=r) {
            int mid = (l+r)>>1;
            //�����ǰ��������������С�ұ߽磨�������С��
            if(judge(mid)) ans = mid, r = mid-1;
            else l = mid+1;
        }
        cout<<"Case #"<<cas<<":\n";
        cout<<ans<<"\n";
    }
	return 0;
}
