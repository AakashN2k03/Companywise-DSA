// LEETCODE: 735. Asteroid Collision 

// PATTERN: monotonic stack  

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        list<int> st; // Acts as a stack to keep surviving asteroids

        for (int i = 0; i < n; i++) {
            // 🚀 Case 1: Right-moving asteroid, push into the stack

            if (asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            }
            // 💥 Case 2: Left-moving asteroid (possible collision)
            else {
                // Destroy all smaller right-moving asteroids
                while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) {
                    st.pop_back(); // Right asteroid explodes
                }

                // If same size right-moving asteroid and left moving asteroi →  explode both
                if (!st.empty() && st.back() == abs(asteroids[i])) {
                    st.pop_back(); // Both are destroyed
                }
                // No collision or only left-moving asteroids remain
                else if (st.empty() || st.back() < 0) {
                    st.push_back(asteroids[i]); // Survives
                }
                // Else: larger right-moving asteroid survives → do nothing
            }
        }

        // Convert the list to a vector to return
        return vector<int>(st.begin(), st.end());
    }
};
//TIME COMPLEXITY=O(N)
//SPACE COMPLEXITY=O(N)
