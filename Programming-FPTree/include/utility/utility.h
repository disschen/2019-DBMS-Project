#include <stdlib.h>
#include <string>

#ifndef UTILITY_VALUE

#define UTILITY_VALUE
#define MAX_DEGREE 256
#define MIN_DEGREE 2
#define LEAF_DEGREE 56
#define INNER_DEGREE 4096

#define MAX_KEY UINT64_MAX;
#define MAX_VALUE UINT64_MAX;

#define LEAF_GROUP_AMOUNT 16
#define ILLEGAL_FILE_ID   0

#endif

using std::string;

typedef unsigned char Byte;

typedef uint64_t  Key;    // key(8 byte)
typedef uint64_t  Value;  // value(8 byte)

//leaves file and pallocator data storing place
const string DATA_DIR =  "/home/zhangjoe/Desktop/pmem/";

// leaf header length, the bitmap is simply one byte for a leaf
const uint64_t LEAF_GROUP_HEAD = sizeof(uint64_t) + LEAF_GROUP_AMOUNT;

typedef struct t_PPointer
{
    /* data */
    uint64_t fileId;
    uint64_t offset;

    bool operator==(const t_PPointer p) const;
} PPointer;

uint64_t calLeafSize();

uint64_t countOneBits(Byte b);

Byte keyHash(Key k);

PPointer getPNext(PPointer p);