import numpy as np
import random

# Define the number of servers in a grid
N = 10  # Number of servers in each dimension

# All servers have equal capacity
Capacity = np.full((N, N), 50)
print(Capacity)
# Get the number of jobs from the user
num_jobs = int(input("Enter the number of jobs: "))

# Initialize the number of migrations and jobs
Migrations = 0
Jobs = 0

# Start the simulation
while Jobs < N * N * Capacity[0, 0] and Jobs < num_jobs:
    # Select a random server
    source_server_x = random.randint(0, N - 1)
    source_server_y = random.randint(0, N - 1)

    # If the source server has enough capacity, process the job on the same server
    if Jobs + 1 <= Capacity[source_server_x, source_server_y]:
        Jobs += 1
        Capacity[source_server_x, source_server_y] -= 1
        print(f"Job: {Jobs}, Server: ({source_server_x}, {source_server_y}), Processing Time: 1")
    else:
        # Find a destination server with available capacity
        dest_server_x, dest_server_y = np.where(Capacity >= 1)
        if dest_server_x.size > 0:
            dest_index = random.randint(0, dest_server_x.size - 1)
            dest_x, dest_y = dest_server_x[dest_index], dest_server_y[dest_index]
            Migrations += 1
            Jobs += 1
            Capacity[dest_x, dest_y] -= 1
            print(f"Job: {Jobs}, Source Server: ({source_server_x}, {source_server_y}), Destination Server: ({dest_x}, {dest_y}), Processing Time: 1")

# Print the number of migrations and total number of jobs processed
print("Number of migrations:", Migrations)
print("Total number of jobs processed:", Jobs)