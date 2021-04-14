#ifndef HWSERIA_DATASTRUCT_H
#define HWSERIA_DATASTRUCT_H

#include "HWSeriable.h"
#include "SubSubD.h"
#include <string>
#include <iostream>

class DataStruct : HWSeriable {
private:
    int a = 452;
    float b = 83.356;
    double c = 827.512356788954;
    std::string d = "wojiaohanwei1234";
    SubSubD e;
public:
    void writeToBuf(HWSeriaDataBuf * pBuf);
    void createFromBuf(HWSeriaDataBuf * pBuf);

    friend std::ostream & operator << (std::ostream & os, DataStruct & data) {
        os << "DataSturct" << std::endl;
        os << "\ta = " << data.a << std::endl;
        os << "\tb = " << data.b << std::endl;
        os << "\tc = " << data.c << std::endl;
        os << "\td = " << data.d << std::endl;
        os << "\te = " << data.e << std::endl;
    }

public:
    void tClear() {
        a = 0;
        b = 0;
        c = 0;
        d = "";
        e.tClear();
    }
};


#endif //HWSERIA_DATASTRUCT_H
