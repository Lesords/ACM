#include<iostream>//ac
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

//��⣺�ȼ����ܽ���Ƿ���0��3�ķ�Χ�ڣ����������ڷ�Χ�ڣ���϶��޽�
//Ȼ���ж��������� -3 �� 3�Ƿ���Ժ������Ϊ0����Ϊ����ֵ������3�ķ�Χ�ڽ��м���
//���ж�-3��������� 3 �� (1+2) �� (1*3) �� (2*2-1)
//Ȼ�����ж��Ƿ��ж����-3���������޽�
//���ж�3��������� (-1-2) �� ((-1)*3) �� (1+(-2)*2)
//Ȼ���ж�3�������Ƿ񳬹�1���������޽�

const int MAXN = 505;
int num[10];//��3λ����
bool check() {
    int tmp,ans = 0;
    for(int i = -3;i <= 3;i++) {//�����ܺ�
        ans += num[i+3]*i;
    }
    if(ans>3||ans<0) return false;//�������Χ��
    if(num[-3+3]) {
        tmp = min(num[-3+3],num[3+3]);
        num[-3+3] -= tmp;
        num[3+3] -= tmp;
        tmp = min(num[-3+3], min(num[1+3],num[2+3]));
        num[-3+3] -= tmp;
        num[1+3] -= tmp;
        num[2+3] -= tmp;
        tmp = min(num[-3+3],num[1+3]/3);
        num[-3+3] -= tmp;
        num[1+3] -= tmp*3;
        tmp = min(num[-3+3], min(num[-1+3],num[2+3]/2));
        num[-3+3] -= tmp;
        num[-1+3] -= tmp;
        num[2+3] -= tmp*2;
    }
    if(num[-3+3]) return false;//-3��������Ϊ0
    if(num[3+3]) {
        tmp = min(num[3+3],min(num[-1+3],num[-2+3]));
        num[3+3] -= tmp;
        num[-1+3] -= tmp;
        num[-2+3] -= tmp;
        tmp = min(num[3+3],min(num[1+3], num[-2+3]/2));
        num[3+3] -= tmp;
        num[1+3] -= tmp;
        num[-2+3] -= tmp*2;
        tmp = min(num[3+3], num[-1+3]/3);
        num[3+3] -= tmp;
        num[-1+3] -= tmp*3;
    }
    if(num[3+3]>1) return false;//3���������ܳ���1������
    return true;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,tmp;
        cin>>n;
        memset(num,0,sizeof(num));//��ʼ��
        for(int i = 1;i <= n;i++) cin>>tmp,num[tmp+3]++;
        cout<<(check()?"Yes\n":"No\n");
    }
    return 0;
}
