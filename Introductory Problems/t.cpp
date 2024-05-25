#include <iostream>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int q, k;
    cin >> q;
    while (q--) {
        cin >> k;
        int lv = 1, ten = 1;
        while (k >= lv * 9 * ten) {
            k -= lv * 9 * ten;
            lv++;
            ten *= 10;
        }
        int s = (k-1) / lv;
        int n = ten + s;
        for (int i = lv; i > k - s*lv; i--) {
            n /= 10;
        }
        cout << n % 10 << '\n';
    }
}