#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Job structure with ID, profit, and deadline
struct Job {
    char id;
    int profit;
    int deadline;
};

// Comparator to sort jobs by descending profit
bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

// Function to schedule jobs for maximum profit
void jobSequencing(vector<Job>& jobs) {
    // Sort jobs by profit descending
    sort(jobs.begin(), jobs.end(), cmp);

    int n = jobs.size();
    int maxDeadline = 0;
    for (auto &job : jobs) maxDeadline = max(maxDeadline, job.deadline);

    vector<char> schedule(maxDeadline + 1, '-');  // slots 1..maxDeadline
    int totalProfit = 0;

    for (auto &job : jobs) {
        // Try to schedule job in latest free slot before its deadline
        for (int slot = job.deadline; slot >= 1; slot--) {
            if (schedule[slot] == '-') {
                schedule[slot] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }

    cout << "Scheduled Jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (schedule[i] != '-') cout << schedule[i] << " ";
    }
    cout << "\nMaximum Profit: " << totalProfit << endl;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter job details (ID Profit Deadline):\n";
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << ": ";
        cin >> jobs[i].id >> jobs[i].profit >> jobs[i].deadline;
    }

    jobSequencing(jobs);

    return 0;
}
