#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//��⣺ֱ��ģ��
//��ʼʱ�����Ϊ4���߶�Ϊ2
//ÿ����һ�Σ�����ڿ�Ⱥ͸߶�*2
//��ô����ֱ�Ӽ��㵱ǰ�����ͼ�ڵĴ�С������͸�
//�ȳ�ʼ������λ��Ϊ�ո��ַ�
//Ȼ������һ�׵�λ�ü���Ӧ�ַ�
//���Ŵӵ����ϣ�һ��һ������

char s[(2<<10)+5][(4<<10)+5];
int main() {
    memset(s,' ',sizeof(s));                        //��ʼ��Ϊ�ո��ַ�
    int n;
    cin>>n;
    int hei = 2<<(n-1);                             //�ܵĸ߶�
    int wid = 4<<(n-1);                             //�ܵĿ��
    s[hei][1] = s[hei-1][2] = '/';                  //��ʼ����һ�׵�ֵ
    s[hei][2] = s[hei][3] =  '_';
    s[hei][4] = s[hei-1][3] = '\\';
    for(int i = 1;i < n;i++) {                      //����n-1��
        int thei = 2<<(i-1);                        //��ǰ�׵ĸ߶�
        int twid = 4<<(i-1);                        //��ǰ�׵Ŀ��
        for(int j = hei;j >= hei-thei+1;j--) {      //���Ƶ��ұ�
            for(int k = twid+1;k <= twid<<1;k++) {
                s[j][k] = s[j][k-twid];
            }
        }
        for(int j = hei-thei;j >= hei-(thei<<1)+1;j--) {//���Ƶ�����
            for(int k = (twid>>1)+1;k <= (twid>>1)+twid;k++) {
                s[j][k] = s[j+thei][k-twid/2];
            }
        }
    }
    for(int i = 1;i <= hei;i++) {
        for(int j = 1;j <= wid;j++) cout<<s[i][j];
        cout<<"\n";
    }
    return 0;
}
/*
   /\
  /__\
 /\  /\
/__\/__\
*/
