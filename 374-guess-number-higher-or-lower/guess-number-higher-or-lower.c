int guess(int num);

int guessNumber(int n) {
      int left = 1;                // Start search from 1
      int right = n;               // End search at n

      while (left <= right) {
            int mid = left + (right - left) / 2;  // Compute mid safely to avoid overflow
            int result = guess(mid);              // Call external guess API

            if (result == 0) {
                  return mid;      // Found the correct number
            } else if (result < 0) {
                  right = mid - 1; // Target is smaller than mid
            } else {
                  left = mid + 1;  // Target is greater than mid
            }
      }

      return -1; // Should never hit this if guess is guaranteed correct
}