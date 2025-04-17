
# Alex-CG2111A

This repository contains all the code for **Alex**, a remote controlable robot developed using an Arduino, Raspberry Pi, and secure TLS communication in CG2111A course. It is organized into four main components:

- `Alex/`: Arduino code (to be flashed from the Raspberry Pi)
- `Controller/`: Raspberry Pi controller code (communicates with Arduino via serial)
- `TLS Client/`: TLS-based client running on a laptop to send commands
- `TLS Server/`: TLS-based server running on the Raspberry Pi

---

## 📁 Folder Structure

### 🔌 `Alex/`
This folder contains the Arduino sketch (`.ino` file) that controls the motors, servos, and other onboard components of Alex.

**Setup Instructions:**
- Flash the `.ino` file to the **Arduino UNO** from the **Raspberry Pi** using the Arduino IDE or `arduino-cli`.

---

### 🖥️ `Controller/`
The controller is the middle layer that receives commands (via TLS) and forwards them to the Arduino via serial.

**Setup Instructions:**
1. Make sure your **Raspberry Pi** has GCC installed.
2. SSH into the Raspberry Pi (or use VNC):
   ```bash
   ssh <rpi-username>@<rpi-ip-address>
   ```
3. Compile the controller code:
   ```bash
   g++ alex-pi.cpp serial.cpp serialize.cpp -pthread -o alex-pi
   ```
4. Run the controller:
   ```bash
   ./alex-pi
   ```

---

### 🔐 `TLS Client/`
This client sends commands from your **laptop** to the Raspberry Pi securely via TLS.

**Setup Instructions:**
1. Make sure you have OpenSSL installed and the required TLS credentials ready.
2. Compile the client:
   ```bash
   g++ tls-alex-client.cpp make_tls_client.cpp tls_client_lib.cpp tls_pthread.cpp tls_common_lib.cpp -pthread -lssl -lcrypto -o tls-alex-client
   ```
3. Run the client:
   ```bash
   ./tls-alex-client <rpi-ip-address> <port-number>
   ```

---

### 🔒 `TLS Server/`
The server receives secure TLS commands from the client and forwards them to the controller on the Raspberry Pi.

**Setup Instructions:**
1. Ensure OpenSSL is installed and TLS credentials are available.
2. Compile the server on the Raspberry Pi:
   ```bash
   g++ tls-alex-server.cpp tls_server_lib.cpp tls_pthread.cpp make_tls_server.cpp tls_common_lib.cpp serial.cpp serialize.cpp -pthread -lssl -lcrypto -o tls-alex-server
   ```
3. Run the server:
   ```bash
   ./tls-alex-server
   ```

---

## 🔁 System Workflow

1. **Laptop TLS Client** sends a command.
2. **Raspberry Pi TLS Server** receives it.
3. The **Controller** program forwards the command to the **Arduino**.
4. **Arduino** executes the command to move Alex.

---

## ✅ Requirements

- Raspberry Pi with serial access to Arduino
- Arduino UNO
- OpenSSL (on laptop and RPi)
- TLS certificates and keys
- GCC and g++ compilers
- SSH or VNC access to RPi
