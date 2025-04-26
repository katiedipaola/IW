#include "dependency.h"

static u_int
encode_ie(void *buf, size_t bufsize,                  
               const u_int8_t *ie, size_t ielen,          
	       const char *leader, size_t leader_len)
{
  u_int8_t *p;
  int i;

  if (bufsize < leader_len)
    return 0;
  p = buf;
  memcpy(p, leader, leader_len);
  bufsize -= leader_len;
  p += leader_len;


  if (bufsize < ielen)
    return 0;

  for (i = 0; i < ielen && bufsize > 2; i++) {

    *p = 'x';
    *(p+1) = 'x';
    p += 2;
  }
  return (i == ielen ? p - (u_int8_t *)buf : 0);
}


static int
giwscan_cb(const struct ieee80211_scan_entry *se)
{
  u_int8_t buf[BUFSZ];
  char rsn_leader [LEADERSZ];


  if (se->se_rsn_ie != NULL) {
    if (se->se_rsn_ie[0] == IEEE80211_ELEMID_RSN)
      encode_ie(buf, sizeof(buf),
                se->se_rsn_ie, se->se_rsn_ie[1] + 2,
                rsn_leader, sizeof(rsn_leader) - 1);
  }
  
  return 0;
}

int main ()
{
  struct ieee80211_scan_entry se;
  u_int8_t ie [IESZ];
  se.se_rsn_ie = ie;
  se.se_rsn_ie[1] = IESZ - 2;

  giwscan_cb (&se);

  return 0;
}
