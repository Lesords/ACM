#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺����ѡ������+���
//���ò�����޸����䣬Ȼ�����ǰ׺�����жϵ�ǰţ�Ƿ�����ǰ��

const int MAXN = 5e3+5;
int a[MAXN],d[MAXN],n;//d���鱣���ֵ�ֵ
int solve(int len) {
    memset(d,0,sizeof(d));//��ʼ��Ϊ0�����޲���
    int now = 0,num = 0;//nowΪǰ׺�͵�ֵ��numΪ������
    for(int i = 1;i <= n;i++) {
        now += d[i];
        if(i+len-1<=n) {//���������޸ĵ�����
            if((a[i]+now)%2==0) {//��ǰ����󷽣����޸�
                d[i]++;//���
                now++;//��ǰǰ׺�͵�ֵ��Ҫ�޸ģ�����
                d[i+len]--;//����Ϊlen
                num++;//������++
            }
        }
        else {
            if((a[i]+now)%2==0) {//��ǰ����󷽣�����ʣ�೤�Ȳ����޸�
                return -1;//���޽�
            }
        }
    }
    return num;
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) {
        char ch;
        cin>>ch;
        a[i] = ch=='F';//1Ϊ����ǰ��
    }
    int ans_cnt = INF,ans_len = 0;
    for(int i = 1;i <= n;i++) {//����ö����������
        int cnt = solve(i);
        if(cnt!=-1&&cnt<ans_cnt) {//�н⣬��ȡ��С������
            ans_cnt = cnt;
            ans_len = i;
        }
    }
    cout<<ans_len<<" "<<ans_cnt<<"\n";
    return 0;
}
