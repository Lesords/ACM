#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺���Խ���άѹ��һά������ÿ�е�ǰ׺�ͣ�����O(1)�������
//ÿ��ö�����������˵��λ�ã�Ȼ���ʱ������ (l,r) ����O(1)���
//�������Ϊһ���㣬��ô���ڱ�ѡ�е���������˵������һ����ֱ��һά״̬
//Ҳ�������Ϊ��n�кϲ���һ�У�����
//Ȼ������һά������Ӷκ͵ķ���������������У����´𰸼���

const int MAXN = 105;
int sum[MAXN][MAXN],n;
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            int tmp;
            cin>>tmp;
            sum[i][j] = sum[i][j-1] + tmp;//��ǰ�е�ǰ׺��
        }
    }
    int ans = -INF;//��ʼ��Ϊ��Сֵ
    for(int i = 1;i <= n;i++) {
        for(int j = i;j <= n;j++) {//�����е������յ�
            int num = 0;//����ͳ�ʼ��Ϊ0
            for(int k = 1;k <= n;k++) {//���������У��൱��һά״̬
                if(num<0) num = 0;//С��0�����޸�Ϊ0
                num += sum[k][j]-sum[k][i-1];//��ӵ�ǰ�е������
                ans = max(ans,num);//���´�
            }
        }
    }
    cout<<ans;
    return 0;
}
