#include "Polynomial.hpp"

Polynomial::Polynomial(const std::map<int, double>& coefficients)
    : coefficients(coefficients)
{
}

Polynomial::~Polynomial() 
{
}

std::string Polynomial::getReducedForm() const
{
    std::string result;
    for (const auto& coeff : coefficients) {
        if (coeff.second == 0) 
            continue;
        if (!result.empty() && coeff.second > 0) {
            result += " + ";
        }
        if (!result.empty() && coeff.second < 0) {
            result += " - ";
        }
        result += (std::to_string(std::abs(coeff.second))) + " * X^" + std::to_string(coeff.first);
    }
    return result.empty() ? "0" : result + " = 0";
}

double Polynomial::calculateDiscriminant() const
{
    double a = 0.0, b = 0.0, c = 0.0;
    
    for (const auto& term : coefficients) {
        switch (term.first) {
            case 2: a = term.second; break;
            case 1: b = term.second; break;
            case 0: c = term.second; break;
            default: break;
        }
    }
    
    return b * b - 4 * a * c;
}

std::pair<std::complex<double>, std::complex<double>> Polynomial::getQuadraticRoots() const
{
    double a = 0.0;
    double b = 0.0;
    for (const auto& term : coefficients) {
        switch (term.first) {
            case 2: a = term.second; break;
            case 1: b = term.second; break;
            default: break;
        }
    }
    double discriminant = calculateDiscriminant();
    std::complex<double> root1((-b + std::sqrt(std::complex<double>(discriminant))) / (2.0 * a));
    std::complex<double> root2((-b - std::sqrt(std::complex<double>(discriminant))) / (2.0 * a));
    
    return {root1, root2};
}

void Polynomial::solveLinear()
{
    double b = 0.0;
    double c = 0.0;
    for (const auto& term : coefficients) {
        switch (term.first) {
            case 1: b = term.second; break;
            case 0: c = term.second; break;
            default: break;
        }
    }
    if (b == 0) {
        if (c == 0) {
            std::cout << "Any real number is a solution." << std::endl;
        } else {
            std::cout << "No solution" << std::endl;
        }
        return;
    }
    double root = -c / b;
    std::cout << "The solution is : " << root << std::endl;
}

void Polynomial::solveQuadratic()
{
    double discriminant = calculateDiscriminant();
    auto roots = getQuadraticRoots();
    if (discriminant < 0) {
        std::cout << "Discriminant is strictly negative, the two complex solutions are:" << std::endl;
        std::cout << roots.first.real() << " + " << roots.first.imag() << "i" << std::endl;
        std::cout << roots.second.real() << " + " << roots.second.imag() << "i" << std::endl;
    }
    else if (discriminant == 0) {
        // auto roots = getQuadraticRoots();
        std::cout << "Discriminant is zero, the solution is:" << std::endl;
        std::cout << roots.first.real() << std::endl;
    }
    else {
        std::cout << "Discriminant is strictly positive, the two solutions are:" << std::endl;
        std::cout << roots.first.real() << std::endl;
        std::cout << roots.second.real() << std::endl;
    }
}

void Polynomial::solve(int degree)
{
    if (degree <= 1) {
        solveLinear();
        return;
    }
    else if (degree == 2) {
        solveQuadratic();
        return;
    }
    else 
    {
        std::cout << "The polynomial degree is :" << degree << std::endl;
        std::cout << "The polynomial degree is strictly greater than 2, I can't solve" << std::endl;
    }
}