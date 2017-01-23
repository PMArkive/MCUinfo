#include <3ds.h>

Handle mcuHandle;

Result mcuInit();
Result mcuExit();
Result GetMcuFwVerHigh(u8* out);
Result GetMcuFwVerLow(u8* out);
