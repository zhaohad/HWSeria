#include <iostream>
#include "HWSeria.h"
#include "DataStruct.h"

#include <list>

int main() {
    HWSeria hwSeria;
    hwSeria.hello();
    DataStruct data;

    /*std::list<std::string> l;
    l.push_back("1");
    l.push_back("2");
    l.push_back("3");
    for (int size = l.size(); size > 0; --size) {
        std::cout << l.front() << std::endl;
        l.pop_front();
    }*/
    std::cout << sizeof(int) << std::endl;
    char * a = new char [3];
    std::cout << sizeof(char) << std::endl;
    delete [] a;
    return 0;
}
