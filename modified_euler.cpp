#include<bits/stdc++.h>
using namespace std;

// Define the differential equation dy/dx = f(x, y)
double f(double x, double y) {
    return x + y;
}

// Modified Euler's method implementation
double modifiedEuler(double x0, double y0, double h, double x_target) {
    double x = x0;
    double y = y0;
    int n= (int)(x_target/h);
    while (n--) {
        double f0 = f(x, y);
        double x_temp = x + h;
        double y_temp = y + h * f0;
        double f1 = f(x_temp, y_temp);

        // Calculate the average slope
        double slope_avg = (f0 + f1) / 2.0;

        // Update y using the average slope
        y = y + h * slope_avg;
        x = x_temp;
    }

    return y;
}

int main() {
    double x0 = 0.0;         // Initial x value
    double y0 = 1.0;         // Initial y value
    double h = 0.05;          // Step size
    double x_target = 0.1;   // Target x value

    double result = modifiedEuler(x0, y0, h, x_target);

    cout << "Approximate solution at x = " << x_target << ": " << result << endl;

    return 0;
}
