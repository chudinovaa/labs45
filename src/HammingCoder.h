#ifndef LAB4_HAMMINGCODER_H
#define LAB4_HAMMINGCODER_H

#include "ICoder.h"

class HammingCoder : public ICoder
{
public:
  std::vector<uint8_t> encode(const std::vector<uint8_t> &data) override;
};


#endif //LAB4_HAMMINGCODER_H
