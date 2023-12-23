import random

def generate_random_network(num_nodes, max_capacity):
    """
    Generate a random network of computer systems with specified maximum capacity.

    Parameters:
    - num_nodes: Number of computer systems in the network.
    - max_capacity: Maximum capacity of each computer system.

    Returns:
    - network: Dictionary representing the network connections.
    """
    network = {}
    for i in range(1, num_nodes + 1):
        network[i] = {'capacity': max_capacity, 'neighbors': set()}

    # Generate random connections between nodes
    for node in network:
        num_neighbors = random.randint(1, min(3, num_nodes - 1))  # Randomly choose 1 to 3 neighbors
        available_nodes = list(set(range(1, num_nodes + 1)) - {node})  # Exclude the current node
        network[node]['neighbors'] = random.sample(available_nodes, min(num_neighbors, len(available_nodes)))

    return network

def process_jobs(network, num_jobs):
    """
    Simulate job submissions and migrations in the network.

    Parameters:
    - network: Dictionary representing the network connections.
    - num_jobs: Number of jobs to be submitted.

    Returns:
    - migrations: Total number of migrations performed.
    """
    migrations = 0

    for _ in range(num_jobs):
        # Simulate job submission to a random node with available capacity
        available_nodes = [node for node in network if network[node]['capacity'] > 0]
        
        # Sort nodes based on available capacity (descending order)
        sorted_nodes = sorted(available_nodes, key=lambda x: network[x]['capacity'], reverse=True)
        
        if not sorted_nodes:
        # Randomly choose a node from the sorted list
            source_node = random.randint(1, len(network))
        else:
            source_node=random.choice(sorted_nodes)
        # Simulate job migration
        target_node = source_node
        flag = 0
        while True:
            if flag == 1:
                source_node = random.randint(1, len(network))
                target_node = source_node
                flag = 0

            # Check if the source node has capacity
            if network[source_node]['capacity'] > 0:
                network[source_node]['capacity'] -= 1
                break
            else:
                # Check neighbors and neighbors of neighbors recursively
                neighbors_to_check = [source_node]
                visited = set()

                while neighbors_to_check:
                    current_node = neighbors_to_check.pop(0)
                    visited.add(current_node)

                    for neighbor in network[current_node]['neighbors']:
                        if neighbor not in visited and neighbor not in neighbors_to_check:
                            neighbors_to_check.append(neighbor)

                            # Check if the neighbor has capacity
                            if network[neighbor]['capacity'] > 0:
                                target_node = neighbor
                                break

                if target_node != source_node:
                    # Perform migration
                    network[target_node]['capacity'] -= 1
                    migrations += 1
                    break
                else:
                    flag = 1

    return migrations

# Example usage:
num_nodes = 10
max_capacity = 5
num_jobs = 45

network = generate_random_network(num_nodes, max_capacity)
total_migrations = process_jobs(network, num_jobs)

print("Total Migrations:", total_migrations)
