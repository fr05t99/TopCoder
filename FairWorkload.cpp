#include<bits/stdc++.h>
using namespace std;
class FairWorkload {
    public:
    int getMostWork(vector<int> folders, int workers) {
        int ans = INT_MAX;
        int s = INT_MIN, e = 0;
        for (int i : folders) {
            s = max(s, i);
            e += i;
        }
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int currSum = 0, maxSum = 0;
            int numOfWorkers = 1;
            for (int i : folders) {
                if (currSum + i > mid) {
                    currSum = i;
                    numOfWorkers++;
                } else {
                    currSum += i;
                }
                maxSum = max(maxSum, currSum);
            }
            if (numOfWorkers <= workers) {
                e = mid - 1;
                ans = min(ans, maxSum);
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};
int main() {
    FairWorkload fairWorkload;
    cout << fairWorkload.getMostWork({  950, 650, 250, 250, 350, 100, 650, 150, 150, 700}, 6);
}
