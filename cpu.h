/* cpu external interface. This should be the only header you need to use if
 * you're using cpu as a library. Internal details are in interpreter.h */
#ifndef CPU_H
#define CPU_H

	#define CPU_VERSION "v1.0a"

	/* handy definitions */
	#ifndef TRUE
		#define TRUE 1
		#define FALSE 0
	#endif


	#include <setjmp.h>

	/* mark where to end the program for platforms which require this */
	extern jmp_buf CPUExitBuf;

	/* this has to be a macro, otherwise errors will occur due to the stack being corrupt */
	#define CPUPlatformSetExitPoint() setjmp(CPUExitBuf)

	/* parse.c */
	void CPUParse(const char *FileName, const char *Source, int SourceLen, int RunIt, int CleanupNow, int CleanupSource, int EnableDebugger);
	void CPUParseInteractive();

	/* platform.c */
	void CPUCallMain(int argc, char **argv);
	void CPUInitialise(int StackSize);
	void CPUCleanup();
	void CPUPlatformScanFile(const char *FileName);

	extern int CPUExitValue;

	/* include.c */
	void CPUIncludeAllSystemHeaders();

#endif /* CPU_H */
