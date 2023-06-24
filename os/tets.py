import socket
import threading
import urllib.request

def handle_client(client_socket):
    request = client_socket.recv(4096).decode()
    url = request.split()[1][1:]  # Extract the URL from the request
    
    try:
        response = urllib.request.urlopen(url)
        data = response.read()
        response_headers = f"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
        client_socket.sendall(response_headers.encode() + data)
    except Exception as e:
        error_message = f"HTTP/1.1 500 Internal Server Error\r\nContent-Type: text/html\r\n\r\n"
        client_socket.sendall(error_message.encode() + str(e).encode())
    
    client_socket.close()

def start_server(host, port):
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen(5)
    print(f"Proxy server listening on {host}:{port}...")

    while True:
        client_socket, addr = server_socket.accept()
        print(f"Accepted connection from {addr[0]}:{addr[1]}")
        
        client_thread = threading.Thread(target=handle_client, args=(client_socket,))
        client_thread.start()

if __name__ == '_main_':
    host = 'localhost'
    port = 8888
    start_server(host, port)