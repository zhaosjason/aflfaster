#include <stdio.h>
#include <string.h>

#define BUF_LEN 1024
#define SMALL_BUF_LEN 1

int main(int argc, char* argv[]) {

  if (argc != 2) {
    printf("usage: ./test1 <file>\n");
    return 1;
  }
  FILE *file = fopen( argv[1], "r");
  if ( file != NULL ) {
    char str[BUF_LEN];
    if ( fgets( str, BUF_LEN, file ) != NULL ) {
      int len = strlen( str );
      if (len < 2) {
        return 1;
      }

      // Everything above is overhead.

      if (str[0] == 'a') {
        if (str[1] == 'b') {
          char buf[SMALL_BUF_LEN];
          strcpy( buf, str );
        }
        else {
          return 1;
        }
      }

      if (str[0] == 'z') {
        if (str[1] == 'y') {
          char buf[SMALL_BUF_LEN];
          strcpy( buf, str );
        }
        else{
          return 1;
        }
      }

    }
  }

}