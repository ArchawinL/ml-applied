#include "linear_regression.h"
#include <numeric>  // For accumulate
#include <cmath>    // For mathematical functions
#include <bits/stdc++.h>


// Constructor
LinearRegression::LinearRegression() : slope(0.0), intercept(0.0) {}

void LinearRegression::fit(const std::vector<double>& X, 
                           const std::vector<double>& y) {
    // TODO: Implement using the formulas:
    // slope = covariance(X, y) / variance(X)
    // intercept = mean(y) - slope * mean(X)
                            
    assert(X.size() == y.size());

    int N = X.size();
    

    double mean_X = accumulate(X.begin(),  X.end(), 0.0) / N;
    double mean_y = accumulate(y.begin(),  y.end(), 0.0) / N;
    
    double covariance = 0.0;
    double variance = 0.0;
    
    for (int i=0; i < N; i++){

        covariance += (X[i] - mean_X) * (y[i] - mean_y);
        variance += pow((X[i] - mean_X), 2);        

    }

    covariance = covariance / N;
    variance = variance / N;

    slope = covariance / variance;
    intercept = mean_y - slope * mean_X;

} 



double LinearRegression::predict(double x) const {
    return slope * x + intercept;
}

std::vector<double> LinearRegression::predict(const std::vector<double>& X) const {
    std::vector<double> predictions;
    predictions.reserve(X.size());  // Optimisation: pre-allocate
    
    for (double x : X) {
        predictions.push_back(predict(x));
    }
    return predictions;
}