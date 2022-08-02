#ifndef SAFIRE_UTILS_HPP
#define SAFIRE_UTILS_HPP

#include <stdio.h>
#include <stdint.h>

#include "safire/tools/dynamic_array.hpp"
#include "safire/tools/memory.hpp"
#include "safire/tools/string.hpp"

#include <glm/glm.hpp>


namespace safire
{

    typedef uint64_t UUID;
    typedef glm::vec4 Colour;

    UUID genertate_UUID();

    uint64_t generate_rand_uint64();

}

#endif // SAFIRE_UTILS_HPP
