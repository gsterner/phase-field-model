import simulation_data_pb2


sim_data = simulation_data_pb2.SetupData()

sim_data.time_steps = 20
f = open("simulation_setup.data", "wb")
f.write(sim_data.SerializeToString())
f.close()
