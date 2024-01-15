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
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//��⣺���ڽ���Ǹ����У��������е����ֶ��ǲ�ͬ��
//��ô������ǰ�����Ӧ���䳤���� ��Сֵ �����ֵ
//Ȼ������s����Сֵ�Ĳ���ȵķ����������ڵ����֣�ʹ�����ڵ����ֻ�����ͬ
//����������ƽ���������䣬Ȼ������������Ӹߵ��ͷ��䣬��֤�����ظ�
//����1 - k���� 1+avg - k+avg
//Ȼ�����Լ����ֹ������֣������ʣ��λ�õ�����

const int MAXN = 1e5+5;
//�Ȳ���͹�ʽ
int High(int n,int k) {//�����ֵ����Χ n-k+1 -> n
    return ((2*n-k+1)*k)/2;
}
int Lower(int k) {//����Сֵ����Χ 1 - k
    return (1+k)*k/2;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,l,r,s;
        cin>>n>>l>>r>>s;
        int Max = High(n,r-l+1);//ȡ���ֵ
        int Min = Lower(r-l+1);//ȡ��Сֵ
        if(s<Min||s>Max) {//���ڷ�Χ�����޽�
            cout<<"-1\n";
            continue;
        }
        vector<bool> vis(505,0);//������������Ƿ�ʹ��
        vector<int> ans(505,0);//��������������
        int dif = s - Min,num = r-l+1;//difΪ�numΪ���������
        int avg = dif/num,val = 1,rest = dif%num;//valΪ��ʼ����
        //avgΪƽ�������������restΪʣ����Ҫ���������
        for(int i = l;i <= r;i++) {//�����ڵ����ַ��䣬��1��ʼ
            ans[i] = val+avg;//������Ϸ����ƽ��ֵ
            val++;
        }
        int pos = r;//�Ӹߵ��Ͳ�ʣ���ֵ
        while(rest--) {
            ans[pos--]++;//һ�������Ӽ���
        }
        for(int i = l;i <= r;i++) vis[ans[i]] = 1;//����Ѿ����ֵ�ֵ
        for(int i = 1;i <= n;i++) {//��ͷ��β����ʣ���λ��
            if(i==l) {//��Ϊl����ֱ���Ƶ�r��������
                i = r;
                continue;
            }
            for(int j = 1;j <= n;j++) {//��ͷ��ʼѰ��
                if(vis[j]) continue;//�����ѳ��ֹ���
                ans[i] = j;//���iλ�õĴ�
                vis[j] = 1;//�������
                break;//�ҵ��ͽ�������Ȼ���ظ�Ѱ�ң�����
            }
        }
        for(int i = 1;i <= n;i++) {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
	return 0;
}
