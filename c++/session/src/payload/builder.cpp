
#include <iostream>
#include <sstream>
#include <iomanip>

#include "builder.hpp"

using namespace std;

vector<string> BasicBuilder::split(const string& s) {
   vector<string> rtn;

   // header: NNNN, the length of the payload
   auto hdr = s.substr(0,4);
   auto plen = atoi(hdr.c_str());

   // payload - really what could go wrong?
   auto payload = s.substr(5,plen); // +1 for the comma separating header
   istringstream iss(payload);
   string ss;

   getline(iss,ss,',');
   rtn.push_back(ss);
   getline(iss,ss,',');
   rtn.push_back(ss);
   getline(iss,ss);
   rtn.push_back(ss);

   return rtn;
}

string BasicBuilder::encode(const Message& m) {

   // payload
   string r = m.group();
   r += ",";
   r += m.name();
   r += ",";
   r += m.text();

   // a message = header + payload
   stringstream ss;
   ss << setfill('0') << setw(4) << r.length() 
      << "," << r; // NO! << std::ends;
   
   return ss.str();
}

Message BasicBuilder::decode(string raw) {
   auto parts = split(raw);
   Message m(parts[1],parts[0],parts[2]);
   return m;
}
