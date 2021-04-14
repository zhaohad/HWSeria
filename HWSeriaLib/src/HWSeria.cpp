
#include <iostream>
#include "HWSeria.h"

void HWSeria::serialize(HWSeriaDataBuf * pBuf, HWSeriable *data) {
    data->writeToBuf(pBuf);
}
