# Tinker - A Processor Simulator
KAUST CS294V Project by`Sadiq Albinalshaikh` `Omar Zawawi` `Kuilian Yang`, `Jihao Xin`.

### User Guide

* Test Devices

  ```shell
  cd devices
  make
  ./device_test
  ```

### TODO

The topology is designed and devices are implemented.

* **MultiportRegisterFile**, should design its control signal, currently it works same as normal register file.
* **ControlArray**: should utilize the **machine code example (add and addi).xlsx** file to define the structure and coordinate with **Issuer**. Currently it has a toy implementation & test.

