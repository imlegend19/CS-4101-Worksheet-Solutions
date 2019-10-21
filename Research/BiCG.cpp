//
// Created by imlegend19 on 21/10/19.
//

#include <bits/stdc++.h>

using namespace std;

#define N 3
#define MAX 100

void subtract(double  sub[], const double  a[N], const double  b[N]) {
    for (int  i = 0; i < N; ++i)
        sub[i] = a[i] - b[i];
}

void multiply(double  a[N][N], const double  b[N], double  mul[N]) {
    for (int  i = 0; i < N; i++) {
        double  sum = 0;
        for (int  j = 0; j < N; j++) {
            sum += a[i][j] * b[i];
        }

        mul[i] = sum;
    }
}

double  *multiply(double  beta, const double  a[N]) {
    auto *b = new double [N];
    for (int  i = 0; i < N; i++) {
        b[i] = a[i] * beta;
    }

    return b;
}

double  transpose_multiply(const double a[], const double b[]) {
    double p = 0;
    for (int  i = 0; i < N; i++) {
        p += a[i] * b[i];
    }

    return p;
}

void transpose(double  b[N][N], double  a[][N]) {
    for (int  i = 0; i < N; i++)
        for (int  j = 0; j < N; j++)
            b[i][j] = a[j][i];
}

void add(double  ans[], const double  a[], const double  b[]) {
    for (int  i = 0; i < N; i++) {
        ans[i] = a[i] + b[i];
    }
}

int  main() {
    cout << "Enter the A: " << endl;
    double  A[N][N], b[N], x[MAX][N], r[MAX][N], rp[MAX][N], z[N], zp[N], p[MAX], d[MAX][N], dp[MAX][N], alpha, beta,
    q[N], qp[N];

    int i, j, iter;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter matrix b: " << endl;
    for (i = 0; i < N; i++) {
        cin >> b[i];
    }

    cout << "Enter the initial guess: " << endl;
    for (i = 0; i < N; i++) {
        cin >> x[0][i];
    }

    cout << "Enter the number of iterations: ";
    cin >> iter;

    double  mul[N];
    multiply(A, b, mul);
    subtract(r[i], b, mul);

    for (i = 0; i < iter; i++) {
        copy(begin(r[i]), end(r[i]), begin(z));
        copy(begin(rp[i]), end(rp[i]), begin(zp));

        p[i] = transpose_multiply(z, rp[i]);
        if (p[i] == 0) {
            cout << "Method fails." << endl;
            break;
        }

        if (i == 0) {
            copy(begin(z), end(z), begin(d[i+1]));
            copy(begin(zp), end(zp), begin(dp[i+1]));
        } else {
            beta = p[i] / p[i - 1];

            double  *ans = multiply(beta, d[i]);
            add(d[i], z, ans);

            ans = multiply(beta, dp[i]);
            add(dp[i], z, ans);
        }

        multiply(A, d[i+1], q);
        double  tran[N][N];
        transpose(tran, A);
        multiply(tran, dp[i+1], qp);

        alpha = p[i] / transpose_multiply(d[i+1], q);

        double  *ans = multiply(alpha, d[i+1]);
        add(x[i+1], x[i], ans);

        ans = multiply(alpha, q);
        subtract(r[i+1], r[i], ans);

        ans = multiply(alpha, qp);
        subtract(rp[i+1], rp[i], ans);
    }

    for (i=0; i<N; i++) {
        cout << x[i] << endl;
    }

    return 0;
}
