#ifndef PKT_H
#define PKT_H

#include <map>
#include <string>

using namespace std;

extern map<string, string> pkt_fields;

extern int iptoint(string ip);

class packet {
};

#endif

