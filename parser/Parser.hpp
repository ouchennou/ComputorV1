#ifndef PARSER_HPP
#define PARSER_HPP
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>

class Parser
{
    private:
        void deleteAllSpaces(std::string& input);
        std::vector<std::string> splitEquation(const std::string& input);
        bool isValidTerm(const std::string& term);
        std::map<int, double> coefficients;
        std::vector<std::string> terms;
        int maxDegree;                       
    public:
        Parser();
        ~Parser(); 
        bool isInputValide(std::string& input);
        const std::map<int, double>& getCoefficients() const { return coefficients; }
        int getDegree() const;
        void parsePolynomial();
};

#endif