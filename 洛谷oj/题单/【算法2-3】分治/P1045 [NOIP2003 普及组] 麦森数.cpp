#include<iostream>//ac
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

//��⣺��Ŀ�ֳ��������֣�һ���Ǽ�������λ����һ���Ǽ������ĺ�500ֵ
//����һ�������ǿ��Ը���10^x��x��ֵ���ж�������ж���λ����ֵΪx+1��
//���磺10^2 = 100 ����λ
//��ô����2^p-1��˵��������2�Ĵη����к��治����0����Ҫ������2��5����0��
//���� 2^p-1��λ�� = 2^p��λ��
//��ô����2 = 10^(log_10 2) => 2^p = (10^(log_10 2))^p = 10^((log_10 2) * p)
//��λ�� = (log_10 2) * p + 1
//���ں�500ֱ�Ӹ߾��ȿ����ݼ���

const int MAXN = 501;
int a[MAXN],val[MAXN],c[MAXN];//c�����洢�м���������valΪ���ս��
int main() {
    int p;
    cin>>p;
    int num = log10(2)*p+1;//λ��
    val[1] = 1;//��ʼ��Ϊ1
    a[1] = 2;//��Ϊ2
    while(p) {                                      //�������� 2^p��500λ��ֵ
        if(p&1) {
            for(int i = 1;i < MAXN;i++) {           //�������е�a
                for(int j = 1;j < MAXN;j++) {       //�������е�val
                    int tmp = a[i]*val[j];          //��ǰλ�õļ�����
                    if(i+j-1>=MAXN) continue;       //���ܳ���500λ
                    tmp += c[i+j-1];                //�ۼӣ�����
                    c[i+j-1] = tmp%10;              //��λ����Ϊ��ǰ��ֵ
                    if(i+j<MAXN) c[i+j] += tmp/10;  //ʮλ��Ϊ��һλ��ֵ����Ҫ�жϲ��ܳ���500λ
                }
            }
            for(int i = 1;i < MAXN;i++) {
                val[i] = c[i];                      //������ת�Ƶ�val����
                c[i] = 0;                           //��Ҫ��ʼ��Ϊ0����Ϊ��ǰλ��Ҫ�ۼӣ�����
            }
        }
        for(int i = 1;i < MAXN;i++) {               //�������е�a
            for(int j = 1;j < MAXN;j++) {           //�������е�a
                int tmp = a[i]*a[j];                //���㵱ǰλ�õ�ֵ
                if(i+j-1>=MAXN) continue;           //���ܳ���500λ
                tmp += c[i+j-1];                    //�ۼӣ�����
                c[i+j-1] = tmp%10;                  //��λ����Ϊ��ǰ��ֵ
                if(i+j<MAXN) c[i+j] += tmp/10;      //ʮλ��Ϊ��һλ��ֵ����Ҫ�жϲ��ܳ���500λ
            }
        }
        //c[i]��Ҫ��ʼ��Ϊ0����Ϊ��ǰλ��Ҫ�ۼӣ�����
        for(int i = 1;i < MAXN;i++) a[i] = c[i],c[i] = 0;
        p >>= 1;
    }
    //-1
    if(val[1]>=1) {//��λ����
        val[1] -= 1;
    }
    else {
        for(int i = 2;i < MAXN;i++) {               //�������Ҹ�λ��ֵ�Ľ�λ
            if(val[i]>=1) {
                for(int j = i-1;j >= 1;j--) val[i] = 9;//��ôǰ�����еĵ�λֵ��Ϊ9
                break;                              //����
            }
        }
    }
    cout<<num<<"\n";
    for(int i = 1,j = 500;i <= 500;i++,j--) {
        cout<<val[j];
        if(i%50==0) cout<<"\n";                     //ÿ50������
    }
    return 0;
}
