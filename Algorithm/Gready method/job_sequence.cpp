#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Job structure
struct Job {
    int index;
    int deadline;
};

// Function to schedule maximum number of jobs
int JobSequencing(vector<Job>& jobs, vector<int>& J) {
    // Find maximum deadline
    int maxDeadline = 0;
    for (auto &job : jobs) maxDeadline = max(maxDeadline, job.deadline);

    vector<int> slot(maxDeadline + 1, 0);
    int k = 0;

    // Consider jobs in order of earliest deadline first
    for (auto &job : jobs) {
        for (int j = job.deadline; j >= 1; j--) {
            if (slot[j] == 0) {
                slot[j] = job.index;
                J[k++] = job.index;
                break;
            }
        }
    }
    return k;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);
    cout << "Enter deadlines for each job (1-based index):\n";
    for (int i = 0; i < n; i++) {
        jobs[i].index = i + 1;
        cin >> jobs[i].deadline;
    }

    // Sort jobs by deadline ascending
    sort(jobs.begin(), jobs.end(), [](Job a, Job b) {
        return a.deadline < b.deadline;
    });

    vector<int> J(n);
    int k = JobSequencing(jobs, J);

    cout << "Maximum number of jobs that can be scheduled: " << k << endl;
    cout << "Job sequence: ";
    for (int i = 0; i < k; i++) {
        cout << J[i] << " ";
    }
    cout << endl;

    return 0;
}
