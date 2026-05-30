# ESP32 ECCM Data Link Simulation
A hardware-software co-design prototype demonstrating flexible, connectionless  communication links resilient to high-power channel interference. Built using two ESP32 microcontrollers communicating via raw, low-overhead frames, and a third to simulate the expected jamming behaviour.

## System Architecture
* **Transmitter Node:** Simulates a deployedsensor or asset constantly serialising packed binary state structures
* **Receiver Node (Gateway):** Executes real-time LQM, processes data streams, and triggers frequency-hopping routines when the signal is sufficiently degraded
* **Python Telemetry Cache:** Intercepts hardware UART payloads from the Gateway Node via a local FTDI serial connection, translating the raw byte-stream

## Key Core Technical Implementations
* **Packed Binary Serialisation:** Low-overhead data transport using custom C structures to enforce a strict frame layout without string formatting overhead
* **Connectionless Transport Medium:**  Bypassing traditional Wi-Fi connection states by utilising Espressif's raw ESP-NOW protocol
* **Dynamic Channel Hopping:** Programmed automatic node re-synchronisation to switch to using an embedded state machine to the next pre-determined Wi-Fi frequency.
