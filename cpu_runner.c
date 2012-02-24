/* cpu main program - this varies depending on your operating system and
 * how you're using cpu */
 
/* include only cpu.h here - should be able to use it with only the external interfaces, no internals from interpreter.h */
#include "cpu.h"

/* platform-dependent code for running programs is in this file */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CPU_STACK_SIZE (128*1024)              /* space for the the stack */

int main(int argc, char **argv) {
	int ParamCount = 1;
	int DontRunMain = FALSE;
	int StackSize = getenv("STACKSIZE") ? atoi(getenv("STACKSIZE")) : CPU_STACK_SIZE;

	if (argc < 2) {
		printf("Format: cpu <csource1.c>... [- <arg1>...]    : run a program (calls main() to start it)\n"
				"        cpu -s <csource1.c>... [- <arg1>...] : script mode - runs the program without calling main()\n"
				"        cpu -i                               : interactive mode\n");
		exit(1);
	}

	CPUInitialise(StackSize);

	if (strcmp(argv[ParamCount], "-s") == 0 || strcmp(argv[ParamCount], "-m") == 0) {
		DontRunMain = TRUE;
		CPUIncludeAllSystemHeaders();
		ParamCount++;
	}

	if (argc > ParamCount && strcmp(argv[ParamCount], "-i") == 0) {
		CPUIncludeAllSystemHeaders();
		CPUParseInteractive(TRUE);
	} else {
		if (CPUPlatformSetExitPoint()) {
			CPUCleanup();
			return CPUExitValue;
		}

		for (; ParamCount < argc && strcmp(argv[ParamCount], "-") != 0; ParamCount++)
			CPUPlatformScanFile(argv[ParamCount]);

		if (!DontRunMain)
			CPUCallMain(argc - ParamCount, &argv[ParamCount]);
	}

	CPUCleanup();
	return CPUExitValue;
}
