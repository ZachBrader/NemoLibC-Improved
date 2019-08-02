#pragma once

#ifndef __NEMO_CONFIG
	#define __NEMO_CONFIG

	#ifdef __has_include
		#define _CAN_CHECK_INCLUDE
	#endif

	#ifdef _CAN_CHECK_INCLUDE
		#if __has_include(<execution>)
			#define _C17_EXECUTION_AVAILABLE 0
			#include <execution>
		#else
			#define _C17_EXECUTION_AVAILABLE 0
		#endif
	#else
		#define _C17_EXECUTION_AVAILABLE 0
	#endif

#endif // end __NEMO_CONFIG
