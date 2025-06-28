#include <iostream>
#include "parser/Parser.hpp"
#include "Polynomial/Polynomial.hpp"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    std::string input(argv[1]);
    Parser parser;

    if (!parser.isInputValide(input)) {
        std::cerr << "Invalid input: " << input << std::endl;
        return 1;
    }
    parser.parsePolynomial();
    Polynomial polynomial(parser.getCoefficients());
    std::cout << "Reduced form: " << polynomial.getReducedForm() << std::endl;
    polynomial.solve(parser.getDegree());
    
}