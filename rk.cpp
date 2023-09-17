#include<bits/stdc++.h>
using namespace std;

// Define the differential equation dy/dx = f(x, y)
double f(double x, double y) {
    return x + y;
}

// RK4 method implementation
double rungeKutta(double x0, double y0, double h, double x_target) {
    double x = x0;
    double y = y0;

    while (x < x_target) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2.0, y + k1 / 2.0);
        double k3 = h * f(x + h / 2.0, y + k2 / 2.0);
        double k4 = h * f(x + h, y + k3);

        // Update y using the weighted average of the four slopes
        y = y + (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
        x = x + h;
    }

    return y;
}

int main() {
    double x0 = 0.0;         // Initial x value
    double y0 = 1.0;         // Initial y value
    double h = 0.1;          // Step size
    double x_target = 0.2;   // Target x value

    double result = rungeKutta(x0, y0, h, x_target);

    cout << "Approximate solution at x = " << x_target << ": " << result << endl;

    return 0;
}
