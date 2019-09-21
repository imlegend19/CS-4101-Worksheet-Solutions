#include <bits/stdc++.h>
#include <cmath>

typedef long double ld;

using namespace std;

ld q1a(ld x) { return -(x*x) / (powl(x, 3) + cos(x)); }
ld q1b(ld x) { return (powl(x, 4) - powl(x, 3) - powl(x, 2)) / exp(-powl(x, 2)); }
ld q1c(ld x) { return sin(x) / sqrt(x); }
ld q1d(ld x) { return cos(x) / sqrt(x); }
ld q1e(ld x) { return (x + 1) * powl((x - 3), 2) * powl(x + 7, -2); }
ld q1f(ld x) { return (x - 2) * powl((x - 3), 2) * powl(x - 5, 3); }
ld q1g(ld x) { return 1 - exp(-powl(x - 3, 2)); }
ld q1h(ld x) { return cyl_bessel_jl(0, x) - exp(-(x - 3)); }
ld q1i(ld x) { return 0.5 * powl(x, 2) + (2 * cos(x)); }
ld q1j(ld x) { return powl(x, 100); }

ld * quadratic_fit_search(ld a, ld b, ld c) {

}

int main() {
    ios_base::sync_with_stdio(false);

}
