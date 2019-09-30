#include <bits/stdc++.h>
#include <cmath>

typedef long double ld;

typedef ld (*Function)(ld x);

const ld epsilon = 0.0001;
const ld gm = (1 + sqrt(5)) / 2;
const ld dh = sqrt(DBL_EPSILON);

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

ld derivative(Function f, ld x) { return (f(x + dh) - f(x - dh)) / 2 * dh; }

ld double_derivative(Function f, ld x) { return (f(x + dh) - 2 * f(x) + f(x - dh)) / powl(dh, 2); }

//for extrema
ld *newton_raphson(Function f, ld a) {
    ld h = derivative(f, a) / double_derivative(f, a);

    int eval = 0;
    while (a <= 5) {
        h = derivative(f, a) / double_derivative(f, a);
        a -= h;
        eval += 1;
    }

    return new ld[3]{a, f(a), (ld) eval};
}

// for extrema
ld *golden_search(Function f, ld a, ld b) {
    ld L0 = b - a;
    ld prevRatio = 1 / gm * L0;
    ld x1, x2;

    int eval = 2;
    while (prevRatio > epsilon) {
        prevRatio = powl(1 / gm, eval) * L0;
        x1 = a + prevRatio;
        x2 = b - prevRatio;

        if (x1 < x2) {
            if (f(x1) > f(x2)) {
                b = x2;
            } else {
                a = x1;
            }
        } else {
            if (f(x1) > f(x2)) {
                a = x2;
            } else {
                b = x1;
            }
        }

        eval += 1;
    }

    if (f(a) > f(b)) {
        return new ld[3]{a, f(a), (ld) eval - 1};
    } else {
        return new ld[3]{b, f(b), (ld) eval - 1};
    }
}

// for extrema
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
                a = b;
                ya = yb;
                b = x;
                yb = yx;
            } else {
                c = x;
                yc = yx;
            }
        } else if (x < b) {
            if (yx > yb) {
                c = b;
                yc = yb;
                b = x;
                yb = yx;
            } else {
                a = x;
                ya = yx;
            }
        }
    }

    if (ya >= yb && ya >= yc)
        return new ld[2]{a, ya};
    else if (yb >= ya && yb >= yc)
        return new ld[2]{b, yb};
    else
        return new ld[2]{c, yc};
}

int main() {
    ios_base::sync_with_stdio(false);

    Function funcs[] = {q1a, q1b, q1c, q1d, q1e, q1f, q1g, q1h, q1i, q1j};
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

    cout << "Quadratic Fit Search" << endl;
    cout << "--------------------" << endl;

    for (int i = 0; i < 10; i++) {
        ld *max;
        if (i != 3) {
            max = quadratic_fit_search(0, 1 / exp(1), 5, funcs[i], 10);
        } else {
            max = quadratic_fit_search(0.5, 0.5 / exp(1), 5, funcs[i], 10);
        }
        cout << "The maximum value for Q1-(" << letters[i] << ") is " << max[1] << " at " << max[0] << endl;
    }

    cout << "--------------------" << endl;
    cout << "--------------------" << endl;

    cout << "1D Line Search - Golden Section Search" << endl;
    cout << "--------------------" << endl;

    for (int i = 0; i < 10; i++) {
        ld *max = golden_search(funcs[i], 0, 5);
        cout << "The maximum value for Q1-(" << letters[i] << ") is " << max[1] << " at " << max[0] << " in "
             << (int) max[2]
             << " evaluations. " << endl;
    }

    cout << "--------------------" << endl;
    cout << "--------------------" << endl;

    cout << "Newton-Raphson Method" << endl;
    cout << "--------------------" << endl;

    for (int i = 0; i < 10; i++) {
        ld *max = newton_raphson(funcs[i], 1);
        cout << "The maximum value for Q1-(" << letters[i] << ") is " << max[1] << " at " << max[0] << " in "
             << (int) max[2]
             << " evaluations. " << endl;
    }

    cout << "--------------------" << endl;

    return 0;
}
