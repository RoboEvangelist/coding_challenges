#include <iostream>
#include <unordered_set>
#include <utility>
#include <string>

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

int main() {
  // Up, Left, Down, Right
  int mov_x[] = {0, -1,  0, 1};
  int mov_y[] = {1,  0, -1, 0};
  
  /// initial position is at 0, 0
  int distance_x = 0;
  int distance_y = 0;
  std::unordered_set<std::pair<int, int>, pair_hash> location_set;
  
  std::string motions = "FLLLLR";
  int string_length = motions.length();
  /// initial motion is up
  int motion_state = 0;
  for (int i = 0; i < string_length; ++i) {
    std::cout << distance_x << ", " << distance_y << "\n";
    if (location_set.find({distance_x, distance_y}) != location_set.end()) {
      std::cout << "Cycle Found\n";
      break;
    } else {
      location_set.insert(std::make_pair(distance_x, distance_y));
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

