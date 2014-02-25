from ctypes import *
import numpy as np

slib   = 'libphasefieldmodela.so'
hlib   = CDLL(slib)

array_length = 10
array_type = c_double * array_length
test_array = array_type()

n_array = np.array([[0.1, 0.5], [0.2, 0.6], [0.3, 0.7]])
n_array = n_array.astype(c_double)
n_array_p = n_array.ctypes.data_as(POINTER(c_double))

rows  = np.shape(n_array)[0]
cols = np.shape(n_array)[1]

#hlib.print_array(n_array_p, len(n_array))
hlib.print_matrix(n_array_p, rows, cols)

#print(hlib.g_func())

