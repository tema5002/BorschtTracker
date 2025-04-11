#pragma once
#include "includes.h"

typedef uint32_t packed_string_t;

#define BT_PACK_STRING4(s) ( \
    (packed_string_t)( ( (unsigned char)(s[3]) ) << 24 ) + \
    (packed_string_t)( ( (unsigned char)(s[2]) ) << 16 ) + \
    (packed_string_t)( ( (unsigned char)(s[1]) ) << 8  ) + \
    (packed_string_t)( ( (unsigned char)(s[0]) )       )   \
)

#define BT_PACK_STRING3(s) ( \
    (packed_string_t)( ( (unsigned char)(s[2]) ) << 16 ) + \
    (packed_string_t)( ( (unsigned char)(s[1]) ) << 8  ) + \
    (packed_string_t)( ( (unsigned char)(s[0]) )       )   \
)

#define BT_PACK_STRING2(s) ( \
    (packed_string_t)( ( (unsigned char)(s[1]) ) << 8  ) + \
    (packed_string_t)( ( (unsigned char)(s[0]) )       )   \
)

#define BT_PACK_STRING1(s) ( \
    (packed_string_t)( ( (unsigned char)(s[0]) )       )   \
)

#define BT_PACK_STRING_CHAR(c) ( \
    (packed_string_t)( ( (unsigned char)(c) )       )   \
)
