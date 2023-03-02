#include <iostream>
#include <string>
#include <math.h>

std::string ConvertDecimalToBinary(unsigned int dec);

char HexNumber(unsigned int remainder);
std::string ConvertDecimalToHex(unsigned int dec);

unsigned int HexChar(char hex_char);
unsigned int ConvertBinaryToDecimal(std::string bin);

unsigned int ConvertHexToDecimal(std::string hex);

std::string ConvertBinaryToHex(std::string bin);

int main()
{
    bool is_running = true;
    int choice = 0;

    unsigned int dec = 0;
    std::string bin;
    std::string hex;

    while (is_running)
    {
        std::cout << "**********************************\n";
        std::cout << "Cac bai tap: \n";
        std::cout << "Bai 1: Chuyen tu he 10 sang he 2 \n";
        std::cout << "Bai 2: Chuyen tu he 10 sang he 16 \n";
        std::cout << "Bai 3: Chuyen tu he 2 sang he 10 \n";
        std::cout << "Bai 4: Chuyen tu he 16 sang he 10 \n";
        std::cout << "Bai 5: Chuyen tu he 2 sang he 16 \n";
        std::cout << "Moi nhap so tuong ung de chon bai tap (nhap so 0 de thoat): ";
        std::cin >> choice;
        std::cout << "**********************************\n";

        switch(choice)
        {
            case(1):
                std::cout << "Moi nhap so nguyen de chuyen sang he 2: ";
                std::cin >> dec;
                std::cout << "So da chuyen doi: " << ConvertDecimalToBinary(dec) << "\n";
                break;

            case(2):
                std::cout << "Moi nhap so nguyen de chuyen sang he 16: ";
                std::cin >> dec;
                std::cout << "So da chuyen doi: " << ConvertDecimalToHex(dec) << "\n";
                break;

            case(3):
                std::cout << "Moi nhap so he 2 de chuyen sang he 10: ";
                std::cin >> bin;
                std::cout << "So da chuyen doi: " << ConvertBinaryToDecimal(bin) << "\n";
                break;

            case(4):
                std::cout << "Moi nhap so he 16 de chuyen sang he 10: ";
                std::cin >> hex;
                std::cout << "So da chuyen doi: " << ConvertHexToDecimal(hex) << "\n";
                break;

            case(5):
                std::cout << "Moi nhap so he 2 de chuyen sang he 16: ";
                std::cin >> bin;
                std::cout << "So da chuyen doi: " << ConvertBinaryToHex(bin) << "\n";
                break;

            default:
                is_running = false;
                break;
        }
    }

    return 0;
}

std::string ConvertDecimalToBinary(unsigned int dec)
{
    std::string bin;
    while (dec != 0)
    {
        bin = (dec % 2 == 0 ? "0" : "1") + bin;
        dec /= 2;
    }
    return bin;
}

char HexNumber(unsigned int remainder)
{
    std::string h_number;

    if (remainder >= 10) { return char(remainder + 55); }
    else                 { return remainder + '0'; } // use for change 0-9 to char without ascii
}

std::string ConvertDecimalToHex(unsigned int dec)
{
    std::string hex;
    while (dec != 0)
    {
        hex += HexNumber(dec % 16);
        dec /= 16;
    }
    return hex;
}

unsigned int ConvertBinaryToDecimal(std::string bin)
{
    unsigned int dec = 0;

    size_t size = bin.size();
    for (int i=0; i < size; i++)
    {
        dec += (bin[size - 1 - i] - '0') * pow(2, i);
    }

    return dec;
}

unsigned int HexChar(char hex_char)
{
    if ((int)hex_char >= 65) { return (int)hex_char - 55; }
    else                     { return hex_char - '0'; }
}

unsigned int ConvertHexToDecimal(std::string hex)
{
    unsigned int dec = 0;

    size_t size = hex.size();
    for (int i=0; i < size; i++)
    {
        dec += HexChar(hex[size - 1 - i]) * pow(16, i);
    }

    return dec;
}

std::string ConvertBinaryToHex(std::string bin)
{
    return ConvertDecimalToHex(ConvertBinaryToDecimal(bin));
}