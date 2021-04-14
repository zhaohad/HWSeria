//
// Created by zhaohad on 2021/4/14.
//

#include "SubD.h"

void SubD::writeToBuf(HWSeriaDataBuf *pBuf) {
    pBuf->writeBytes(subDb, sizeof(subDb));
    pBuf->writeByte(subDa);
}

void SubD::createFromBuf(HWSeriaDataBuf *pBuf) {
    pBuf->readBytes(subDb, sizeof(subDb));
    pBuf->readByte(reinterpret_cast<unsigned char &>(subDa));
}
