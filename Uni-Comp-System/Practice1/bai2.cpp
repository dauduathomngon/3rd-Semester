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
    std::string bit1 {"01000101"};
    std::string bit2 {"10010111"};
    std::string bit3 {"00110010"};

    std::string sumBit = SumTwoBit(bit1, bit2);

    std::string subBit = SubtractTwoBit(bit3, bit1);

    std::string mulBit = MultiplyTwoBit(bit1, bit2);

    std::string divBit = DivineTwoBit(bit1, bit3);

    std::string quotientBit = divBit.substr(0, bit1.size());

    std::string remainderBit = divBit.substr(bit1.size());

    std::cout << "Day la bit: " << bit1 << " va day la so nguyen: " << BitToDecimal(bit1) << "\n"
              << "Day la bit: " << bit2 << " va day la so nguyen: " << BitToDecimal(bit2) << "\n"
              << "Day la bit phep cong: " << sumBit << " va day la so nguyen: " << BitToDecimal(sumBit) << "\n";

    std::cout << "\n";

    std::cout << "Day la bit: " << bit3 << " va day la so nguyen: " << BitToDecimal(bit3) << "\n"
              << "Day la bit: " << bit1 << " va day la so nguyen: " << BitToDecimal(bit1) << "\n"
              << "Day la bit phep tru: " << subBit << " va day la so nguyen: " << BitToDecimal(subBit) << "\n";

    std::cout << "\n";

    std::cout << "Day la bit: " << bit1 << " va day la so nguyen: " << BitToDecimal(bit1) << "\n"
              << "Day la bit: " << bit2 << " va day la so nguyen: " << BitToDecimal(bit2) << "\n"
              << "Day la bit phep nhan: " << mulBit << " va day la so nguyen: " << BitToDecimal(mulBit) << "\n";

    std::cout << "\n";

    std::cout << "Day la bit: " << bit1 << " va day la so nguyen: " << BitToDecimal(bit1) << "\n"
              << "Day la bit: " << bit3 << " va day la so nguyen: " << BitToDecimal(bit3) << "\n"
              << "Day la bit phep chia: " << divBit << "\n"
              << "Va day la ket qua thuong: " << quotientBit  << " voi gia tri nguyen: " << BitToDecimal(quotientBit) << "\n"
              << "Va day la phan du: " << remainderBit << " voi gia tri nguyen: " << BitToDecimal(remainderBit) << "\n";

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