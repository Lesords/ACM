#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;

//��⣺ֱ�ӹ��쳤m�������ɣ����г�Ϊ1��Ϊ0�����
//�͵ķ�Χ��Ҫ����1����С�� m*9 ��Ϊ��СֵΪ��һλΪ1����Ϊ0�����ֵΪȫ9
//��ʼ����һλ��Ϊ1����Сֵ�����λ�����λ��ʼ����
//���ֵ�����λ�����λ��ʼ����

const int MAXN = 105;
int a[MAXN];
int main() {
    int m,s;
    scanf("%d%d", &m,&s);
    if(m==1&&s==0) {//���г�Ϊ1��Ϊ0�����
        puts("0 0");
        return 0;
    }
    if(s>=1&&s<=m*9) {//m���ĺ͵ķ�Χ
        int tmp = s-1;
        a[1] = 1;//��ʼ����λΪ1
        for(int i = m;i >= 1&&tmp;i--) {//�ڵ�λ����λ��ʼ����
            while(a[i]<9) {//ÿ��λ�ò��ܳ���9
                a[i]++;
                tmp--;
                if(tmp==0) break;//ֵ���ˣ������
            }
        }
        for(int i = 1;i <= m;i++) printf("%d", a[i]),a[i] = 0;
        printf(" ");
        tmp = s-1;
        a[1] = 1;//��ʼ����λΪ1
        for(int i = 1;i <= m&&tmp;i++) {//�Ӹ�λ����λ��ʼ����
            while(a[i]<9) {//ÿ��λ�ò��ܳ���9
                a[i]++;
                if(--tmp==0) break;//ֵ���ˣ������
            }
        }
        for(int i = 1;i <= m;i++) printf("%d", a[i]);
    }
    else puts("-1 -1");
    return 0;
}
