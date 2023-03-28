#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <limits>

const int FLOAT_SIZE = sizeof(float) * CHAR_BIT;

void DumpFloat(float *p);
void ForceFloat(float *p, std::string s);
uint32_t ConvertBinaryToDecimal(std::string bin);

int main()
{
    float x;
    ForceFloat(&x, "01111111110000000000000000000000");
    std::cout << x;
    return 0;
}

void DumpFloat(float *p)
{
    // use uint32_t to make sure have 4 bytes
    // cast float to uint32_t have same bits
    uint32_t y;
    memcpy_s(&y, sizeof(uint32_t), p, sizeof(float));

    // store bit in int array
    int bin[FLOAT_SIZE];

    for (int i = 0; i < FLOAT_SIZE; i++)
    {
        bin[i] = ((1 << i) & y) != 0 
                 ? 1 
                 : 0;
    }

    // print bit
    for (int i = FLOAT_SIZE - 1; i >= 0; --i)
    {
        std::cout << bin[i];
    }
}

void ForceFloat(float *p, std::string s)
{
    // MSB first
    std::string r;
    int idxLSB = FLOAT_SIZE - s.length();
    for (int i=0; i < idxLSB; i++)
    {
        r.append("0");
    }
    r += s;

    // calculate long from bit
    uint32_t temp = ConvertBinaryToDecimal(r);

    // cast long to float
    memcpy_s(p, sizeof(float), &temp, sizeof(uint32_t));
}

uint32_t ConvertBinaryToDecimal(std::string bin)
{
    uint32_t dec = 0;
    int size = bin.size();
    for (int i=0; i < size; i++)
    {
        dec += (bin[size - 1 - i] - '0') * pow(2, i);
    }
    return dec;
}
