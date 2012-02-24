//This is the interface por use the CPU Engine

#ifndef CPU_ENGINE_H_
#define CPU_ENGINE_H_

	#include <stdint.h>

	typedef struct{
			uint16_t ip;

			char *code_segment;
			uint16_t code_segment_size;

			char *data_segment;
			uint16_t data_segment_size;

	}t_cpu_reg;

	typedef struct{

			uint16_t tick_rate;

			t_cpu_reg regx;
	}t_cpu;

	t_cpu 	 *cpu_engine_init();
	void 	 cpu_engine_load(t_cpu*, t_cpu_reg*);
	void 	 cpu_engine_run(t_cpu*);


#endif /* CPU_ENGINE_H_ */
