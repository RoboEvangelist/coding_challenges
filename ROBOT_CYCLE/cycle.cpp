#include <time.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <csignal>
#include <chrono>
#include <vector>
#include <unordered_set>
#include <utility>

using namespace std;

struct pair_hash
{
	template <class T1, class T2>
	std::size_t operator () (std::pair<T1, T2> const &pair) const
	{
		std::size_t h1 = std::hash<T1>()(pair.first);
		std::size_t h2 = std::hash<T2>()(pair.second);

		return h1 ^ h2;
	}
};

// To execute C++, please define "int main()"
int main() {
  // U, L, D, R
  int mov_x[] = {0, -1,  0, 1};
  int mov_y[] = {1,  0, -1, 0};
  
  int distance_x = 0;
  int distance_y = 0;
  unordered_set<pair<int, int>, pair_hash> location_set;
  
  /// initial motion is to the right
  string motions = "FLLLLR";
  int string_size = motions.length();
  int motion_state = 0;
  for (int i = 0; i < string_size; ++i) {
    cout << distance_x << ", " << distance_y << "\n";
    if (location_set.find({distance_x, distance_y}) != location_set.end()) {
      cout << "Cycle Found\n";
      break;
    } else {
      location_set.insert(make_pair(distance_x, distance_y));
    }
    if (motions[i] == 'L') {
      motion_state++;
    } else if (motions[i] == 'R') {
      motion_state--;
    }
    motion_state = motion_state % 4;
    distance_x += mov_x[motion_state];
    distance_y += mov_y[motion_state];
  }

  return 0;
}

// FLLL
// L, R, F
// cyclic

