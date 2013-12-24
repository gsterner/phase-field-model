import model_a
import phase_grid

__author__ = 'gustaf'


def do_integration(start_field, delta_x, delta_t, time_steps):
    grid = phase_grid.PhaseGrid(start_field)
    for time in range(time_steps):
        for i in range(grid.x_size()):
            for j in range(grid.y_size()):
                grid.set_at(i, j, model_a.model_a_step(grid.at(i,j),
                                                       grid.at(i - 1,j),
                                                       grid.at(i + 1,j),
                                                       grid.at(i,j - 1),
                                                       grid.at(i,j + 1),
                                                       delta_t, delta_x))
    return grid.get_mesh()