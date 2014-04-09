import simulation_data_pb2


sim_data = simulation_data_pb2.SetupData()

sim_data.time_steps = 20

field = sim_data.Field()
#field = sim_data.phase_field.add()

in_data = [[1,2,3,11],[4,5,6,44],[7,8,9,77]]

for in_row in in_data:
    new_row = field.row.add()
    for r in in_row:
        new_row.element.append(r)

sim_data.phase_field.MergeFrom(field)

print(len(field.row))
print(len(field.row[0].element))
print(sim_data.phase_field)



f = open("simulation_setup.data", "wb")
f.write(sim_data.SerializeToString())
f.close()
