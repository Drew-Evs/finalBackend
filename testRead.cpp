#include "sampleset.hpp"
#include <iostream>

using namespace std;

int main (int argc, char* argv[]) {
  if (argc != 2) {
    cout << "Usage: <filename>" << endl;
    exit(1);
  }

  //creates an instance of 
  SampleSet data(argv[1]);
  SampleSet filtered = data.filterGroup(1);

  filtered = data.filterLocation("MALHAM TARN");
  cout << "Size after 1st filter: " << filtered.sampleSize() << endl;
  filtered = filtered.filterName("Nitrogen - N");
  cout << "Size after 2nd filter: " << filtered.sampleSize() << endl;
  filtered = filtered.filterDate("2024-09-03T10:47:00");
  cout << "Size after 3rd filter: " << filtered.sampleSize() << endl;
  //SampleSet filtered = filtered.filterTime(timePeriodSearchText.toStdString());
  cout << "Avg: " << filtered.getAvg() << endl;
  cout << "Name: " << filtered.sampleAt(0).getName() << " Location: " <<
  filtered.sampleAt(0).getLocation() << " Time: " << filtered.sampleAt(0).getTime() << endl;
}

