#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

map<string, int> nNames = {{"one", 1},
                           {"two", 2},
                           {"three", 3},
                           {"four", 4},
                           {"five", 5},
                           {"six", 6},
                           {"seven", 7},
                           {"eight", 8},
                           {"nine", 9}};

int checkNumName(string s);

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

  string line, buffer;
  int sum = 0;
  inFile >> line;

  while (inFile)
  {
    buffer = "";
    int left = -1, right = -1;

    for (char c : line)
    {
      if (isdigit(c))
      {
        if (left == -1)
          left = (int)c - 48;
        right = (int)c - 48;

        buffer = "";
      }
      else
      {
        buffer += c;
        int newNumber = checkNumName(buffer);
        if (newNumber != -1)
        {
          if (left == -1)
            left = newNumber;
          right = newNumber;

          buffer = "";
        }
      }
    }

    inFile >> line;
    cout << left << " " << right << endl;
    sum += left * 10 + right;
  }

  cout << "Final sum: " << sum << endl;
  inFile.close();

  return 0;
}

int checkNumName(string s)
{
  for (pair<string, int> pair : nNames)
    if (s.find(pair.first) != string::npos)
      return pair.second;

  return -1;
}