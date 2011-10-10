#include <stdlib.h>
#include <string.h>

#include "abuse.h"

static void *data;

static int xmp_read(void *buf, u_int32_t len, u_int64_t offset)
{
    /* memcpy(buf, (char *)data + offset, len); */
    memset(buf, 0, len);

    return 0;
}

static int xmp_write(const void *buf, u_int32_t len, u_int64_t offset)
{
    memcpy((char *)data + offset, buf, len);
    return 0;
}

static struct abuse_operations aop = {
    .read = xmp_read,
    .write = xmp_write,
    .size = 128 * 1024 * 1024,
};

int main(int argc, char *argv[])
{
    data = malloc(aop.size);

    return abuse_main(argc, argv, &aop, NULL);
}