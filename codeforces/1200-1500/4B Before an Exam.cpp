#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺���ж� Ŀ����ʱ�� �Ƿ��� �ܹ���Сʱ�� �� �ܹ����ʱ�� �ķ�Χ��
//Ȼ���ǰ�������������Сʱ��Ļ�������ӻ�����ӵ�ʱ�䣬ֱ������ʱ�䶼����

int minT[50],maxT[50];
int main() {
    int n,sumTime,sumMin = 0,sumMax = 0;
    cin>>n>>sumTime;
    for(int i = 1;i <= n;i++) {
        cin>>minT[i]>>maxT[i];
        sumMin += minT[i];//�ܹ���Сʱ��
        sumMax += maxT[i];//�ܹ����ʱ��
    }
    if(sumTime>sumMax||sumTime<sumMin) {//���ڷ�Χ�ڣ����޽�
        cout<<"NO\n";
    }
    else {
        cout<<"YES\n";
        for(int i = 1;i <= n;i++) {
            int cha = maxT[i] - minT[i];//��ֵ������ӵ�ֵ��
            if(cha<=sumTime-sumMin) {//ʣ��ʱ�����
                sumMin += cha;
                minT[i] = maxT[i];//ֱ��Ϊ���ʹ��ʱ��
            }
            else {//����ʣ��ʱ�伴��
                cha  = sumTime-sumMin;
                sumMin += cha;//��ʣ���ʱ��
                minT[i] += cha;
                break;//����
            }
        }
        for(int i = 1;i <= n;i++) cout<<minT[i]<<" ";//����������
    }
    return 0;
}
