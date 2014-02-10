from ctypes import *
import numpy as np

slib   = 'libphasefieldmodela.so'
hlib   = CDLL(slib)

n_array = np.array(range(10))
n_array = n_array.astype(c_double)
n_array_p = n_array.ctypes.data_as(POINTER(c_double))

hlib.print_array(n_array_p)
print(hlib.g_func())

