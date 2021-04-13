#ifndef HWSERIA_HWSERIABLE_H
#define HWSERIA_HWSERIABLE_H


class HWSeriable {
public:
    void writeToBuf();

protected:
    virtual void writeToBuf(int a) = 0;

};


#endif //HWSERIA_HWSERIABLE_H
