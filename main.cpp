#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int irand(int min, int max) {
  return ((double)rand() / ((double)RAND_MAX + 1.0)) * (max - min + 1) + min;
}

class TrooperType {
public:
  int WS;
  int BS;
  int W;
  int T;
  int Ld;
  
public:
  TrooperType(int WS, int BS, int W, int T, int Ld) : WS(WS), BS(BS), W(W), T(T), Ld(Ld) { }
};

class Unit { 
public:
  TrooperType type;
  int size;
  int orginalSize;
};

class dice {
public:
  int k(int i) { return irand(1,i); }
};

void declareTroopers(std::vector<TrooperType>* troopers) {
  /*
  TrooperType Orc;
  Orc.WS = 3;
  Orc.T = 4;
  Orc.W = 1 ;
  Orc.Ld = 7;
  */
  
  troopers->push_back(TrooperType(3,3,4,1,7)); // ustaw sobie te liczby tak, żeby sie zgadzały
  troopers->push_back(TrooperType(3,1,4,1,7));
  troopers->push_back(TrooperType(3,2,4,1,7));
  troopers->push_back(TrooperType(3,100,4,1,7));
  
  /*
  TrooperType Elf;
  Elf.WS = 4;
  Elf.T = 3;
  Elf.W = 1;
  Elf.Ld = 9;
  
  troopers->push_back(Elf);
  */
};

int main() {
  // init 
  srand(time(0));
  dice rzuc;
  
  std::vector<TrooperType> troopers; 
  declareTroopers(&troopers);

  // some action

}
