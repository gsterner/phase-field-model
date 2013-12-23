from encodings.punycode import selective_find

__author__ = 'gustaf'


class PhaseGrid():
    def __init__(self, phi_mesh):
        self.x_length = phi_mesh.shape[0]
        self.y_length = phi_mesh.shape[1]
        self.phi = phi_mesh

    def at(self, x_index, y_index):
        return self.phi[self._get_x_index(x_index)][self._get_y_index(y_index)]

    def _get_x_index(self, x_index):
        if -1 < x_index < self.x_length:
            return x_index
        elif x_index < 0:
            return self.x_length + x_index
        else:
            return x_index - self.x_length

    def _get_y_index(self, y_index):
        if -1 < y_index < self.y_length:
            return y_index
        elif y_index < 0:
            return self.y_length + y_index
        else:
            return y_index - self.y_length
