from ctypes import *

slib   = 'libphasefieldmodela.so'
hlib   = CDLL(slib)

array_length = 10
array_type = c_double * array_length

test_array = array_type()

for i in range(10):
    test_array[i] = i




hlib.print_array(test_array)


print(hlib.g_func())

