#include "sampleset.hpp"
#include <iostream>

using namespace std;

int main (int argc, char* argv[]) {
  if (argc != 2) {
    cout << "Usage: <filename>" << endl;
  }

  //creates an instance of 
  SampleSet test_set(argv[1]);
  //returns sizes of the dataset
  cout << "Number Samples: " << test_set.sampleSize() << endl; 
  cout << "Number Determinands: " << test_set.deterSize() << endl; 

  SampleSet filtered = test_set.filterGroup(1);
  int test_id = test_set.deterSearch("4-Phenoxybutyric acid :- {PBA}");
  cout << "Litter Level: " << filtered.getAvg() << endl;
  cout << test_set.sampleAt(31951).getDeterminand() << endl;
  cout << test_set.sampleAt(31951).getFull() << endl;
  cout << "Test ID:" << test_id << endl;

  //outputs data from an individual sample
  Sample sample1 = test_set.sampleAt(0);
  cout << "Sample info at pos 1: " << sample1.getDeterminand() 
  << " " << sample1.getLevel() << " " << sample1.getLocation() << endl;
  SampleSet count;

  //calculates the common pollutants
  for (int i=0; i<test_set.deterSize(); i++) {
    if (test_set.determinandAt(i).getNumberEntries() >= 1000){
      count.addDeterminand(test_set.determinandAt(i));
    }
  }

  cout << "Number of common determinands: " << count.deterSize() << endl;
}