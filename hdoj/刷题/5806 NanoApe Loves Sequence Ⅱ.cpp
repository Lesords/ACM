#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺���Խ���Ŀת��Ϊ��ȡһ�����䣬�������������������k��������ڵ���m
//��ô���Լ�¼���д��ڵ���m��ֵ��λ�ã������ڵ���mֵ�ĸ�������k��ʱ
//ȡ��ǰλ����ǰ k-1 ����λ��pos����ǰΪ��k����ǰ��ֻ��ȡk-1����
//ʹ��ǰλ��Ϊ�����䣬�� 1-pos ��λ�ö�����Ϊ��߽磬����Ϊ pos ��

const int MAXN = 2e5+5;
int pos[MAXN];//pos��¼ ���ڵ���m���� ��λ��
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m,k,top = 0;//top��ʾ��ǰ ���ڵ���m���� ������
        ll ans = 0;
        scanf("%d%d%d", &n,&m,&k);
        for(int i = 1;i <= n;i++) {
            int tmp;
            scanf("%d", &tmp);
            if(tmp>=m) {//���ڵ���m������pos�洢λ��
                pos[++top] = i;
            }
            if(top>=k) {//����k��ʱ
                ans += pos[top-k+1];//ȡǰ k-1 ����λ�ã��ۼ�
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
