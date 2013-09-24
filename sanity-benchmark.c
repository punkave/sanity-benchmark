#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

static double now();
static void io();
static void cpu();

int main(int argc, char *argv[]) {
  io();
  cpu();
}

static void io() {
  double start = now();
  int i;
  FILE *in = fopen("/dev/urandom", "r");
  FILE *out = fopen("/tmp/test", "w");
  for (i = 0; (i < 1000000); i++) {
    int ch = fgetc(in);
    fputc(ch, out);
  }
  fclose(in);
  fclose(out);
  double end = now();
  printf("I/O benchmark time: %.04f\r\n", end - start);
}

static void cpu() {
  double start = now();
  double s = 1.0;
  int i;
  for (i = 0; (i < 1000000); i++) {
    s = sin(i);
  }
  printf("Printing result of CPU test computation so the compiler cannot optimize it away:\r\n");
  printf("%f\r\n", s);
  double end = now();
  printf("CPU benchmark time: %.04f\r\n", end - start);
}

static double now() {
  struct timeval tv;
  gettimeofday(&tv, 0);
  return tv.tv_sec + ((double) tv.tv_usec) / 1000000.0;
}

