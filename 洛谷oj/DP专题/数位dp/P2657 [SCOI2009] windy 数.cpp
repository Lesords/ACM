#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//��⣺��λdp
//�����������������λ�ϵ�ֵ
//Ȼ��Ӹ�λ����λ����ö�����е����
//��ǰһ��λ������ʱ����ǰ���ֵΪ ��Ӧ��λ ��ֵ
//�������������������
//�����������ֲ���ҪΪ2�����ǵ�ǰ�涼Ϊ0ʱ
//��ǰλ�ÿ��Դ�0��ʼ����������ת��Ϊǰһ������Ϊ -2����0��ֵ�պ�Ϊ2��������
//���� pos,pre ����¼״̬������pre�и��������������+3
//��¼�����޵������������������ࣩ

int a[20],dp[20][15];//dp[i][j]����iλ�õ���λ��ǰһλΪpre������
//posΪ��ǰλ�ã�limΪ��ǰ�Ƿ����ޣ�preΪǰһ������ֵ
int dfs(int pos, bool lim, int pre) {
    if(pos==0) return 1;//0Ϊ�߽磬����1
    //��ǰ�����ޣ����Ҷ�Ӧ״̬�Ѿ��������ֱ�ӷ���
    if(!lim&&dp[pos][pre+3]!=-1) return dp[pos][pre+3];
    int ans = 0;//��¼���
    int siz = lim?a[pos]:9;//���㵱ǰλ�õķ�Χ
    for(int i = 0;i <= siz;i++) {//�����������
        if(abs(pre-i)<2) continue;//����������������
        //ǰһλΪ-2��0�����ҵ�ǰҲΪ0����ô��ӦֵΪ-2������Ϊi
        int now = (pre==-2&&i==0)?-2:i;
        //lim��������ǰ���޲��ҵ�ǰΪ���ֵa[pos]ʱΪ���ޣ�ֵΪtrue��
        ans += dfs(pos-1, lim&&i==a[pos], now);
    }
    //��¼�����޵����
    if(!lim) dp[pos][pre+3] = ans;
    return ans;
}
int solve(int val) {//����val��������λ��ֵ
    int top = 0;//��1��ʼ��¼
    while(val) {
        a[++top] = val%10;
        val /= 10;
    }
    //��ǰλ��Ϊtop�����ޣ�����ǰһ��ֵΪ-2����ʾ��ǰ���Դ�0��ʼ��
    return dfs(top, 1, -2);
}
int main() {
    memset(dp, -1, sizeof(dp));//��ʼ��Ϊ-1
    int a,b;
    cin>>a>>b;
    cout<<solve(b) - solve(a-1);//��ֵ��Ϊ�����ڵ�����
    return 0;
}
