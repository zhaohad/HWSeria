#ifndef HWSERIA_HWSERIADATABUF_H
#define HWSERIA_HWSERIADATABUF_H

#include <list>
#include <string>

class _DataBuf_B {
    friend class HWSeriaDataBuf;
public:
    _DataBuf_B(const void * v, int size);
public:
    int size;
    char * buff;

private:
    ~_DataBuf_B();
};

class HWSeriaDataBuf {
private:
    unsigned int mBufferSize = 0;
    std::list<_DataBuf_B *> mBuffers;
    const char * _Buffer_Bytes = nullptr;

    int mCurrentPos = 0;

public:
    HWSeriaDataBuf();
    HWSeriaDataBuf(const char * data, int size);
    ~HWSeriaDataBuf();
    void writeInt(const int v);
    void writeFloat(const float v);
    void writeDouble(const double v);
    void writeByte(const unsigned char v);
    void writeBytes(const char * v, int size);
    void writeString(const std::string & v);
    void readInt(int & v);
    void readFloat(float & v);
    void readDouble(double & v);
    void readByte(unsigned char & v);
    void readBytes(char * v, int size);
    void readString(std::string & v);
    const void toBytes(char * buf);
    unsigned int getBufferSize();

private:
    void writeToBuf(const void * v, int size);
    void readBuf(int size, void * v);
};


#endif //HWSERIA_HWSERIADATABUF_H
