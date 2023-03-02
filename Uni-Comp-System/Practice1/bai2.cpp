#include <iostream>
#include <string>
#include <math.h>

std::string SumTwoBit(std::string firstBit, std::string lastBit);

std::string TakeComplement(std::string bin);

std::string SubtractTwoBit(std::string firstBit, std::string lastBit);

std::string ShiftRight(std::string bin);

std::string MultiplyTwoBit(std::string firstBit, std::string lastBit);

std::string ShiftLeft(std::string bin);

std::string DivineTwoBit(std::string firstBit, std::string lastBit);

int BitToDecimal(std::string bin);

int main()
{
    std::string bit1 {"00000101"};
    std::string bit2 {"00000111"};
    
    std::string bit3 {"00110010"};

    std::cout << "This is bit: " << bit1 << " and this is number: " << BitToDecimal(bit1) << "\n"
              << "This is bit: " << bit2 << " and this is number: " << BitToDecimal(bit2) << "\n"
              << "This is multiplication: " << BitToDecimal(MultiplyTwoBit(bit1, bit2)) << " and its bit: " << MultiplyTwoBit(bit1, bit2) << "\n" << "\n";

    std::cout << "This is bit: " << bit1 << " and this is number: " << BitToDecimal(bit1) << "\n"
              << "This is bit: " << bit3 << " and this is number: " << BitToDecimal(bit3) << "\n"
              << "This is divine: " << DivineTwoBit(bit1, bit3);
    return 0;
}

std::string SumTwoBit(std::string firstBit, std::string lastBit)
{
    std::string totalBit {};

    int size = firstBit.size(); // or lastBit.size()

    int carry = 0;

    for (int i = size-1; i >= 0; i--)
    {
        int sumBit = (firstBit[i] - '0') + (lastBit[i] - '0') + carry;

        auto bitStr = std::to_string(sumBit % 2);

        totalBit.insert(0, bitStr);

        carry = (sumBit >= 2) ? 1 : 0;
    }

    return totalBit;
}

std::string TakeComplement(std::string bin)
{
    int size = bin.size();

    for (int i = 0; i < size; i++)
    {
        bin[i] = (bin[i] == '1') ? '0' : '1';
    }

    std::string bitOne {};

    for (int i=0; i < size; i++)
    {
        bitOne.append((i == size - 1) ? "1" : "0");
    }

    return SumTwoBit(bin, bitOne);
}

std::string SubtractTwoBit(std::string firstBit, std::string lastBit)
{
    if (lastBit[0] == '1') { return SumTwoBit(firstBit, lastBit); }
    else                   { return SumTwoBit(firstBit, TakeComplement(lastBit)); }
}

std::string ShiftRight(std::string bin)
{
    int size = bin.size();

    std::string bit = (BitToDecimal(bin) < 0) ? "1" : "0";

    return bin.substr(0, size-1).insert(0, bit);
}

std::string MultiplyTwoBit(std::string firstBit, std::string lastBit)
{
    int size = lastBit.size();

    std::string bitRes {};

    for (int i = 0; i < size; i++)
    {
        bitRes.append("0");
    }

    std::string bitNew = lastBit + "0";

    for (int i = size; i > 0; i--)
    {
        std::string lastTwoBit = bitNew.substr(size - 1);

        if (lastTwoBit == "10")      { bitRes = SubtractTwoBit(bitRes, firstBit); }
        else if (lastTwoBit == "01") { bitRes = SumTwoBit(bitRes, firstBit); }

        std::string shiftBit = ShiftRight(bitRes + bitNew);

        bitRes = shiftBit.substr(0, bitRes.size());
        bitNew = shiftBit.substr(bitRes.size());
    }

    return bitRes + bitNew.substr(0, lastBit.size());
}

std::string ShiftLeft(std::string bin)
{
    int size = bin.size();

    return bin.substr(1).append("0");
}

std::string DivineTwoBit(std::string firstBit, std::string lastBit)
{
    int size = firstBit.size();

    std::string bitRes {};

    for (int i = 0; i < size; i++)
    {
        bitRes.append("0");
    }

    for (int i = size; i > 0; i--)
    {
        std::string shiftBit = ShiftLeft(bitRes + firstBit);

        bitRes = shiftBit.substr(0, bitRes.size());

        firstBit = shiftBit.substr(bitRes.size());

        bitRes = SubtractTwoBit(bitRes, lastBit);

        if (BitToDecimal(bitRes) < 0) 
        { 
            firstBit[size - 1] = '0'; 
            bitRes = SumTwoBit(bitRes, lastBit);
        }
        else
        {
            firstBit[size - 1] = '1';
        }
    }

    return firstBit + bitRes;
}

int BitToDecimal(std::string bin)
{
    int dec = 0;
    int size = bin.size();

    for (int i = 0; i < size; ++i)
    {
        int bitNum = (bin[size - 1 - i] - '0') * pow(2, i);
        dec += (i == size - 1) 
                ? -bitNum 
                : bitNum;
    }

    return dec;
}