#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define LED2_PATH "/sys/class/leds/beaglebone:green:usr2"

int main(int argc, char* argv[])
{
  std::cout << "Hello World";

  std::fstream fs;
  cout << "Starting LED flash" << endl;

  while (1)
  {
	  fs.open(LED2_PATH "/trigger", std::fstream::out);
	  fs << "timer";
	  fs.close();
	  fs.open(LED2_PATH "/delay_on", std::fstream::out);
	  fs << "100";
	  fs.close();
	  fs.open(LED2_PATH "/delay_off", std::fstream::out);
	  fs << "100";
	  fs.close();
  }
}
