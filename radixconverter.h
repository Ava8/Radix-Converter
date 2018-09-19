#ifndef RADIXCONVERTER_H
#define RADIXCONVERTER_H

#include <QWidget>
#include <cmath>

class RadixConverter
{
public:
    RadixConverter();
    int toDecimal(int notation, QString num);
    QString toBase(int sourceNotation, int destinationNotation, QString num);

};

#endif // RADIXCONVERTER_H
