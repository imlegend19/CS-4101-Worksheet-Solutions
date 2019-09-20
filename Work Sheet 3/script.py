import numpy as np
import scipy as sp


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


if __name__ == '__main__':
    """
    Bessel Function is an oscillation curve with decay.
    
    :param np.cos(x) / x**0.5 -> Bessel Half Function
    :param sp.jv -> Bessel Function
    """
    funcs = {
        1: lambda x: (-x ** 2 / (x ** 3 + np.cos(x))),
        2: lambda x: (x**4 - x**3 - x**2) * np.exp(-x**2),
        3: lambda x: np.sin(x) / x**0.5,
        4: lambda x: np.cos(x) / x**0.5,
        5: lambda x: (x + 1)*((x - 3)**2)*((x + 7)**(-2)),
        6: lambda x: (x - 2)*((x - 3)**2)*((x - 5)**2),
        7: lambda x: 1 - np.exp(-(x - 3)**2),
    }

    a1, a2, a3 = quadratic_search(lambda x: (-x ** 2 / (x ** 3 + np.cos(x))), 0.5, 2, 4, 10)
    print(a1, a2, a3)
