#include <iostream>
#include <vector>

/* 
    rotor.cpp - 2021-09-23
    Rotor lodzsik emulátor
    Kópirájt kodolas3 (lol)

*/

// Rotor osztály, belső counter, automatikusan incrementál
class rotor
{
private:
    int position;
    std::vector<int> table;

public:
    rotor(std::vector<int> table, int position);
    ~rotor();
    int encode(int charNum);
    int decode(int charNum);
    void writePosition();
    bool addPos();
};

rotor::rotor(std::vector<int> table, int position)
{
    this->position = position;
    this->table = table;
}

// Encoder
// Forgatja a "rotor"-t, pozitív irányba
int rotor::encode(int charNum)
{
    int realNum = this->table[charNum] + this->position;

    // Debug output
    //std::cout << "Pos - table: " << this->table[this->position] << ", Num: " << this->table[charNum] << ", Res:" << realNum << std::endl;

    if (realNum > 26)
    {
        realNum -= 26;
    }
    this->position++;

    if (this->position > 26)
    {
        this->position -= 26;
    }
    return realNum;
}

// Decoder
// Forgatja a "rotor"-t negatív irányba
int rotor::decode(int charNum)
{
    int realNum = charNum - this->position;

    if (realNum < 1)
    {
        realNum += 26;
    }

    this->position++;

    if (this->position > 26)
    {
        this->position -= 26;
    }
    return this->table[realNum];
}

// Rotor destruktor
rotor::~rotor()
{
    // Az égvilágon semmi
}

// Pozíció bele a konzolba be
void rotor::writePosition()
{
    std::cout << "Rotor pozíció: " << this->position << std::endl;
}

bool rotor::addPos()
{
    this->position++;

    if (this->position > 26)
    {
        this->position -= 26;
        return 1;
    }
    else if (this->position == 14)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}