#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;

//��⣺��λdp
//Ԥ�������ж�����λ��Ӧ��ʮ����ֵ
//Ȼ����dfs�����У����һ����ǰ����ֵ�Ĳ���
//�� ��ǰλ�õ����λ�ĺ�������ĺ���ֵ Ϊdp�ڶ�ά״̬
//�� Ҫ��ֵall - ��ǰֵsum
//��ΪsumΪ ���λ��ǰһ��λ�� ��ֵ�����Բ�����״̬������
//�����ǰ����ֵ����Ҫ��ֵ��ֱ�ӷ���0������

int val[15],a[15],dp[15][10000];//ֵ�ķ�Χ��(1<<10)*9 = 1024*9
//val[i]:��¼�����ƶ�Ӧλ�õ�ֵ���� 1<<(i-1)
//a�����¼�������ֵ�������λ�ϵ�ֵ
//dp[i][j]:Ϊ������ʱ����iλ�õ���λ�У���Ӧλ�ú���ֵΪj�������
int all;//��¼�޶��ĺ���ֵ
int cal(int v) {//����v�ĺ���ֵ
    if(v<10) return v;//С��10Ϊ�߽磬ֱ�ӷ���
    return cal(v/10)*2+v%10;
}
//posΪ��ǰλ�ã�limΪ��ǰλ���Ƿ����ޣ�sumΪ��ǰ��Ӧ����ֵ
int dfs(int pos, bool lim, int sum) {
    if(pos==0) {//�߽�λ�ã��жϺ���ֵ�Ƿ�С�ڶ�Ӧֵ
        return sum<=all;
    }
    //������Ӧ����ֵ�ģ�ֱ�ӷ���0
    if(sum>all) return 0;
    //�����޲��ҵ�ǰ״̬�Ѿ��������ֱ�ӷ���
    if(!lim&&dp[pos][all-sum]) return dp[pos][all-sum];
    int ans = 0;//�ۼӽ��
    int siz = lim?a[pos]:9;//��ǰλ�õķ�Χ
    for(int i = 0;i <= siz;i++) {//�������з�Χ
        //lim��������ǰ���޲���ֵΪa[pos]
        //sum�������ۼӵ�ǰλ�� pos �Ķ�Ӧֵ i
        ans += dfs(pos-1, lim&&i==a[pos], sum+i*val[pos]);
    }
    //�����ޣ���¼��ǰ״ֵ̬
    if(!lim) dp[pos][all-sum] = ans;
    return ans;
}
int solve(int v) {//����v��������λ��ֵ
    int pos = 0;
    while(v) {//��1��ʼ��¼
        a[++pos] = v%10;
        v /= 10;
    }
    //��ǰλ��Ϊpos����ǰ���ޣ�����ֵΪ0
    return dfs(pos, 1, 0);
}
int main() {
    //��������ƶ�Ӧλ�õ�ֵ
    for(int i = 1;i <= 15;i++) val[i] = 1<<(i-1);
    int t;
    scanf("%d", &t);
    for(int cas = 1;cas <= t;cas++) {
        int a,b;
        scanf("%d%d", &a,&b);
        all = cal(a);//�����޶��ĺ���ֵ
        printf("Case #%d: %d\n", cas, solve(b));
    }
    return 0;
}
