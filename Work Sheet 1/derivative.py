import math
import matplotlib.pyplot as plt


# First Order Derivatives
def forward_order_derivative(function_definition, value_x, value_h):
    return (function_definition(value_x + value_h) - function_definition(value_x)) / value_h


def backward_order_derivative(function_definition, value_x, value_h):
    return (function_definition(value_x) - function_definition(value_x - value_h)) / value_h


def central_order_derivative(function_definition, value_x, value_h):
    return (function_definition(value_x + value_h) - function_definition(value_x - value_h)) / (2 * value_h)


# Function Definitions
def function_1(value_x):  # x - ln(x)
    # return value_x - math.log(value_x)
    # return math.cos(value_x ** 2)
    return math.tan(value_x)


def function_1_derivative(value_x):
    # return 1 - (1 / value_x)
    # return -math.sin(value_x ** 2) * (2 * value_x)
    return (1/math.cos(x)) ** 2


# Main Code
x = 0.09
h = 0.001

x_axes = []

y_axes_derivative_values = []
y_axes_percentage_error = []
y_axes_magnitude_error = []

print('--------------------------------------------------------------------------------------------------------')
print('|     x    |      h     |    f(x)    |  f\'(x) Computed  |  f\'(x) Calculated  |   Error    |  Error %  |')
print('--------------------------------------------------------------------------------------------------------')

for i in range(1, 6):
    print('| %f |  %f  |  %f  |    %f    |     %f     |  %f  | %f |'
          % (x, h, function_1(x),
             forward_order_derivative(function_1, x, h),
             function_1_derivative(x),
             abs(forward_order_derivative(function_1, x, h) - function_1_derivative(x)),
             abs((forward_order_derivative(function_1, x, h) - function_1_derivative(x)) / function_1_derivative(x))) * 100
          )
    x_axes.append(h)
    y_axes_derivative_values.append([function_1_derivative(x),
                                     forward_order_derivative(function_1, x, h),
                                     backward_order_derivative(function_1, x, h),
                                     central_order_derivative(function_1, x, h)
                                     ])
    y_axes_percentage_error.append(
        abs((forward_order_derivative(function_1, x, h) - function_1_derivative(x)) / function_1_derivative(x) * 100)
    )
    y_axes_magnitude_error.append(
        abs(forward_order_derivative(function_1, x, h) - function_1_derivative(x))
    )
    h /= 10

plt.plot(x_axes,
         [y_axes_derivative_values[i][0] for i in range(len(y_axes_derivative_values))],
         label='Calculated')
plt.plot(x_axes,
         [y_axes_derivative_values[i][1] for i in range(len(y_axes_derivative_values))],
         label='Computed (Forward)')
plt.plot(x_axes,
         [y_axes_derivative_values[i][2] for i in range(len(y_axes_derivative_values))],
         label='Computed (Backward)')
plt.plot(x_axes,
         [y_axes_derivative_values[i][3] for i in range(len(y_axes_derivative_values))],
         label='Computed (Central)')
plt.xlabel('Value of h')
plt.ylabel('Value of derivative')
plt.title('First Derivative (Computed vs Calculated)')
plt.legend()
plt.show()

plt.plot(x_axes, y_axes_magnitude_error)
plt.xlabel('Value of h')
plt.ylabel('Percentage Error')
plt.title('h vs magnitude of error')
plt.show()


plt.plot(x_axes, y_axes_percentage_error)
plt.xlabel('Value of h')
plt.ylabel('Percentage Error')
plt.title('h vs percentage error')
plt.show()
