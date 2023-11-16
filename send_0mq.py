#file

import socket
import struct
import zmq
import numpy as np
import argparse
import time

def send_0mq(args):

    # Create a UDP socket
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    # Bind the socket to a specific address and port
    udp_socket.bind(('127.0.0.1', 5588))  # Use the appropriate address and port

    # ZMQ configuration for sending data to a ZMQ PUB socket
    zmq_port = args.publisher  # ZMQ server port
    context = zmq.Context()
    zmq_socket = context.socket(zmq.PUB)
    zmq_socket.bind(f"tcp://localhost:{zmq_port}")

    start_time = time.perf_counter()
    while True:
        # Receive data from the server
        for j in range(args.n_vectors):
            data, server_address = udp_socket.recvfrom(8*args.vector_length)  # Adjust buffer size as needed
            num_complex_samples = len(data) // 8  # Each complex number has 8 bytes (4 bytes for real and 4 bytes for imaginary)
            #num_complex_samples = 524288

            # Unpack the received binary data into complex numbers
            complex_data = struct.unpack(f'{num_complex_samples}f{num_complex_samples}f', data)

            # Convert complex_data to np.complex64 NumPy array
        
            if j == 0 : complex_values  = np.array([complex(complex_data[i], complex_data[i + 1]) for i in range(0,2*num_complex_samples,2)], dtype=np.complex64)
            else:
                complex_values = np.concatenate((complex_values,np.array([complex(complex_data[i], complex_data[i + 1]) for i in range(0,2*num_complex_samples,2)], dtype=np.complex64)),axis=0)
                
        # Send the complex data to the ZMQ PUB socket
        zmq_socket.send(complex_values.tobytes())
        
        # Print the complex data before sending it to the ZMQ PUB socket
        print(f"Received complex data from {server_address}: {complex_values}")

        end_time = time.perf_counter()
        print("\033[38;5;214m"+f"Publish loop time: {end_time-start_time}"+'\033[0m')
        start_time = end_time



if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Sends 0mq over to the RAN")
    parser.add_argument("--vector_length", "-v",  type=int,   default=1024, help="Vector length the model is trained for.")
    parser.add_argument("--publisher", "-p",  type=int,   default=5556, help="ZMQ Publisher Address. Default is 5556")
    parser.add_argument("--n_vectors", "-n",  type=int,   default=512, help="ZMQ Publisher Address. Default is 5556")
    args = parser.parse_args()

    send_0mq(args)
