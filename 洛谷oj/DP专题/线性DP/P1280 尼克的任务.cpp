#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//��⣺����dp
//��������������ʱ�䣬���Դ�ǰ�����ʾ״̬�Ļ�����dp[i]Ϊ1-i��Ŀ���ʱ��
//�᲻�ü��㣬��Ϊ��ǰλ��i�޷���¼����ʱ��Ժ����Ӱ��
//���Կ��ԴӺ���ǰ���㣬��dp[i]Ϊi-n��Ŀ���ʱ��
//��ʼ������λ�õ�ֵΪ0����ΪҪ�����ֵ
//ת�ƣ�
//�����ǰʱ��û������ dp[i] = dp[i+1]+1
//����ȡ����������ɺ�Ŀ���ʱ�����Сֵ Min(ALL(dp[i+time]))
//Ŀ��״̬��dp[1]
//���ɣ�ֱ����vector�洢ÿ��ʱ�̵��������ʱ�䣬�����Ͳ�����������

const int MAXN = 1e4+5;
vector<int> g[MAXN];//�洢��Ӧʱ�̵�����ĳ���ʱ��
int dp[MAXN];
int main() {
    int n,k;
    cin>>n>>k;
    for(int i = 1;i <= k;i++) {
        int p,t;
        cin>>p>>t;
        g[p].push_back(t);//��¼pʱ�̵��������ʱ��Ϊt
    }
    for(int i = n;i >= 1;i--) {//�������
        //��ǰʱ����������ֱ�Ӹ���
        if(g[i].empty()) dp[i] = dp[i+1]+1;
        else {
            //����ȡ����������ɺ�Ŀ���ʱ�����Сֵ
            for(auto v:g[i]) {//������ǰʱ�̿�ʼ����������
                dp[i] = max(dp[i], dp[i+v]);
            }
        }
    }
    cout<<dp[1];
    return 0;
}
