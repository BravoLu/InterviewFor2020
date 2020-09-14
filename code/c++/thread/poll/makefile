all:server client
server:server.o
	g++ -g -o server server.o 
client:client.o
	g++ -g -o client client.o 
server.o:server.cpp 
	g++ -g -c server.cpp 
clean:all
	rm all
