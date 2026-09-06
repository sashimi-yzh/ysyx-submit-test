#include <stdint.h>
#include <string>

typedef struct {
    const char *name;
    uint32_t start;
    uint32_t end;
    uint8_t *space;
} socspace; 