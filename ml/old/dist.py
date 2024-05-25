from scipy.spatial.distance import cdist
import numpy as np

# Define the points for each cluster
C1_set1 = np.array([(158,58), (158,59), (158,63)])
C2_set1 = np.array([(158,58), (163,64), (158,63)])

C1_set2 = np.array([(160,64), (163,64), (165,61)])
C2_set2 = np.array([(158,59), (160,64), (165,61)])

# Calculate the cohesion for each cluster
cohesion_C1_set1 = cdist(C1_set1, C1_set1, metric='euclidean')
cohesion_C1_set2 = np.mean(cdist(C1_set2, C1_set2, metric='euclidean'))

cohesion_C2_set1 = np.mean(cdist(C2_set1, C2_set1, metric='euclidean'))
cohesion_C2_set2 = np.mean(cdist(C2_set2, C2_set2, metric='euclidean'))

# Calculate the separation between clusters
separation_C1_C2 = np.mean(cdist(C1_set1, C2_set1, metric='euclidean'))

print("Cohesion for C1_set1:", cohesion_C1_set1)
print("Cohesion for C1_set2:", cohesion_C1_set2)
print("Cohesion for C2_set1:", cohesion_C2_set1)
print("Cohesion for C2_set2:", cohesion_C2_set2)
print("Separation between C1 and C2:", separation_C1_C2)
