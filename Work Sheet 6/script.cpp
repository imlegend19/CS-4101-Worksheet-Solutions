#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, num[10] = {0}, i = 0, max = -1, idx = -1, printed = 0;
        cin >> n;
        int temp = 0;
        temp = n;
        while (temp > 0) {
            num[i] = temp % 10;
            temp = temp / 10;
            if (num[i] >= max) {
                max = num[i];
                idx = i;
            } else if (num[i] == 0) {
                max = -1;
            }
            //cout<<num[i]<<endl;
            i++;

        }
        idx = i - 1 - idx;
        for (int j = i - 1; j >= 0; j--) {
            if (j != i - 1 - idx) {
                if (num[j] == 0) {
                    if (printed == 1) {
                        cout << num[j];
                        printed = 1;
                    } else
                        continue;
                } else {
                    cout << num[j];
                    printed = 1;
                }
            }
        }

        if (printed == 0) {
            cout << 0;
        }

        cout << endl;
    }
}
