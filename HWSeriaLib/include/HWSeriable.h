#ifndef HWSERIA_HWSERIABLE_H
#define HWSERIA_HWSERIABLE_H

#include "HWSeriaDataBuf.h"
#include <string>

class HWSeriable {
public:
    virtual void writeToBuf(HWSeriaDataBuf * pBuf) = 0;
    virtual void createFromBuf(HWSeriaDataBuf * pBuf) = 0;
};


#endif //HWSERIA_HWSERIABLE_H
