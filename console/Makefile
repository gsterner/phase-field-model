all:
	pkg-config --cflags protobuf
	clang++ main.cpp simulation_data.pb.cc -lprotobuf -o phasefieldmain

protoc_middleman:
	protoc -I=. --python_out=. simulation_data.proto
	protoc -I=. --cpp_out=. simulation_data.proto
