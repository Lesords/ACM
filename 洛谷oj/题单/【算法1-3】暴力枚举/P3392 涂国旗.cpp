#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺��ʼ��ÿ�а׺����ͺ������������ǰ׺���Ż���������ö�����ͺ�����
//��������Ҫ��������ȡ��Сֵ����

char map[55][55];
int white[55],blue[55],red[55],n,m;
int solve(int one,int two) {//one����ɫ��㣬two�Ǻ�ɫ���
    int num = 0;
//    ǰ׺������
//    num += blue[one-1]+red[one-1];//�ϲ��ְ�ɫ
//    num += white[two-1]-white[one-1]+red[two-1]-red[one-1];//�м���ɫ
//    num += white[n]-white[two-1]+blue[n]-blue[two-1];//�²��ֺ�ɫ
    for(int i = 1;i < one;i++) num += blue[i]+red[i];//��ɫ����
    for(int i = one;i < two;i++) num += white[i]+red[i];//��ɫ����
    for(int i = two;i <= n;i++) num += white[i]+blue[i];//��ɫ����
    return num;
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        int wt = 0,bl = 0,rd = 0;
        for(int j = 1;j <= m;j++) {
            cin>>map[i][j];
            if(map[i][j]=='W') wt++;
            else if(map[i][j]=='B') bl++;
            else rd++;
        }
        white[i] = wt;//��¼��ǰ�еĶ�Ӧ��ɫ���������
        blue[i] = bl;
        red[i] = rd;
//        white[i] = white[i-1]+wt;//ǰ׺��д��
//        blue[i] = blue[i-1]+bl;
//        red[i] = red[i-1]+rd;
    }
    int ans = INF;
    for(int i = 2;i <= n-1;i++) {//ö���������Ŀ�����
        for(int j = i+1;j <= n;j++) {
            ans = min(ans,solve(i,j));//ȡ��Сֵ
        }
    }
    cout<<ans<<endl;
    return 0;
}
