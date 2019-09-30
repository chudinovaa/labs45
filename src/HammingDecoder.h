#ifndef LAB4_HAMMINGDECODER_H
#define LAB4_HAMMINGDECODER_H

#include "IDecoder.h"

class HammingDecoder : public IDecoder
{
public:
  std::vector <uint8_t> decode(const std::vector <uint8_t> &data) override;
};


#endif //LAB4_HAMMINGDECODER_H
