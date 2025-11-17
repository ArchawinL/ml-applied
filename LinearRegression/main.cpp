#include <iostream>
#include "linear_regression.h"

int main() {
    // Test dataset
    std::vector<double> X = {1, 2, 3, 4, 5};
    std::vector<double> y = {2, 4, 5, 4, 5};
    
    LinearRegression model;
    model.fit(X, y);
    
    std::cout << "Slope: " << model.getSlope() << std::endl;
    std::cout << "Intercept: " << model.getIntercept() << std::endl;
    
    // Make predictions
    double test_x = 6.0;
    std::cout << "Prediction for x=" << test_x << ": " 
              << model.predict(test_x) << std::endl;
    
    return 0;
}