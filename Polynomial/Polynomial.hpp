#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <vector>
#include <string>
#include <complex>
#include <iomanip>
#include "../parser/Parser.hpp"

class Polynomial {
public:
    Polynomial(const std::map<int,double>& terms);
    ~Polynomial();

    void solve(int degree);
    std::string getReducedForm() const;
    
private:
    std::map<int, double> coefficients;
    void solveLinear();
    void solveQuadratic();
    double calculateDiscriminant() const;
    std::pair<std::complex<double>, std::complex<double> > getQuadraticRoots() const;
};

#endif