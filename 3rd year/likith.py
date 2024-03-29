class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []

    def add_edge(self, u, v, w):
        self.graph.append([u, v, w])

    def kruskal(self):
        result = []
        self.graph = sorted(self.graph, key=lambda item: item[2])
        parent = [i for i in range(self.V)]

        def find(i):
            if parent[i] == i:
                return i
            return find(parent[i])

        i, e = 0, 0
        while e < self.V - 1:
            u, v, w = self.graph[i]
            i = i + 1
            x = find(u)
            y = find(v)
            if x != y:
                e = e + 1
                result.append([u, v, w])
                parent[y] = x

        print("Edges in the Minimum Spanning Tree:")
        for u, v, w in result:
            print(f"{u} - {v} : {w}")


# Example usage:
g = Graph(4)
g.add_edge(0, 1, 10)
g.add_edge(0, 2, 6)
g.add_edge(0, 3, 5)
g.add_edge(1, 3, 15)
g.add_edge(2, 3, 4)

g.kruskal()
