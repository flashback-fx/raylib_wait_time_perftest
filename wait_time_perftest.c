#include <raylib.h>
#include <stddef.h>

#if !defined(WAIT_TIME_SECONDS) && !defined(WAIT_TIME_MILLISECONDS)
	#error WAIT_TIME_SECONDS or WAIT_TIME_MILLISECONDS must be defined
#endif
#if defined(WAIT_TIME_SECONDS) && defined(WAIT_TIME_MILLISECONDS)
	#error Only WAIT_TIME_SECONDS or WAIT_TIME_MILLISECONDS must be defined
#endif

#define NUMBER_OF_LOOPS 20000
#define WAIT_TIME 0.001

int main(void)
{
	InitWindow(10, 10, "WaitTime performance test");

#if defined(WAIT_TIME_SECONDS)
	TraceLog(LOG_INFO, "Testing WaitTime with seconds parameter");
#elif defined(WAIT_TIME_MILLISECONDS)
	TraceLog(LOG_INFO, "Testing WaitTime with milliseconds parameter");
#endif
	TraceLog(LOG_INFO, "Used parameters are:");
	TraceLog(LOG_INFO, "Number of loops: %zu", NUMBER_OF_LOOPS);
	TraceLog(LOG_INFO, "Wait time per loop: %f", WAIT_TIME);
	TraceLog(LOG_INFO, "Starting WaitTime performance test");

	double initial_time = GetTime();

	for (size_t i = 0; i < NUMBER_OF_LOOPS; i += 1) {
#if defined(WAIT_TIME_SECONDS)
		WaitTime(WAIT_TIME);
#elif defined(WAIT_TIME_MILLISECONDS)
		WaitTime(WAIT_TIME * 1000.0);
#endif
	}

	double result_time = GetTime() - initial_time;

	TraceLog(LOG_INFO, "Test completed in: %f seconds", result_time);

	return 0;
}

