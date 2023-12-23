import numpy as np
import random
import matplotlib.pyplot as plt

# Define constants
GRID_SIZE = 10
MAX_CAPACITY = 100
MIN_CAPACITY = 50
MAX_JOBS = 500  # Specify the maximum number of jobs

server_capacities = [random.randint(MIN_CAPACITY, MAX_CAPACITY) for _ in range(GRID_SIZE)]
print("Initial Server Capacities:", server_capacities)

# Establish interconnections between servers
server_connections = np.zeros((GRID_SIZE, GRID_SIZE))

for i in range(GRID_SIZE):
    for j in range(GRID_SIZE):
        if i == j:
            server_connections[i][j] = 0  # No connection between the same server
        elif (i // GRID_SIZE == j // GRID_SIZE) and (abs(i - j) == 1 or abs(i - j) == GRID_SIZE):
            server_connections[i][j] = 1

print("Server Connections:\n", server_connections)

# Initialize counters
lt = []

for i in range(0, MAX_JOBS+1, 100):
    total_migrations = 0
    total_jobs_processed = 0

    # Simulate job submission and migration
    print(f"\nJob Migration Details for {i} jobs:",end="")
    while total_jobs_processed < i:  # Update loop condition to consider total_jobs_processed
        source_server = random.randint(0, GRID_SIZE - 1)

        # If the source server is not full, process jobs on the same server
        if total_jobs_processed < server_capacities[source_server]:
            total_jobs_processed += 1  # Process one job at a time
        else:
            # If the source server is full, migrate jobs to adjacent servers
            migration_attempt = False
            for destination_server in range(GRID_SIZE):
                if server_connections[source_server][destination_server] == 1 and total_jobs_processed < server_capacities[destination_server]:
                    total_migrations += 1
                    total_jobs_processed += 1  # Process one job at a time
                    server_capacities[destination_server] -= 1  # Update the capacity of the destination server
                    migration_attempt = True
                    break

            # If migration was attempted and failed, increment total_jobs_processed
            if not migration_attempt:
                total_jobs_processed += 1

    # Output results
    lt.append(total_migrations)
    if total_migrations > 0:
        print(total_migrations)
    else:
        print("No migrations occurred.")

# Plot results
plt.plot(lt)
plt.xlabel('Number of Jobs')
plt.ylabel('Total Migrations')
plt.title('Total Migrations vs Number of Jobs')
plt.show()
