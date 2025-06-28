#include "Parser.hpp"

Parser::Parser() : maxDegree(0)
{
}

Parser::~Parser()
{
}

void Parser::deleteAllSpaces(std::string &input)
{
    std::string::iterator inputIterator = std::remove_if(input.begin(), input.end(), ::isspace);
    input.erase(inputIterator, input.end());
}

bool Parser::isInputValide(std::string& input)
{
    if (input.empty())
        return false;
    if (std::count(input.begin(), input.end(), '=') != 1)
        return false;
    coefficients.clear();
    maxDegree = 0;

    deleteAllSpaces(input);
    terms = splitEquation(input);
    for (const auto& term : terms) {
        if (term == "=") {
            continue;
        }
        if (term[0] == '0')
            continue;
        if (term.empty() || !isValidTerm(term)) {
            return false;
        }
    }
    return true;
}

void Parser::parsePolynomial()
{
    bool afterEquals = false;
    for (const auto& term : terms) {
        if (term == "=") {
            afterEquals = true;
            continue;
        }
        size_t pos = 0;
        double coef = 1.0;
        
        if (term[pos] == '-') {
            coef = -1.0;
            pos++;
        }

        size_t endPos;
        coef *= std::stod(term.substr(pos), &endPos);
        size_t powerPos = term.find_last_of('^') + 1;
        int power = std::stoi(term.substr(powerPos));
        if (afterEquals) {
            coef = -coef;
        }
        coefficients[power] += coef;
    }
}

int Parser::getDegree() const
{
    if (coefficients.empty()) {
        return 0;
    }
    for (auto it = coefficients.rbegin(); it != coefficients.rend(); ++it) {
        if (it->second != 0) {
            return it->first;
        }
    }
    return 0;
}

bool Parser::isValidTerm(const std::string& term)
{
    if (term.empty())
        return false;

    size_t pos = 0;
    
    if (term[pos] == '-') 
        pos++;
        

    if (!std::isdigit(term[pos]))
        return false;
    while (pos < term.size() && std::isdigit(term[pos]))
        pos++;
    if (pos < term.size() && term[pos] == '.')
    {
        pos++;
        if (pos >= term.size() || !std::isdigit(term[pos]))
            return false;
        while (pos < term.size() && std::isdigit(term[pos]))
            pos++;
    }

    if (pos >= term.size() || term[pos] != '*')
        return false;
    pos++;

    if (pos >= term.size() || term[pos] != 'X')
        return false;
    pos++;
    if (pos >= term.size() || term[pos] != '^')
        return false;
    pos++;
    
    if (pos >= term.size() || !std::isdigit(term[pos]))
        return false;

    while (pos < term.size() && std::isdigit(term[pos]))
        pos++;
    return pos == term.size();
}

std::vector<std::string> Parser::splitEquation(const std::string& input) {
    
    std::vector<std::string> terms;
    std::string term;
    
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == '=') {

            if (!term.empty()) {
                terms.push_back(term);
                term.clear();
            }
            term += input[i];
            terms.push_back(term);
            term.clear();
            continue;
        }
        
        if ((input[i] == '+' || input[i] == '-') && i > 0) {
            if (!term.empty()) {
                terms.push_back(term);
                term.clear();
            }
            if (input[i] == '+')
                continue;
            term = input[i];
        } else {
            term += input[i];
        }
    }
    
    if (!term.empty()) {
        terms.push_back(term);
    }
    
    return terms;
}