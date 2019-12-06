import math


def func(x):
    return x ** 3 + (2 * math.exp(-100 * x)) / x


def quadratic_search(f, a, b, c, n):
    ya, yb, yc = f(a), f(b), f(c)
    for _ in range(1, n - 3):
        x = 0.5 * (ya * (b ** 2 - c ** 2) + yb * (c ** 2 - a ** 2) + yc * (a ** 2 - b ** 2)) / (
                ya * (b - c) + yb * (c - a)
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
    a1, b1, c1 = quadratic_search(f=func, a=0.11, b=0.45, c=0.99, n=100)
    print(min(a1, b1, c1))
