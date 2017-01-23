#include "mcu.h"

Result mcuInit() {
    return srvGetServiceHandle(&mcuHandle, "mcu::HWC");
	}

Result mcuExit() {
    return svcCloseHandle(mcuHandle);
	}

Result GetMcuFwVerHigh(u8* out) {
    u32* ipc = getThreadCommandBuffer();
    ipc[0] = 0x100000;
    Result ret = svcSendSyncRequest(mcuHandle);
    if(ret < 0) return ret;
  	  *out = ipc[2];
    return ipc[1];
  }

Result GetMcuFwVerLow(u8* out) {
    u32* ipc = getThreadCommandBuffer();
    ipc[0] = 0x110000;
    Result ret = svcSendSyncRequest(mcuHandle);
    if(ret < 0) return ret;
    	*out = ipc[2];
    return ipc[1];
  }
