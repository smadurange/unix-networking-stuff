#include <assert.h>
#include <stdio.h>

/* determines the host byte order - Unix Network Programming, W. Richard Stevens
 */
int main(int argc, char *argv[]) {
  union {
    short s;
    char c[sizeof(short)];
  } un;

  un.s = 0x0102;
  assert(sizeof(short) == 2);

  if (un.c[0] == 1 && un.c[1] == 2)
    printf("byte order: big endian\n");
  else if (un.c[0] == 2 && un.c[1] == 1)
    printf("byte order: little endian\n");
  else
    printf("byte order: unknown");

  return 0;
}