#include <iostream>
#include <fstream>
#include <string>
#include "simulation_data.pb.h"
using namespace std;

int main(int argc, char* argv[]) {
  cout << "console file "<< argv[1] << endl;

  // Read the existing address book.
  fstream input(argv[1], ios::in | ios::binary);
  if (!input) {
    cout << argv[1] << ": File not found." << endl;
  }

  phasefield::SetupData sim_data;
  

  return 0;
}
