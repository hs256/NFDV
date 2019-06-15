#include "pkt.h"
#include <string>

using namespace std; 

map<string, string> pkt_fields  = {
  {"sip", "L3+96"},
  {"dip", "L3+128"},
  {"proto", "L3+72"},
  {"sport", "L4+0"},
  {"dport", "L4+16"},
  {"flag_syn", "L4+110"},
  {"flag_fin", "L4+111"}
};


int iptoint(string ip) {
  const char *a = ip.c_str();
  unsigned int val;
  const char *start = a;
  for (int i = 0; i < 4; i++) {
    char c;
    int n = 0;
    while (1) {
      c = *start;
      start++;
      if (c >= '0' && c <= '9') {
	n *= 10;
	n += c - '0';
      } else if ((i < 3 && c == '.') || i == 3) {
	  break;
      } else {
	return -1;
      }
    }
    if (n >= 256) {
      return -1;
    }
    val *= 256;
    val += n;
  }

  return val;
}
  /*char ipbytes[4];
  sscanf(a, "%uhh.%uhh.%uhh.%uhh", &ipbytes[3], &ipbytes[2], &ipbytes[1], &ipbytes[0]);
  return ipbytes[0] | ipbytes[1] << 8 | ipbytes[2] << 16 | ipbytes[3] << 24;
}*/
