#ifndef BASICBUILDER_HPP
#define BASICBUILDER_HPP

#include <string>
#include <vector>

#include "message.hpp"

class BasicBuilder {
   private:  
     std::vector<std::string> split(const std::string& s);

   public: 
     BasicBuilder() {}
     virtual ~BasicBuilder() {}

     std::string encode(const Message& m);
     Message decode(std::string raw);

  
};

#endif
