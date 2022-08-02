#include "safire/tools/utils.hpp"

#define IMAX_BITS(M) ((M) / ((M) % 255 + 1) / 255 % 255 * 8 + 7 - 86/ ((M) % 255 + 12))
#define RAND_MAX_WIDTH IMAX_BITS(RAND_MAX)

namespace safire
{


    UUID genertate_UUID()
    {
        return generate_rand_uint64();
    }

    // I have no idea what this is doing so here is where I got this from:
    // https://stackoverflow.com/questions/33010010/how-to-generate-random-64-bit-unsigned-integer-in-c
    uint64_t generate_rand_uint64()
    {
        uint64_t random = 0;
        for (int i = 0; i < 64; i += RAND_MAX_WIDTH)
        {
            random <<= RAND_MAX_WIDTH;
            random ^= (unsigned) rand();
        }

        return random;
    }

}
