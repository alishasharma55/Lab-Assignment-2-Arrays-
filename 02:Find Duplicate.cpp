#include <iostream>
using namespace std;

int findDuplicate(int nums[], int n) {
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    int nums[n + 1];

    cout << "Enter " << n + 1 << " elements: ";
    for (int i = 0; i <= n; i++) {
        cin >> nums[i];
    }

    cout << "Duplicate number: " << findDuplicate(nums, n);

    return 0;
}
