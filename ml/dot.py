import numpy as np

i=np.array([[3],[2]])
w1=np.array([[0.63,0.43],[0.41,0.15],[0.5,0.1]])
#number of inputs = number of weights for each neuron
#number of weight sets = number of neurons 
#each column in weight column = weight lines linked to that neuron = number of inputs
# each row in output = output of that neuron.
# print(i.shape)
# print(w1.shape)
# print(np.dot(w1,i))


#suppose if there are 4 inputs and 3 hidden neuron which means 4x3 matrix will be weight matrix
a = np.array([[1, 2, 3]])  # 1x3 matrix
b = np.array([[1, 2, 3, 4],
              [5, 6, 7, 8],
              [9, 10, 11, 12]])  # 3x4 matrix

c = np.dot(a.T, b)  # dot product
# or c = a.T @ b

print(c)