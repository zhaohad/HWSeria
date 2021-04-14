#include "SubSubD.h"

void SubSubD::writeToBuf(HWSeriaDataBuf *pBuf) {
    pBuf->writeByte(subSubDa);
    pBuf->writeBytes(subSubDb, sizeof(subSubDb));
    pBuf->writeInt(subSubDc);
    pBuf->writeInt(subSubDd);
    pBuf->writeFloat(subSubDe);
    pBuf->writeDouble(subSubDf);
    pBuf->writeString(subSubDg);
}

void SubSubD::createFromBuf(HWSeriaDataBuf *pBuf) {
    pBuf->readByte(reinterpret_cast<unsigned char &>(subSubDa));
    pBuf->readBytes(subSubDb, sizeof(subSubDb));
    pBuf->readInt(subSubDc);
    pBuf->readInt(reinterpret_cast<int &>(subSubDd));
    pBuf->readFloat(subSubDe);
    pBuf->readDouble(subSubDf);
    pBuf->readString(subSubDg);
}