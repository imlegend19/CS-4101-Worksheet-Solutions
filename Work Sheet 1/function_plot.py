import math
import matplotlib.pyplot as plt


# Function Definitions
def function_1(value_x):
    return 2 - (1 / value_x)


def function_2(value_x):
    return value_x + math.log(value_x)


def function_3(value_x):
    return (2 - value_x**2) / (5 + value_x**2)


def function_4(value_x):
    return (value_x**3) + (5 * value_x**2) - (10 * value_x) - 2


# Function plotting code
# x_axes = [i/100 for i in range(1, 300)]
# y_axes = []
#
# for i in x_axes:
#     y_axes.append([
#         function_1(i),
#         function_2(i),
#         function_3(i),
#         function_4(i)
#     ])
#
# plt.plot(x_axes, [i[0] for i in y_axes], label='2 - (1/x)')
# plt.plot(x_axes, [i[1] for i in y_axes], label='x + ln(x)')
# plt.plot(x_axes, [i[2] for i in y_axes], label='(2 - (x**2)) / (5 + (x**2))')
# plt.plot(x_axes, [i[3] for i in y_axes], label='x**3 + (5 * (x**2) - (10 * x) - 2)')
# plt.legend()
# plt.title('x vs f(x)')
# plt.xlabel('Value of x')
# plt.ylabel('Value of f(x)')
# plt.show()


# Root finding code


