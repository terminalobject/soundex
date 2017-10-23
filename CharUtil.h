#ifndef CharUtil_h
#define CharUtil_h

   char lower(char c) {
      return std::tolower(static_cast<unsigned char>(c));
   };

   bool isVowel(char letter) {
      return
	 std::string("aeiouy").find(lower(letter) ) != std::string::npos;
   };

#endif 
