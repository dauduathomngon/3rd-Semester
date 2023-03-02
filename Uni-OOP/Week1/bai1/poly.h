#ifndef POLY_H
#define POLY_H

#include <algorithm>
#include <vector>

class Polynomial
{
public:
    Polynomial(int degree, std::vector<double> arrCoefficent, std::vector<char> arrVariable)
    {
        m_degree = degree;
        m_arrCoef = arrCoefficent;
        m_arrVar = arrVariable;
    }

    ~Polynomial() {}

    void print();

    std::vector<double> get_coefficent()
    {
        return m_arrCoef;
    }

    std::vector<char> get_variable()
    {
        return m_arrVar;
    }

    int get_degree()
    {
        return m_degree;
    }
private:
    int m_degree;
    std::vector<double> m_arrCoef;
    std::vector<char> m_arrVar;
};

#endif // POLY_H