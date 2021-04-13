#include "DataBuf.h"
#include <cstring>

_DataBuf_B::_DataBuf_B(void * v, int size) {
    buff = new char [size];
    std::memcpy(buff, v, size);
}

_DataBuf_B::~_DataBuf_B() {
    if (buff) {
        delete [] buff;
    }
}

DataBuf::~DataBuf() {
    for (int s = mBuffers.size(); s > 0; --s) {
        _DataBuf_B * b = mBuffers.front();
        delete b;
        mBuffers.pop_front();;
    }
}

void DataBuf::writeInt(int v) {
    mBuffers.push_back(new _DataBuf_B(&v, sizeof(int)));
}

void DataBuf::writeByte(unsigned char v) {
    mBuffers.push_back(new _DataBuf_B(&v, sizeof(unsigned char)));
}

void DataBuf::writeFloat(float v) {
    mBuffers.push_back(new _DataBuf_B(&v, sizeof(float)));
}

void DataBuf::writeDouble(double v) {
    mBuffers.push_back(new _DataBuf_B(&v, sizeof(double)));
}

void DataBuf::writeBytes(const char *v, int size) {
    mBuffers.push_back(new _DataBuf_B(v, size));
}

void DataBuf::writeString(std::string v) {
    writeBytes(v.c_str(), v.length());
}