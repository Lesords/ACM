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
#define fi first
#define se second
using namespace std;

//��⣺���ڶ���1-n���������ɸ sqrt(n) ��ʱ�򣬻��֮�����еı�����ɸ��
//���Ե�һ��ֻ��Ҫɸ 1-sqrt(n) ����
//���ڵڶ�����˵��Ҫ�� i*i ��ʼ����Ϊ��Ҫ��ȡÿ��������С�����ӣ�����
//������������������˵��
// ���ڽ������˵ģ����Կ����ȼ��㵱ǰ������С�����ӣ�Ȼ���ٳ���ʣ���ֵ�����Ӻ�
//���Ӵ�С��¼ ÿ�����Ӻ� ��Ӧ��ֵ

const int MAXN = 1e7+5;
int v[MAXN],ans[MAXN];//v[i]Ϊi����С�����ӣ�ansΪ��
ll sum[MAXN];//sum[i]Ϊi�����Ӻ�
void init() {
    //��ȡÿ��������С������
    for(int i = 2;i*i < MAXN;i++) {//��ʽɸ����Ҫȡ sqrt(MAXN)
        if(v[i]==0) {
            v[i] = i;//v���鱣�浱ǰ������С������
            for(int j = i*i;j < MAXN;j+=i) {//�����Ҫ��i*i��ʼ������
                if(v[j]==0) v[j] = i;
            }
        }
    }
    sum[1] = 1;//����ÿ���������Ӻ�
    for(int i = 2;i < MAXN;i++) {
        if(v[i]==0) {//sqrt(MAXN)֮�������
            v[i] = i;//��¼��С������
            sum[i] = i+1;//����������ֻ�б���+1
        }
        else {
            sum[i] = 1;//��ʼ��
            int tmp = i;
            while(tmp%v[i]==0) {//����С������ȫ��ȥ��
                sum[i] = sum[i]*v[i]+1;//����v[i]���������㣡����
                tmp /= v[i];
            }
            sum[i] = sum[i]*sum[tmp];//�ٳ���ʣ���tmp
        }
    }
    memset(ans,-1,sizeof(ans));//��ʼ��Ϊ-1���޽����-1
    for(int i = MAXN-1;i >= 1;i--) {//��������
        if(sum[i]>=MAXN) continue;//Խ��
        ans[sum[i]] = i;//��¼sum[i]ֵ��Ӧ����Ϊi
    }
}
int main() {
    fast;//����
    init();//Ԥ������
    int t;
    cin>>t;
    while(t--) {
        int c;
        cin>>c;
        cout<<ans[c]<<"\n";//ֱ�Ӷ�Ӧ���������
    }
	return 0;
}
