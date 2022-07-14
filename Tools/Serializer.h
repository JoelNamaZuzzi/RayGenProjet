#pragma once
#ifndef RAYGEN_SERIALIZER_H
#define RAYGEN_SERIALIZER_H

namespace Serializer {
    static float serialize(float v, float min, float max) {
        return (v - min) / (max - min);
    }

    static int deserialize(float v, float min, float max) {
        return int(v * (max - min) + min);
    }
};

#endif //RAYGEN_SERIALIZER_H
