#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <limits>

const int FLOAT_SIZE = sizeof(float) * CHAR_BIT;

void DumpFloat(float *p);
void ForceFloat(float *p, std::string s);
long ConvertBinaryToDecimal(std::string bin);

int main()
{
    return 0;
}

void DumpFloat(float *p)
{
    // use long to make sure have 4 bytes
    // cast float to long have same bits
    long y = *(long *)p;

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
    long temp = ConvertBinaryToDecimal(r);

    // cast long to float
    *p = *(float *) &temp;
    std::cout << *p << "\n";
}

long ConvertBinaryToDecimal(std::string bin)
{
    long dec = 0;
    int size = bin.size();
    for (int i=0; i < size; i++)
    {
        dec += (bin[size - 1 - i] - '0') * pow(2, i);
    }
    return dec;
}