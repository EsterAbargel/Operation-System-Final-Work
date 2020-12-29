We have two binaries: Server and Client, therefore we have two make both of them (on different Terminals):
- Run: make client
  It will output a binary named client
- Run: make server
  It will output a binary named server

First we have to run the server: ./server
It will print the pid of the server, to be used by client
It will wait for signals from client

To run client we we have to specify the pid of the server, the type of the signal (2 or 10) and the amount of signals we want to send to the server:
./client <server_pid> <signal_type> <signal_amount>

After running the client, we can stop the server by pressing Enter, then it will print how many signals were received, we will notice that the recieved amount is not the same as the amount specified in client!

We can run client multiple time while server still waiting for signals


