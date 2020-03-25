#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  int fd = open("foo", O_RDWR | O_CREAT, 0644);
  write(fd, "foo", 3);
  struct timespec times[2] = {};
  times[0].tv_sec = 1;
  times[0].tv_nsec = 2;
  times[1].tv_sec = 3;
  times[1].tv_nsec = 4;
  int rc = futimens(fd, times);
  printf("rc=%d\n", rc);
  close(fd);
  return rc;
}


