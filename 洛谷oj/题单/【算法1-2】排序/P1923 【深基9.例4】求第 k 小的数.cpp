#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;

//��⣺���ÿ�������˼�������k������
//������Ŀ�е������0��ʼ�����Կ��Ը�����+1��������㣡����

const int MAXN = 5e6+5;
int a[MAXN],n,k;
inline char gch()
{
    static char buf[100010], *h = buf, *t = buf;
    return h == t && (t = (h = buf) + fread(buf, 1, 100000, stdin), h == t) ? EOF : *h ++;
}
template<class T>
inline void re(T &x)
{
    x = 0;
    char a; bool b = 0;
    while(!isdigit(a = gch()))
        b = a == '-';
    while(isdigit(a))
        x = (x << 1) + (x << 3) + a - '0', a = gch();
    if(b == 1)
        x *= -1;
}
//������������򣬻�׼��ȡ�м�λ�ã�ȡ��߻�MLE���ݹ�������ࣩ
int solve(int left,int right,int k) {           //��[left,right]�������ҵ�kСֵ
    int val = a[(left+right)/2];                //��׼ֵ
    int l = left,r = right;
    while(l<=r) {                               //������������Ҫ�жϣ�������valֵ��λ��
        while(a[r]>val) r--;                    //Ѱ��������С�ڵ���val��λ��
        while(a[l]<val) l++;                    //Ѱ����������ڵ���val��λ��
        if(l<=r) {                              //��������λ��
            swap(a[l],a[r]);                    //���������ƶ���Ӧλ��
            l++,r--;
        }
    }
    // left r l right
    if(k<=r) {                                  //��kС�������䣬�ǵõȺţ�����
        return solve(left,r,k);
    }
    else if(k>=l) {                             //��kС�������䣬�ǵõȺţ�����
        return solve(l,right,k);
    }
    else return a[k];                           //ֱ�Ӹ����±����ֵ
}
int main() {
    re(n),re(k);                                //���
    for(int i = 1;i <= n;i++) {                 //��1��ʼ��¼
        re(a[i]);
    }
    printf("%d", solve(1,n,k+1));               //ϸ�ڣ�����k+1������
    return 0;
}
