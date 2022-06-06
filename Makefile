all: wait_time_perftest_s wait_time_perftest_ms

wait_time_perftest_s: wait_time_perftest.c
	gcc -std=c99 -Wall -Wextra -pedantic -DWAIT_TIME_SECONDS wait_time_perftest.c -o out_s/wait_time_perftest_s  -lraylib -lGL -lm -pthread -ldl -lrt -lX11
wait_time_perftest_ms: wait_time_perftest.c
	gcc -std=c99 -Wall -Wextra -pedantic -DWAIT_TIME_MILLISECONDS wait_time_perftest.c -o out_ms/wait_time_perftest_ms  -lraylib -lGL -lm -pthread -ldl -lrt -lX11
