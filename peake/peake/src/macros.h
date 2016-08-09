#include <iostream>
#include <fstream>
#ifdef NDEBUG
	#define LOG_ERROR
#else
#define LOG_ERROR std::cerr<<"FILE: "<<__FILE__<<"\nLINE: "<<__LINE__<<"\nFUNCTION: "<<__func__<<std::endl; \
		exit(EXIT_FAILURE);
#endif
