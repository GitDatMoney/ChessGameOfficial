#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
using namespace std;

class CustomMatch {
private:

public:
  CustomMatch();
  void beginTimedMatch();
  string secondsToTime(int seconds);
};
