#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int irand(int min, int max) { return ((double)rand() / ((double)RAND_MAX + 1.0)) * (max - min + 1) + min;}

int toHit( int attackerWS, int defendantWS) {
  if ( attackerWS > defendantWS ) { return 3; } 
  else { if (attackerWS*2 < defendantWS) { return 5; } else { return 4; } };
};

class TrooperType {
public:
  string name; int WS; int BS; int W; int T; int Ld;
  TrooperType() { name = "just a squig";  WS = 1; BS =1; W=1; T=3;  Ld = 7; }
  TrooperType(string name, int WS, int BS, int W, int T, int Ld) : name(name),  WS(WS), BS(BS), W(W), T(T), Ld(Ld) { }
};

class Unit { 
public:
  TrooperType type; int size; int orginalSize;
};

class Dice {
public:
  int k(int i) { return irand(1,i); };
  std::vector<int> rzuc_n_razy_k(int howMuch, int range) {
    std::vector<int> resu;
    for (int s = 0; s<howMuch; ++s ) {  resu.push_back(irand(1,range)); };
    return resu;
   };
};

class Fight {
  protected:
    Dice rzuc;
    Unit Adversary1, Adversary2;
  public:
    Fight() { Dice rzut; Unit adv1, adv2;   rzuc = rzut; Adversary1 = adv1; Adversary2 = adv2; };
    Fight( Unit adv1, Unit adv2 ) : Adversary1(adv1), Adversary2(adv2)  {  };
    void resolveFightingTurn(Unit &adversary1, Unit &adversary2, Dice rzut);
};

void Fight::resolveFightingTurn(Unit &adversary1, Unit &adversary2, Dice rzut) {
  cout << "Pierwszy walczący to " << adversary1.type.name << ", i ma on WS-a " << adversary1.type.WS << "," << endl;
  cout << "a drugi to " << adversary2.type.name << ", i ma on WS-a " << adversary2.type.WS << "." << endl;
  int hitRoll = rzut.k(6);
  int needToHit = toHit( adversary1.type.WS, adversary2.type.WS);
  cout << "Na hita musi wyrzucić " << needToHit  << " a wyrzucił "  << hitRoll << endl;
  if (hitRoll >= needToHit) { cout << "trafił" << endl; } else { cout << " nie trafił " << endl; };

}

void declareTroopers(map<string,TrooperType>* troopers) {
  // WS BS W T Ld

  (*troopers)["Elf"] = TrooperType("Elf",4,4,1,3,9);
  (*troopers)["Orc"] = TrooperType("Orc",3,3,1,4,8);
};

int main() {

  srand(time(0));
  Dice kostka;
  map<string,TrooperType> troopers; 
  declareTroopers(&troopers);

  Unit OrcGroup;
  OrcGroup.type = troopers["Orc"];
  OrcGroup.size =1;
  Unit ElfGroup;
  ElfGroup.type = troopers["Elf"];
  ElfGroup.size =1;

  Fight melee;
  // melee.resolveFightingTurn(OrcGroup, ElfGroup, kostka);
  
  std::vector<int> porcys;
  porcys = kostka.rzuc_n_razy_k(10,6);
  for (int log = 0; log < porcys.size(); ++log ) {
  cout << porcys[log] << endl; };



}
