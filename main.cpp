#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;



unsigned int PRNG(unsigned int nSeed)
{
  nSeed = (8253729 * nSeed + 2396403);
  return nSeed  % 32767;
}
                                        

int main() {
  unsigned int nSeed = time(0);
  srand(nSeed);
  cout << "seed is" << time(0) << endl;
  int i;
  int number;
  for (i = 0; i < 4; i++) {
    nSeed = PRNG(nSeed);
    srand(nSeed);
    number = rand()%8;  // generate a random number
    cout << "number is " << number << endl;
  }
}

