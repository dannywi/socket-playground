import socket

host = 'localhost'
#host = '127.0.0.1'
port = 12345

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_socket.bind((host, port))

server_socket.listen(1)
print(f"Server listening on {host}:{port}")

client_socket, client_address = server_socket.accept()
print(f"Client connected from:", client_address)

count = 1
while True:
    data = client_socket.recv(1)
    if not data:
        break
    print(f"{count}: Received: {data}")
    count = count + 1

client_socket.close()
server_socket.close()
