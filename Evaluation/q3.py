import math

# a)
k = 1
m = 12345

# b)
# k = 1
# m = 1

# c)
# k = 12345
# m = 1


def quadratic_search(f, a, b, c, n):
    ya, yb, yc = f(a), f(b), f(c)
    for i in range(1, n - 3):
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


def objective(x):
    return k * (x - 7) * (math.e ** (-m * (x - 5) ** 2))


if __name__ == '__main__':
    a1, b1, c1 = quadratic_search(objective, n=1000, a=2.1, b=5, c=7.99)
    print(min(a1, b1, c1))
    print(objective(min(a1, b1, c1)))
