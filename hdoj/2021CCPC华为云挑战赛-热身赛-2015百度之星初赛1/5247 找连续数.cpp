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
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//��⣺ֱ�ӱ���Ԥ�������г��ȵ�������
//ÿ��ö�����������������������
//����set����¼�������Ƿ����ظ������飨.size==len��
//Ȼ���¼���ֵ����Сֵ�����
//��������������ظ���ֱ��break����Ϊ���涼���������������ˣ���ʱ���̶���
//��� ���ֵ-��Сֵ ���� �����±���������������Ӧ���䳤�Ƚ��++
//����a[2] = 1, a[3] = 2, a[4] = 3
//������ 3-1 = 4-2

const int MAXN = 1e4+5;
const int MOD = 1e9+7;
int n,m;
int a[MAXN], num[int(1e3+5)];//aΪԭ���飬num��¼��Ӧ���ȵ�������
void init() {
    for(int i = 1;i <= n;i++) {//ö���������
        set<int> st;
        int minn = INF;
        int maxx = -INF;
        for(int j = i;j <= n;j++) {//ö�������յ�
            st.insert(a[j]);//���뼯���У�ȥ��
            minn = min(minn, a[j]);//ȡ��Сֵ
            maxx = max(maxx, a[j]);//ȡ���ֵ
            int len = j-i+1;//��ǰ���䳤��
            // !=len ��˵���������ظ���ֱ�ӽ���
            // ��Χ>=1000Ҳֱ�ӽ�������Ϊ��ѯ����ֻ��1000
            if(st.size()!=len||maxx-minn>=1000) break;//�����˺ܶ����
            //����ֱ��break�����ܳ��ֵ�ǰ�����㣬������Ӻ����ֵ����������
            if(maxx-minn==len-1) num[len]++;//�������������Ӧ���䳤�Ƚ��++
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }
    init();//Ԥ����
    printf("Case #1:\n");
    while(m--) {
        int k;
        scanf("%d", &k);
        printf("%d\n", num[k]);
    }
	return 0;
}
