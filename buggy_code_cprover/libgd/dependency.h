#include "../stubs.h"

#define INSZ BASE_SZ + 1

#define ENTITY_NAME_LENGTH_MAX 8

struct entities_s {
  char	*name;
  int	value;
};
struct entities_s entities[] = {
  {"AElig", 198},
  {"Aacute", 193},
  {"Acirc", 194},
};
#define NR_OF_ENTITIES 3

#define Tcl_UniChar int
#define gdFTEX_Unicode 0
#define gdFTEX_Shift_JIS 1
#define gdFTEX_Big5 2

