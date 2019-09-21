#include <bits/stdc++.h>
#include <cmath>

typedef long double ld;
typedef ld (*Function) (ld x);

using namespace std;

ld q1a(ld x) { return -(x * x) / (powl(x, 3) + cos(x)); }

ld q1b(ld x) { return (powl(x, 4) - powl(x, 3) - powl(x, 2)) / exp(-powl(x, 2)); }

ld q1c(ld x) { return sin(x) / sqrt(x); }

ld q1d(ld x) { return cos(x) / sqrt(x); }

ld q1e(ld x) { return (x + 1) * powl((x - 3), 2) * powl(x + 7, -2); }

ld q1f(ld x) { return (x - 2) * powl((x - 3), 2) * powl(x - 5, 3); }

ld q1g(ld x) { return 1 - exp(-powl(x - 3, 2)); }

ld q1h(ld x) { return cyl_bessel_jl(0, x) - exp(-(x - 3)); }

ld q1i(ld x) { return 0.5 * powl(x, 2) + (2 * cos(x)); }

ld q1j(ld x) { return powl(x, 100); }

ld *quadratic_fit_search(ld a, ld b, ld c, Function f, int n) {
    ld ya, yb, yc;
    ya = f(a);
    yb = f(b);
    yc = f(c);

    for (int i = 0; i < n - 3; i++) {
        ld x = 0.5 * ((ya * (b * b - c * c) + yb * (c * c - a * a) + yc * (a * a - b * b))) /
               ((ya * (b - c) + yb * (c - a) + yc * (a - b)));

        ld yx = f(x);

        if (x > b) {
            if (yx > yb) {
                c = x;
                yc = yx;
            } else {
                a = b;
                ya = yb;
                b = x;
                yb = yx;
            }
        } else if (x < b) {
            if (yx > yb) {
                a = x;
                ya = yx;
            } else {
                c = b;
                yc = yb;
                b = x;
                yb = yx;
            }
        }
    }

    if (ya <= yb && ya <= yc)
        return new ld[2] {a, ya};
    else if (b <= a && b <= c)
        return new ld[2] {b, yb};
    else
        return new ld[2] {c, yc};
}

int main() {
    ios_base::sync_with_stdio(false);

    Function funcs[] = {q1a, q1b, q1c, q1d, q1e, q1f, q1g, q1h, q1i, q1j};
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

    cout << "Quadratic Fit Search" << endl;
    cout << "--------------------" << endl;

    for (int i=0; i<10; i++) {
        ld *min = quadratic_fit_search(1, 3, 5, funcs[i], 10);
        cout << "The minimum value for Q1-(" << letters[i] << ") is " << min[1] << " at " << min[0] << endl;
    }

    cout << "--------------------" << endl;

    return 0;
}
