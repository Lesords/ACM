#include<iostream>//ac
#include<cstdio>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺˫ָ�����������ֵ
//����l��ʾ��ǰ�������˵�λ�ã�r��ʾ��ǰ�����Ҷ˵��λ��
//ÿ���ۼ�rλ�õĽ�����жϵ�ǰ����ֵ�Ƿ���ڽ���������ڽ���������
//�����ǰ�����С��0����ʾ��ǰ������ں��������ֻ���и�����
//���������������䣬��l��rһ����Ϊ��ǰ�ĺ�һλ�������������Ϊ0
//ע�⣺������и��������Գ�ʼ�������Ϊ-INF

const int MAXN = 1e5+5;
int a[MAXN];
int main() {
    int t;
    scanf("%d",&t);
    for(int cas = 1;cas <= t;cas++) {
        int n;
        scanf("%d",&n);
        for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
        int l = 1,r = 1,sum = 0;//��ʾ��ǰ״̬
        int ans = -INF,ans_l  = 0,ans_r = 0;//��¼���
        while(r<=n) {//r��ʾ��û����ģ�����Ϊn��ʱ��Ҳ��Ҫ����һ�Σ�����
            sum += a[r];
            if(sum>ans) {//���ڽ��������¶�Ӧ��Ϣ
                ans = sum;
                ans_l = l,ans_r = r;
            }
            r++;//����һλ
            if(sum<0) {//�������С��0�����޸��������
                sum = 0;
                l=r;//�޸����λ��
            }
        }
        printf("Case %d:\n",cas);
        printf("%d %d %d\n", ans,ans_l,ans_r);
        if(cas!=t) puts("");
    }
    return 0;
}
/*
2
5
-1 0 -8 -9 -11
5
0 -1 0 -1 -5
5
1 2 -11 2 1
*/
