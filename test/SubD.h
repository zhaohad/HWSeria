#ifndef HWSERIA_SUBD_H
#define HWSERIA_SUBD_H

#include <HWSeriable.h>
#include <iostream>
#include <cstring>

class SubD : HWSeriable {
private:
    char subDa = 'a';
    char subDb[10] = "123456789";
public:
    void writeToBuf(HWSeriaDataBuf *pBuf) override;
    void createFromBuf(HWSeriaDataBuf *pBuf) override;

    friend std::ostream & operator << (std::ostream & os, SubD & data) {
        os << "SubD" << std::endl;
        os << "\tsubDa = " << data.subDa << std::endl;
        os << "\tsubDb = " << data.subDb << std::endl;
    }

public:
    void tClear() {
        subDa = 0;
        std::memset(subDb, 0, sizeof(subDb));
    }
};


#endif //HWSERIA_SUBD_H
