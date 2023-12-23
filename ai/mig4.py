import random
import copy
import networkx as nx
import matplotlib.pyplot as plt
def prim_algorithm():
        first_node = random.randint(1,nodes)
        visited = set([first_node])
        # print(visited)
        edges = []

        while len(visited)<nodes:
            current_node = random.choice(list(visited))

            neighbor = random.randint(1, nodes)
            while neighbor in visited:
                neighbor = random.randint(1,nodes)

            visited.add(neighbor)
            edges.append((current_node, neighbor))

        return edges

def visualize(network):
    G = nx.Graph()

    for node in network:
        for neighbor in network[node]['neighbors']:
            G.add_edge(node, neighbor)

    pos = nx.spring_layout(G) 
    nx.draw(G, pos, with_labels=True, font_weight='bold', node_size=700, node_color='skyblue', font_size=8, edge_color='gray', linewidths=0.5)
    plt.show()

def generate_network():

    # map for storing node with capcity and neighbours
    network = {}
    #total capacity
    cap=0
    for i in range(1, nodes+1):
        #random capacity of 1-50
        capacity = random.randint(50,100)
        cap+=capacity
        network[i] = {'capacity': capacity, 'neighbors': []}

    #creating connected network using spanning tree
    edges = prim_algorithm()

    for i in edges:
        network[i[0]]['neighbors'].append(i[1])
        network[i[1]]['neighbors'].append(i[0])

    # making sure each node has one neighbour (server)
    for node in network:
        if not network[node]['neighbors']:
            # If a node has no neighbors, connect it to a random node
            random_node = random.choice(list(set(range(1, nodes+1)) - {node}))

            network[node]['neighbors'].append(random_node)
            network[random_node]['neighbors'].append(node)

    #printing network    
    print("Node Capacity  neighbours")
    for i in range(1,nodes+1):
        print(f"{i} -\t{network[i]['capacity']} - \t{network[i]['neighbors']}")
    return network,cap


def process_jobs(num_jobs):

    migrations = 0
    for _ in range(num_jobs):
        source_node = random.randint(1, len(network))
        target_node = source_node

        flag=0
        while True:
            #if the source node has capacity
            if network[source_node]['capacity']>0:
                network[source_node]['capacity']-=1
                break
            else:
                #using bfs to check neighbors and their neighbors if capacity full 
                #as it is connected graph we will always find a node if capacity available
                neighbors_q = [source_node]
                visited = []

                while neighbors_q:
                    current_node = neighbors_q.pop(0)
                    visited.append(current_node)

                    for neighbor in network[current_node]['neighbors']:
                        if neighbor not in visited:
                            neighbors_q.append(neighbor)
                            visited.append(neighbor)
                            
                            # if the neighbor has capacity
                            if network[neighbor]['capacity'] > 0:
                                target_node = neighbor
                                break
                
                if target_node != source_node:
                    # do migration
                    network[target_node]['capacity'] -= 1
                    migrations += 1
                    break

    return migrations

nodes = 10
jobs = 500
lt=[]

# note: as each server has different capacity, when num_jobs exceed the capacity, no space to assign job -> infite loop

network,jobs = generate_network()
print(f"\nTotal Capacity Possible: {jobs}")

# to visualize network
visualize(network)

#to give copy of same network by clearing existing old jobs and give new jobs in each iteration.
temp=copy.deepcopy(network)

#giving 0,50,100,150, ... jobs

print("Jobs : Migrations")
for num in range(0,jobs+1,50):
    network=copy.deepcopy(temp)
    migrations = process_jobs(num)
    lt.append(migrations)
    print(f" {num} : {migrations}")
    

#visualize migrations
plt.plot(lt)
plt.xlabel('Number of Jobs')
plt.ylabel('Total Migrations')
plt.title('Total Migrations vs Number of Jobs')
plt.show()

