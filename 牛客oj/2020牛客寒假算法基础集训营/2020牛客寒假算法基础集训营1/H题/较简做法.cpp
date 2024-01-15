//���볤�ȣ�486 ����ʱ�䣺 24 ms ռ���ڴ棺804K

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int maxn = 2e5 + 10;

map<char, int> q;

char x[maxn];

int main() {
    int n, k;
    cin >> n >> k;
    cin >> x;
    int start = 0, end = 0, sum = 0;
    while (start <= end && end < n) {
        q[x[end]]++;//���0��1������
        while (min(q['0'], q['1']) > k )//�Ӵ�����������
        {
            q[x[start++]]--;//���Ʋ���ȥ���
        }
        if (min(q['0'], q['1']) <= k) {
            if (end - start + 1 > sum) {//�ϴ�����´�
                sum = end - start + 1;
            }
        }
        end++;
    }
    cout << sum << endl;
    return 0;
}
