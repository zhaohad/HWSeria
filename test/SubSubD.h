#ifndef HWSERIA_SUBSUBD_H
#define HWSERIA_SUBSUBD_H

#include "HWSeriable.h"
#include <string>
#include <cstring>
#include <iostream>

class SubSubD : HWSeriable {
private:
    char subSubDa = 'a';
    char subSubDb[10] = "123456789";
    int subSubDc = -921;
    unsigned int subSubDd = 214;
    float subSubDe = 123.3f;
    double subSubDf = 123.567890123456;
    std::string subSubDg = "abcdefg";
public:
    void writeToBuf(HWSeriaDataBuf *pBuf) override;
    void createFromBuf(HWSeriaDataBuf *pBuf) override;

    friend std::ostream & operator << (std::ostream & os, SubSubD & data) {
        os << "SubSubD" << std::endl;
        os << "\tsubSubDa = " << data.subSubDa << std::endl;
        os << "\tsubSubDb = " << data.subSubDb << std::endl;
        os << "\tsubSubDc = " << data.subSubDc << std::endl;
        os << "\tsubSubDd = " << data.subSubDd << std::endl;
        os << "\tsubSubDe = " << data.subSubDe << std::endl;
        os << "\tsubSubDf = " << data.subSubDf << std::endl;
        os << "\tsubSubDg = " << data.subSubDg << std::endl;
    }

public:
    void tClear() {
        subSubDa = 0;
        memset(subSubDb, 0, sizeof(subSubDb));
        subSubDc = 0;
        subSubDd = 0;
        subSubDe = 0;
        subSubDf = 0;
        subSubDg = "";
    }
};


#endif //HWSERIA_SUBSUBD_H
