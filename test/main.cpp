#include <iostream>
#include "HWSeria.h"
#include "SubD.h"
#include "SubSubD.h"
#include "DataStruct.h"
#include "HWSeriaDataBuf.h"
#include <fstream>

#include <list>

int main() {
    DataStruct dataStruct;
    /*SubD subD;
    SubSubD subSubD;*/

    HWSeriaDataBuf data;

    dataStruct.writeToBuf(&data);
    /*subD.writeToBuf(&data);
    subSubD.writeToBuf(&data);*/

    std::ofstream os("test.txt", std::ios::out | std::ios::binary);
    const char * bytes = data.toBytes();
    os.write(bytes, data.getBufferSize());
    os.close();

    std::ifstream is("test.txt", std::ios::in | std::ios::binary | std::ios::ate);
    int size = is.tellg();
    is.seekg(0, std::ios::beg);
    char * readBytes = new char[size];
    is.read(readBytes, size);
    is.close();

    DataStruct aDataStruct;
    aDataStruct.tClear();
    HWSeriaDataBuf aBuf(readBytes, size);
    aDataStruct.createFromBuf(&aBuf);

    std::cout << aDataStruct << std::endl;

    /*SubD aSubD;
    aSubD.tClear();
    aSubD.createFromBuf(&aBuf);
    std::cout << aSubD << std::endl;

    SubSubD aSubSubD;
    aSubSubD.tClear();
    aSubSubD.createFromBuf(&aBuf);
    std::cout << aSubSubD << std::endl;*/

    delete [] readBytes;
    return 0;
}
