#include "DataStruct.h"

void DataStruct::writeToBuf(HWSeriaDataBuf *pBuf) {
    pBuf->writeInt(a);
    pBuf->writeFloat(b);
    pBuf->writeDouble(c);
    pBuf->writeString(d);
    e.writeToBuf(pBuf);
}

void DataStruct::createFromBuf(HWSeriaDataBuf *pBuf) {
    pBuf->readInt(a);
    pBuf->readFloat(b);
    pBuf->readDouble(c);
    pBuf->readString(d);
    e.createFromBuf(pBuf);
}