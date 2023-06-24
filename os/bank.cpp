#include <iostream>
#include <vector>

using namespace std;

bool banker(vector<string> processes, vector<int> resources, vector<vector<int>> allocation, vector<vector<int>> max_demand, vector<int> available) {
    int num_processes = processes.size();
    int num_resources = resources.size();

    // Calculate the need matrix
    vector<vector<int>> need(num_processes, vector<int>(num_resources));
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            need[i][j] = max_demand[i][j] - allocation[i][j];
        }
    }

    // Initialize the finish vector
    vector<bool> finish(num_processes, false);

    // Initialize the work vector
    vector<int> work = available;

    bool found;
    do {
        found = false;

        // Find a process i such that finish[i] = false and need[i] <= work
        for (int i = 0; i < num_processes; i++) {
            if (!finish[i]) {
                bool can_allocate = true;
                for (int j = 0; j < num_resources; j++) {
                    if (need[i][j] > work[j]) {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    found = true;
                    finish[i] = true;
                    for (int j = 0; j < num_resources; j++) {
                        work[j] += allocation[i][j];
                    }
                }
            }
        }
    } while (found);

    // Check if all processes have finished
    for (bool f : finish) {
        if (!f) {
            return false; // System is in an unsafe state
        }
    }
    return true; // System is in a safe state
}

int main() {
    // Example inputs
    vector<string> processes = {"P0", "P1", "P2"};
    vector<int> resources = {10, 5, 7};
    vector<vector<int>> allocation = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}};
    vector<vector<int>> max_demand = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}};
    vector<int> available = {3, 3, 2};

    // Call the banker function
    bool result = banker(processes, resources, allocation, max_demand, available);

    // Check if the request can be granted
    if (result) {
        cout << "Request can be granted." << endl;
    } else {
        cout << "Request cannot be granted." <<endl;
    }

    return 0;
}