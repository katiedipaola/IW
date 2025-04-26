#include "../stubs.h"

typedef unsigned int u_int;
typedef unsigned char u_int8_t;

struct ieee80211_scan_entry {
  u_int8_t *se_rsn_ie;
};

#define IEEE80211_ELEMID_RSN 200

#define LEADERSZ 1

#define BUFSZ BASE_SZ + LEADERSZ + 2

#define IESZ (BUFSZ - LEADERSZ) + 5
