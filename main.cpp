#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;

int irand(int min, int max) {
      return ((double)rand() / ((double)RAND_MAX + 1.0)) * (max - min + 1) + min;
}

class TrooperType {

  public:
    int WS, BS, W, Ld;
};


int main() {
  srand(time(0));
  cout << "seed is" << time(0) << endl;
  int i,number;
  for (i = 0; i < 4; i++) {
    number = irand(1,6);
    cout << "number is " << number << endl;
  }
  TrooperType Orc;
  Orc.WS = 4;
}

