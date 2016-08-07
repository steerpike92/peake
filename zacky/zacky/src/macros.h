#include <iostream>
#ifdef NDEBUG
	#define LOG_ERROR
#else
#define LOG_ERROR std::cout<<"FILE: "<<__FILE__<<"\nLINE: "<<__LINE__<<"\nFUNCTION: "<<__func__<<std::endl; \
		exit(EXIT_FAILURE);
#endif
