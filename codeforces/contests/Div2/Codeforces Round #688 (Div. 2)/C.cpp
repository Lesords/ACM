#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//��⣺��0��9��ʼ�жϣ�ÿ�θ�����������Һ����Ϻ����µ�ֵ
//��ĳ�����ֳ��ִ���С��2�������һ��Ϊ0������
//Ȼ���ٱ������е������жϵ�ǰ����ĸ�������ϵ�������
//�ڵ�ǰ��Ĵ�ֱ��ˮƽ�����������һ���㣡����
//�����Ϻ��������ʱ������㴹ֱ�߶ȣ�Ȼ��ѡ�� 0��n ������ˮƽ��ȣ����Ϊ0��
//��������������ʱ�������ˮƽ��ȣ�Ȼ��ѡ�� 0��n �����㴹ֱ�߶�

const int MAXN = 2e3+5;
string a[2005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;cin>>n;
        for(int i = 0;i < n;i++) cin>>a[i];
        for(int i = 0;i <= 9;i++) {//��������жϣ���0��9
            if(i!=0) cout<<" ";
            int leftt = n,up = n,down = 1,rightt = 1;//�����ʼ��
            int num = 0,ans = 0;//num���㵱ǰֵ��������ans��¼��
            for(int j = 0;j < n;j++) {
                for(int k = 0;k < n;k++) {
                    int tmp = a[j][k]-'0';
                    if(tmp!=i) continue;//��Ϊ��ǰ��
                    num++;
                    leftt = min(leftt,k);//����4������
                    up = min(up,j);
                    down = max(down,j);
                    rightt = max(rightt,k);
                }
            }
            if(num<2) cout<<"0";//2������
            else {
                for(int j = 0;j < n;j++) {//���ĸ�����Ϊ��һ������
                    for(int k = 0;k < n;k++) {//Ȼ��Ѱ�ҵڶ�������
                        int tmp = a[j][k]-'0';//�������������⣨ȡ�߽��ֵ���
                        if(tmp!=i) continue;
                        ans = max(ans,max(down-j,j-up)*max((n-1)-k,k));//�̶���ֱ����ļ���
                        ans = max(ans,max(rightt-k,k-leftt)*max((n-1)-j,j));//�̶�ˮƽ����ļ���
                    }
                }
                cout<<ans;
            }
        }
        cout<<"\n";
    }
	return 0;
}
