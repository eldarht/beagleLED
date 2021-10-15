#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

#define GPIO_PATH "/sys/class/gpio/"

int main(int argc, char* argv[])
{
  std::cout << "Hello World";

  using namespace std::this_thread;     // sleep_for, sleep_until
  using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
  using std::chrono::system_clock;

  std::fstream fs;
  cout << "Starting LED flash" << endl;

  fs.open(GPIO_PATH "export", std::fstream::out);
  fs << "53";
  fs.close();
  fs.open(GPIO_PATH "gpio53/direction", std::fstream::out);
  fs << "out";
  fs.close();

  while (1)
  {
	  fs.open(GPIO_PATH "/gpio53/value", std::fstream::out);
	  fs << "1";
	  fs.close();
	  sleep_for(100ms);
	  fs.open(GPIO_PATH "/gpio53/value", std::fstream::out);
	  fs << "0";
	  fs.close();
	  sleep_for(100ms);
  }
}
