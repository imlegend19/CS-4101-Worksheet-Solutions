//
// Created by imlegend19 on 06/12/19.
//

#include <bits/stdc++.h>
#include <cmath>

#define N 4

typedef long double ld;

typedef ld (*Function)(ld x);

const ld epsilon = 0.0001;
const ld gm = (1 + sqrt(5)) / 2;
const ld dh = sqrt(DBL_EPSILON);

using namespace std;

template<class T>
void display(T A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }

    cout << endl;
}

ld m = 1;
ld k = 123456;

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

ld q3b(ld x) { return (x - 1) * powl(x - 3, 2); }

ld eval(ld x) { return k * (x - 7) * exp(-m * pow(x - 5, 2)); }

ld derivative(Function f, ld x) { return (f(x + dh) - f(x - dh)) / 2 * dh; }

ld double_derivative(Function f, ld x) { return (f(x + dh) - 2 * f(x) + f(x - dh)) / powl(dh, 2); }

//for extrema
ld *newton_raphson(Function f, ld a) {
    int eval = 0;
    int iter = 0;
    while (a <= 5 and iter <= 1000) {
        ld h = derivative(f, a) / double_derivative(f, a);
        a -= h;
        eval += 1;
        iter += 1;
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

// for minima
ld *qfs_minima(ld a, ld b, ld c, Function f, int n) {
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
        return new ld[2]{a, ya};
    else if (yb <= ya && yb <= yc)
        return new ld[2]{b, yb};
    else
        return new ld[2]{c, yc};
}

void transpose(int A[][N], int B[][N]) {
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            B[i][j] = A[j][i];
}

void multiply(int mat1[][N], int mat2[][N], int res[][N]) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            res[i][j] = 0;
            for (k = 0; k < N; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}

void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n) {
    int i = 0, j = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinantOfMatrix(int mat[N][N], int n) {
    int D = 0;
    if (n == 1)
        return mat[0][0];

    int temp[N][N];
    int sign = 1;

    for (int f = 0; f < n; f++) {
        getCofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f] * determinantOfMatrix(temp, n - 1);
        sign = -sign;
    }

    return D;
}

void adjoint(int A[N][N], int adj[N][N]) {
    int sign, temp[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            getCofactor(A, temp, i, j, N);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (sign) * (determinantOfMatrix(temp, N - 1));
        }
    }
}

bool inverse(int A[N][N], float inverse[N][N]) {
    int det = determinantOfMatrix(A, N);
    if (det == 0) {
        cout << "Singular matrix, can't find its inverse";
        return false;
    }

    int adj[N][N];
    adjoint(A, adj);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            inverse[i][j] = (float) adj[i][j] / float(det);

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);

    Function funcs[] = {q1a, q1b, q1c, q1d, q1e, q1f, q1g, q1h, q1i, q1j};
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

    cout << "Quadratic Fit Search" << endl;
    cout << "--------------------" << endl;

    ld *max = quadratic_fit_search(2, 6, 7.5, eval, 100);
    cout << "The maximum value is " << max[1] << " at " << max[0] << endl;

    cout << "1D Line Search - Golden Section Search" << endl;
    cout << "--------------------" << endl;

    max = golden_search(eval, 2.1, 7.9);
    cout << "The maximum value is " << max[1] << " at " << max[0] << " in "
         << (int) max[2]
         << " evaluations. " << endl;

    cout << "--------------------" << endl;
    cout << "--------------------" << endl;

    cout << "Newton-Raphson Method" << endl;
    cout << "--------------------" << endl;

    max = newton_raphson(eval, 7.22);
        cout << "The maximum value is " << max[1] << " at " << max[0] << " in "
             << (int) max[2]
             << " evaluations. " << endl;

    cout << "--------------------" << endl;
    cout << "--------------------" << endl;

    return 0;
}

