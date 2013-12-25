import time as local_time
import model_a
import phase_grid


__author__ = 'gustaf'


def do_integration(start_field, delta_x, delta_t, time_steps):
    grid = phase_grid.PhaseGrid(start_field)
    print_sim_info(grid.x_size(), grid.y_size(), time_steps)
    time_one = local_time.time()
    for time in range(time_steps):
        for i in range(grid.x_size()):
            for j in range(grid.y_size()):
                grid.set_at(i, j, model_a.model_a_step(grid.at(i,j),
                                                       grid.at(i - 1,j),
                                                       grid.at(i + 1,j),
                                                       grid.at(i,j - 1),
                                                       grid.at(i,j + 1),
                                                       delta_t, delta_x))
    time_two = local_time.time()
    print('time taken: ' + str(time_two - time_one) + '\n')
    return grid.get_mesh()


def print_sim_info(x_size, y_size, time_steps):
    loop_steps = x_size * y_size * time_steps
    out_string = 'x dimension: ' + str(x_size) + ' y dimension: ' + str(y_size) + '\n' + 'time steps: ' + str(time_steps)
    out_string += ' total steps: ' + str(loop_steps) + '\n'
    print(out_string)