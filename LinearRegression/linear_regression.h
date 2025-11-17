#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H
#include <vector>

class LinearRegression {
private:
    double slope;
    double intercept;

public:
    LinearRegression(); // Constructor

    void fit(const std::vector<double>& X, const std::vector<double>& y);
    double predict(double x) const;
    std::vector<double> predict(const std::vector<double>& X) const; //Const at the end means, no modification on object's state

    double getSlope() const {return slope;}
    double getIntercept() const {return intercept;}

};

#endif
