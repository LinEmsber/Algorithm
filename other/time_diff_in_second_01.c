/* calculate time difference in sencond */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

double time_diff_in_second(struct timespec t1, struct timespec t2)
{
	struct timespec diff;

	if (t2.tv_nsec - t1.tv_nsec < 0) {
		diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
		diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
	} else {
		diff.tv_sec  = t2.tv_sec - t1.tv_sec;
		diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
	}

	return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}


int main()
{
        double time_diff;
        struct timespec start, end;

        clock_gettime(CLOCK_REALTIME, &start);

        sleep(3);

        clock_gettime(CLOCK_REALTIME, &end);

        time_diff = time_diff_in_second(start, end);

        printf("time difference in sencond: %lf\n", time_diff);

        return 0;
}
