import numpy as np


def quadratic_search(f, a, b, c, n):
    ya, yb, yc = f(a), f(b), f(c)
    for i in range(1, n-3):
        x = 0.5 * (ya * (b**2-c**2) + yb * (c**2 - a**2) + yc*(a**2 - b**2)) / (ya * (b - c) + yb * (c - a)
                                                                                + yc * (a - b))
        yx = f(x)
        if x > b:
            if yx > yb:
                c, yc = x, yx
            else:
                a, ya, b, yb = b, yb, x, yx
        elif x < b:
            if yx > yb:
                a, ya = x, yx
            else:
                c, yc, b, yb = b, yb, x, yx

    return a, b, c


if __name__ == '__main__':
    a, b, c = quadratic_search(lambda x: (-x**2/(x**3 + np.cos(x))), 0.5, 2, 4, 10)
    print(a, b, c)
