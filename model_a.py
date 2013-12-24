__author__ = 'gustaf'


def model_a_step(phi_curr,
                 phi_prec,
                 phi_secc,
                 phi_up,
                 phi_down,
                 delta_t,
                 delta_x):
    return phi_curr\
           + delta_t / (delta_x * delta_x) * laplace(phi_curr, phi_prec, phi_secc, phi_up, phi_down)


def laplace(phi_curr,
            phi_prec,
            phi_secc,
            phi_up,
            phi_down):
    return phi_secc + phi_prec + phi_up + phi_down - 4 * phi_curr
