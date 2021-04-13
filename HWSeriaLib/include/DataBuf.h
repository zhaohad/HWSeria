#ifndef HWSERIA_DATABUF_H
#define HWSERIA_DATABUF_H

#include <list>
#include <string>

class _DataBuf_B {
    friend class DataBuf;
public:
    _DataBuf_B(const void * v, int size);
private:
    int size;
    char * buff;

private:
    ~_DataBuf_B();
};

class DataBuf {
private:
    std::list<_DataBuf_B *> mBuffers;

public:
    ~DataBuf();
    void writeInt(const int v);
    void writeFloat(const float v);
    void writeDouble(const double v);
    void writeByte(const unsigned char v);
    void writeBytes(const char * v, int size);
    void writeString(const std::string v);

private:
    _DataBuf_B * generateBuf(void * v, int size);
};


#endif //HWSERIA_DATABUF_H
