import numpy as np

n=10

def ini_population(population_size, n):
    return np.array([np.random.permutation(n) for i in range(population_size)])

def find_fitness(distances,population):
    return np.array([1 / calculate_total_distance(path, distances) for path in population])

def calculate_total_distance(path, distances):
    total_distance = 0
    for i in range(len(path) - 1):
        total_distance += distances[path[i]][path[i + 1]]
    total_distance += distances[path[-1]][path[0]]  # Return to the starting city
    return total_distance

def crossover(p1, p2):
    child = [-1] * len(p1)
    print(child)
    start, end = sorted(np.random.randint(0, len(p1), 2))
    print(start,end)
    child[start:end] = p1[start:end]
    print(child)
    remaining = [item for item in p2 if item not in child]
    index = 0
    for i in range(len(child)):
        if child[i] == -1:
            child[i] = remaining[index]
            index+=1
    return np.array(child)


# print(crossover(p1,p2))
population_size=100
def ini_population(population_size, n):
    return np.array([np.random.permutation(n) for i in range(population_size)])

n=10
population = ini_population(population_size, n)
# print(population)
k=np.array([np.random.permutation(n) for i in range(population_size)])
print(np.unique(k))
# def genetic_algorithm(distances, population_size, mutation_rate, num_generations):
#     population = ini_population(population_size, n) #make population
#     for generation in range(num_generations):
#         fitness = find_fitness(distances,population)
#         print(population,fitness)
#         parents = population[np.random.choice(population_size, size=population_size, p=fitness/fitness.sum())]
#         for i in parents:
#             print(i,calculate_total_distance(i,distances))


distances = np.random.randint(1, 100, size=(n,n))

# genetic_algorithm(distances,100,0.01,1)

fitness = find_fitness(distances,population)

p=fitness/fitness.sum()
print(p)
p1=[1,2,3,4,5,6,7,8,9,10]
p2=[10,9,8,7,6,5,4,3,2,1]
child1 = crossover(p1, p2)
child2 = crossover(p2, p1)
print(child1)
print(child2)
print(np.random.rand())
print(np.random.rand())