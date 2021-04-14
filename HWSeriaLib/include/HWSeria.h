#ifndef HWSERIA_HWSERIA_H
#define HWSERIA_HWSERIA_H

#include "HWSeriable.h"
#include "HWSeriaDataBuf.h"

class HWSeria {
public:
    void serialize(HWSeriaDataBuf * pBuf, HWSeriable * data);
    HWSeriable * deserialize();
};


#endif //HWSERIA_HWSERIA_H
