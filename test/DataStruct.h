#ifndef HWSERIA_DATASTRUCT_H
#define HWSERIA_DATASTRUCT_H

#include "HWSeriable.h"

class DataStruct : HWSeriable {
protected:
    void writeToBuf(int a);
};


#endif //HWSERIA_DATASTRUCT_H
