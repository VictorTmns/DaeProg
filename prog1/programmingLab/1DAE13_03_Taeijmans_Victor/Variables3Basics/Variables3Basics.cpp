// Taeijmans, Victor - DAEE13
//

#include "pch.h"
#include <iostream>
#include <bitset>

void testingSizeOfFunction();
void assigningWithDifferentNumeralSystems();
void testingWithSignedAndUnsignedTypes();
void decimalOrOperator();
void checkIntInDecimal();
void setBit();
void binaryLeftShift();
void generalBitwiseOperator();

int main()
{
    testingSizeOfFunction();
    assigningWithDifferentNumeralSystems();
    testingWithSignedAndUnsignedTypes();
    decimalOrOperator();
    checkIntInDecimal();
    setBit();
    binaryRightShift();
    binaryLeftShift();
    generalBitwiseOperator();

}

void testingSizeOfFunction() {
    const bool bValue{};
    const int iValue{};
    const double dValue{};
    const float fValue{};

    std::cout << "size of a bool: " << sizeof(bValue) << "\nsize of an int: " << sizeof(iValue) << "\nsize of a double: " << sizeof(dValue) << "\nsize of a float: " << sizeof(fValue) << "\n";
}

void assigningWithDifferentNumeralSystems() {
    const int decimalInt{12};
    const int hexadecimalInt{ 0xc };
    const int binaryInt{0b1100};

    std::cout << decimalInt << "\n" << hexadecimalInt << "\n" << binaryInt;

}

void testingWithSignedAndUnsignedTypes() {
    int signedMaxInt{ INT32_MAX };
    int signedMinInt{ INT32_MIN };

    unsigned int unsignedMaxInt{ UINT32_MAX };
    unsigned int unsignedMinInt{ 0 };

    signedMaxInt++, unsignedMaxInt++, signedMinInt--, unsignedMinInt--;



    std::cout << "signed max: " << signedMaxInt << "\n";
    std::cout << "signed min: " << signedMinInt << "\n";
    std::cout << "unsigned max: " << unsignedMaxInt << "\n";
    std::cout << "unsigned min: " << unsignedMinInt << "\n";
}

void decimalOrOperator() {
    unsigned int iValue1{ 3 };
    unsigned int iValue2{ 5 };

    std::cout << iValue1 << " | " << iValue2 << " : " << (iValue1 | iValue2);
}

void checkIntInDecimal() {
    int iInput{};
    unsigned int bit1{ 0b0001 };
    unsigned int bit2{ 0b0010 };
    unsigned int bit3{ 0b0100 };
    unsigned int bit4{ 0b1000 };

    std::cout << ("\nNumber to check which bits are set? ");
    std::cin >> iInput;

    std::cout << ("1st bit: ") << (iInput & bit1) << "\n";
    std::cout << ("2st bit: ") << (iInput & bit2) << "\n";
    std::cout << ("3st bit: ") << (iInput & bit3) << "\n";
    std::cout << ("4st bit: ") << (iInput & bit4) << "\n";
}

void setBit() {
    int iInput{};
    const unsigned int thirdBitBool{ 0b0100 };

    std::cout << ("Number to set 3rd bit in? ");
    std::cin >> iInput;
    std::cout << ("This number with its 3 bit set: ") << (iInput | thirdBitBool);
}

void binaryRightShift() {
    unsigned int iValue{ 2048 };

    std::cout << ("right shift 1") << (iValue >> 1) << std::endl;

    unsigned int iValue2{ 256 };
    iValue2 >>= 8;
    std::cout << iValue2 << std::endl;

    std::cout << std::bitset<1>(iValue2);
}

void binaryLeftShift() {
    unsigned int iValue{ 2048 };

    std::cout << ("left shift 1") << (iValue << 1) << std::endl;
}

void generalBitwiseOperator() {
    int iValue{};
    iValue = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 7) | (1 << 8) | (1 << 9) | (1 << 11) | (1 << 13) | (1 << 14) | (1 << 16) | (1 << 17) | (1 << 19)| (1 << 21);
    std::cout << iValue;
}