import socket
import time

host = 'localhost'
#host = '127.0.0.1'
port = 12345

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client_socket.connect((host, port))

for i in range(5):
    data = b'\x10'
    # send data
    client_socket.send(data)
    time.sleep(1)

client_socket.close()
