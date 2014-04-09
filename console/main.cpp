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

  cout << "time steps:" << sim_data.time_steps() << endl;
  cout << "rows " << sim_data.phase_field().row_size() << endl;
  cout << "cols " << sim_data.phase_field().row(0).element_size() << endl;
  cout << "first element: " << sim_data.phase_field().row(0).element(0) << endl;

  int rows = sim_data.phase_field().row_size();
  int cols = sim_data.phase_field().row(0).element_size();

  for(int i = 0; i < rows; i++) 
  {
    for(int j = 0; j < cols; j++)
    {
      cout << sim_data.phase_field().row(i).element(j) << " ";
    }
    cout << endl;
  }


  return 0;
}
