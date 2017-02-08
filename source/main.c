#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>

#include "mcu.h"

u8 mcuFWHigh;
u8 mcuFWLow;

int main(int argc, char **argv) {
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);
	printf("MCU info\nby Hikari\n\n");
	printf("Press B to exit.\n");
	printf("Initializing the MCU...\n");
	mcuInit();
	GetMcuFwVerHigh(&mcuFWHigh);
	GetMcuFwVerLow(&mcuFWLow);
	printf("MCU firmware version: %u.%u\n", mcuFWHigh, mcuFWLow);
	while (aptMainLoop()) {
		gspWaitForVBlank();
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_B) {
		printf("Exiting...\n");
		break;
	}
}

	mcuExit();
	gfxFlushBuffers();
	gfxSwapBuffers();
	gspWaitForVBlank();
	gfxExit();
	return 0;
}
