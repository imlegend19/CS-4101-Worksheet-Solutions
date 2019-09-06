import matplotlib.pyplot as plt
import numpy as np

FibArray = [1, 1]
N = 10


def fibonacci(n):
    if n < 0:
        print("Incorrect input")
    elif n <= len(FibArray):
        return FibArray[n - 1]
    else:
        temp_fib = fibonacci(n - 1) + fibonacci(n - 2)
        FibArray.append(temp_fib)
        return temp_fib


def graph(func, x_range):
    x = np.arange(*x_range)
    y = func(x)

    print(max(y))

    plt.plot(x, y)
    plt.show()


def evaluate_function(func, val):
    return func(val)


def fibonacci_method(a, b, it):
    l1 = b - a
    k = 2
    lk = (fibonacci(10 - k + 1) / fibonacci(10 + 1)) * l1

    x1 = a + lk
    x2 = a - lk

    fx1 = evaluate_function(lambda x: (x ** 5) * (np.exp(-x)), x1)
    fx2 = evaluate_function(lambda x: (x ** 5) * (np.exp(-x)), x2)

    if it == 0:
        return [a, b]
    else:
        if fx1 > fx2:
            fibonacci_method(x1, b, it - 1)
        else:
            fibonacci_method(a, x2, it - 1)


# graph(lambda x: x * np.exp(-x), (0, 5))
# graph(lambda x: x ** 2 * np.exp(-(x ** 2)), (0, 5))

if __name__ == '__main__':
    a1 = 0
    b1 = 0
    for i in range(100):
        try:
            iteration = i
            x = fibonacci_method(0.5, 1.5, iteration)
            if x[0] == a1 and x[1] == b1:
                print(i)
                break
        except RecursionError:
            print(i)
            break

print(3125 / np.exp(5))
