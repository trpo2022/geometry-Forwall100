#include <stdio.h>
#define CTEST_MAIN
#define CTEST_COLOR_OK
#include "../thirdparty/ctest.h"

int main(int argc, const char* argv[])
{
    int result = ctest_main(argc, argv);
    return result;
}
