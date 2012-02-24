/* cpu main interfaces */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "cpu_engine.h"
#include "cpu.h"

#define CPU_STACK_SIZE (128*1024)              /* space for the the stack */

void cpu_engine_create(){

	if (CPUPlatformSetExitPoint()) {
		CPUCleanup();
		exit(CPUExitValue);
	}
}

void cpu_engine_load_pcb(t_pcb *pcb){

}
