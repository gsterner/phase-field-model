from ctypes import *
import numpy as np

slib   = 'libphasefieldmodela.so'
hlib   = CDLL(slib, mode=RTLD_GLOBAL)

delta_x = c_double(0.1)
delta_t = c_double(0.2)
time_steps = c_int(100)

array_length = 10
array_type = c_double * array_length
test_array = array_type()

n_array = np.array([[0.1, 0.5], [0.2, 0.6], [0.3, 0.7]])
n_array = n_array.astype(c_double)
n_array_p = n_array.ctypes.data_as(POINTER(c_double))

rows  = c_int(np.shape(n_array)[0])
cols = c_int(np.shape(n_array)[1])

#hlib.print_array(n_array_p, len(n_array))
#hlib.print_matrix(n_array_p, rows, cols)
hlib.model_a_integration(n_array_p, rows, cols, delta_x, delta_t, time_steps)

print('->Python<-')
print(n_array)
#print(hlib.g_func())

