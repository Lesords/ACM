#include<iostream>//ac
#include<cstdio>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺����gcdΪ��Сֵ��ֵ���Խ�������ôҲ����˵Ϊ ��Сֵ�ı��� ��ֵλ�ÿ����⽻��
//���Խ�ԭ���������ж��Ƿ��� ��Ϊ���� ��ֵ����ָ��λ�ü���

const int MAXN = 1e5+5;
int a[MAXN], b[MAXN];
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,minn = INF,flag = 0;
        scanf("%d", &n);
        for(int i = 1;i <= n;i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
            minn = min(minn, a[i]);//��¼��Сֵ
        }
        sort(b+1,b+1+n);//����
        for(int i = 1;i <= n;i++) {
            //λ�ô����Ҳ�Ϊminn�ı�����Ϊ�޽�
            if(a[i]!=b[i]&&a[i]%minn) {
                flag = 1;break;
            }
        }
        if(flag) puts("NO");
        else puts("YES");
    }
    return 0;
}
