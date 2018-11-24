#include "radixconverter.h"

RadixConverter::RadixConverter() {}

int RadixConverter::toDecimal(int notation, QString num)
{
    int lenght = num.length();
    int resault = 0;
    int power = 0;

    if (notation > 9) {
        QChar alphabet[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

        int numeric[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

        for (int i = lenght - 1; i >= 0; i--) {
                  for(int j = 0; j < 22; j++) {
                      if(num[i] == alphabet[j]) {
                          if(numeric[j] >= notation) {
                              throw std::runtime_error("wrong input");
                          }
                          resault += numeric[j] * pow(notation,power);
                          power++;

                        }
                    }
                }
    } else {
        for (int i = lenght - 1; i >= 0; i--) {
            qDebug() << num[i].digitValue() << endl;
            if(num[i].digitValue() >= notation) {
                throw std::runtime_error("wrong input");
            }
            resault += (num[i].digitValue()) * pow(notation, power);
            power++;
        }
    }

    return resault;
}

QString RadixConverter::toBase(int sourceNotation, int destinationNotation, QString num)
{
    int numToDecimal;
    try {
    numToDecimal = this->toDecimal(sourceNotation,num);
    } catch(std::runtime_error) {
        return "wrong input";
    }
    int mod = 0;
    QString resault;

    while (numToDecimal != 0) {
        mod = numToDecimal % destinationNotation;
        if (mod >= 10) {
            resault.append(char(mod-10+'A'));
        } else {
            resault.append(char(mod+'0'));
        }
        numToDecimal /= destinationNotation;
    }

    QString reverseResault;
    for (int i = resault.length() -1; i >= 0; i--) {
        reverseResault.append(resault[i]);
    }

    return reverseResault;
}



















