#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{

  if (argc != 2)
  {
    cout << "Invalid arguments. Usage ./app <filename>\n";
    return 1;
  }

  ifstream inFile(argv[1]);

  if (!inFile.is_open())
  {
    cout << "Could not open " << argv[1] << ".\n";
    return 1;
  }

  string line;
  inFile >> line;
  string::iterator left = line.begin();
  string::iterator right = line.end();
  int sum = 0;

  while (inFile)
  {
    while (!isdigit(*left) || !isdigit(*right))
    {
      if (!isdigit(*left))
        left++;

      if (!isdigit(*right))
        right--;
    }

    cout << *left << " " << *right << "\n";

    sum += ((int)*left - 48) * 10 + (int)*right - 48;

    inFile >> line;
    left = line.begin();
    right = line.end();
  }

  cout << "Final sum: " << sum << "\n";
  inFile.close();

  return 0;
}