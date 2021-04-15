#include "HWSeriaDataBuf.h"
#include <cstring>
#include <vector>

_DataBuf_B::_DataBuf_B(const void * v, int size) {
    this->size = size;
    buff = new char [size];
    std::memcpy(buff, v, size);
}

_DataBuf_B::~_DataBuf_B() {
    if (buff) {
        delete [] buff;
    }
}

HWSeriaDataBuf::HWSeriaDataBuf() {
}

HWSeriaDataBuf::HWSeriaDataBuf(const char *data, int size) {
    _Buffer_Bytes = new char[size];
    std::memcpy((void *) _Buffer_Bytes, data, size);
}

HWSeriaDataBuf::~HWSeriaDataBuf() {
    for (int s = mBuffers.size(); s > 0; --s) {
        _DataBuf_B * b = mBuffers.front();
        delete b;
        mBuffers.pop_front();
    }
    if (_Buffer_Bytes) {
        delete [] _Buffer_Bytes;
        _Buffer_Bytes = nullptr;
    }
}

void HWSeriaDataBuf::writeInt(int v) {
    writeToBuf(&v, sizeof(int));
}

void HWSeriaDataBuf::writeByte(unsigned char v) {
    writeToBuf(&v, sizeof(unsigned char));
}

void HWSeriaDataBuf::writeFloat(float v) {
    writeToBuf(&v, sizeof(float));
}

void HWSeriaDataBuf::writeDouble(double v) {
    writeToBuf(&v, sizeof(double));
}

void HWSeriaDataBuf::writeBytes(const char *v, int size) {
    writeToBuf(v, size);
}

void HWSeriaDataBuf::writeString(const std::string & v) {
    writeInt(v.length() + 1);
    writeBytes(v.c_str(), v.length() + 1);
}

void HWSeriaDataBuf::writeToBuf(const void * v, int size) {
    mBufferSize += size;
    mBuffers.push_back(new _DataBuf_B(v, size));
}

void HWSeriaDataBuf::readBuf(int size, void *v) {
    std::memcpy(v, _Buffer_Bytes + mCurrentPos, size);
    mCurrentPos += size;
}

void HWSeriaDataBuf::readInt(int &v) {
    readBuf(sizeof(int), &v);
}

void HWSeriaDataBuf::readFloat(float &v) {
    readBuf(sizeof(float), &v);
}

void HWSeriaDataBuf::readDouble(double &v) {
    readBuf(sizeof(double), &v);
}

void HWSeriaDataBuf::readByte(unsigned char &v) {
    readBuf(sizeof(unsigned char), &v);
}

void HWSeriaDataBuf::readBytes(char *v, int size) {
    readBuf(size, v);
}

void HWSeriaDataBuf::readString(std::string &v) {
    int len;
    readInt(len);
    char str[len];
    readBytes(str, len);
    v.assign(str);
}

const void HWSeriaDataBuf::toBytes(char * buf) {
    int start = 0;
    for (std::list<_DataBuf_B *>::iterator itor = mBuffers.begin(); itor != mBuffers.end(); ++itor) {
        int s = (*itor)->size;
        std::memcpy((void *) (buf + start), (*itor)->buff, s);
        start += s;
    }
}

unsigned int HWSeriaDataBuf::getBufferSize() {
    return mBufferSize;
}