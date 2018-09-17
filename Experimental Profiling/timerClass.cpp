#include <sys/time.h>
class Timer{
  private:
    timeval startTime;
    timeval endTime;

  public:
    void start(){
      gettimeofday(&startTime, 0);
    }

    double stop(){
      long seconds, nseconds;
      double duration;
      gettimeofday(&endTime, 0);
      seconds  = endTime.tv_sec - startTime.tv_sec;
      nseconds = endTime.tv_usec - startTime.tv_usec;
      duration = seconds + nseconds/1000000.0;
      return duration;
    }
};
