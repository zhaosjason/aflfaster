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
          if (str[2] == 'c') {
            if (str[3] == 'd') {
              if (str[4] == 'e') {
                if (str[5] == 'f') {
                  char buf[SMALL_BUF_LEN];
                  strcpy( buf, str );
                }
              }
            }
          }
        }
      }

      if (str[0] == 'z') {
        if (str[1] == 'q') {
          if (str[2] == ';') {
            if (str[3] == '"') {
              if (str[4] == '#') {
                if (str[5] == 'a') {
                  char buf[SMALL_BUF_LEN];
                  strcpy( buf, str );
                }
              }
            }
          }
        }
      }

      if (str[0] == '6') {
        if (str[1] == 'c') {
          if (str[2] == 'w') {
            if (str[3] == '"') {
              if (str[4] == '.') {
                if (str[5] == '~') {
                  char buf[SMALL_BUF_LEN];
                  strcpy( buf, str );
                }
              }
            }
          }
        }
      }

    }
  }
}