#include <iostream>
#include <fstream>
#include <string>
#include "simulation_data.pb.h"
using namespace std;

int main(int argc, char* argv[]) {
  cout << "console file "<< argv[1] << endl;

  phasefield::SetupData sim_data;

  // Read the existing address book.
  fstream input(argv[1], ios::in | ios::binary);
  if (!input) {
    cout << argv[1] << ": File not found." << endl;
  }
  sim_data.ParseFromIstream(&input);

  cout << sim_data.time_steps() << endl;

  return 0;
}
