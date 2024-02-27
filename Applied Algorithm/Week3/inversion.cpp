#include <iostream>
#include <vector>

const int MAX_VAL = 1000000; // Maximum value of elements as per the problem statement
const int MOD = 1e9 + 7; // Modulo value

// Function to get the least significant bit (LSB)
inline int LSB(int i) {
    return i & -i;
}

// Binary Indexed Tree (BIT) for maintaining frequencies
class FenwickTree {
private:
    std::vector<int> tree;
public:
    // Initialize the tree with maximum possible value + 1 to cover all element values
    FenwickTree(int size) : tree(size + 1, 0) {}

    // Function to update the tree - increment the frequency count for a number
    void update(int idx, int val) {
        while (idx < tree.size()) {
            tree[idx] = (tree[idx] + val) % MOD;
            idx += LSB(idx);
        }
    }

    // Function to get the prefix sum - number of elements <= a given number
    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum = (sum + tree[idx]) % MOD;
            idx -= LSB(idx);
        }
        return sum;
    }
};

// Function to calculate the number of inversions using a BIT
int countInversions(std::vector<int>& nums) {
    FenwickTree bit(MAX_VAL);
    long long inv_count = 0;

    // Process the elements in reverse order
    for (int i = nums.size() - 1; i >= 0; --i) {
        // Get the count of numbers already processed and smaller than nums[i]
        inv_count += bit.query(nums[i] - 1);
        inv_count %= MOD;
        
        // Increment the frequency count for nums[i]
        bit.update(nums[i], 1);
    }

    return inv_count;
}

int main() {
    std::ios::sync_with_stdio(false); // Speed up the I/O operations
    std::cin.tie(nullptr); // Untie cin and cout

    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int& num : nums) {
        std::cin >> num;
    }

    // Calculate and output the number of inversions
    std::cout << countInversions(nums) << std::endl;

    return 0;
}
