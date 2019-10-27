# AES-VHDL
VHDL Implementation of AES Algorithm

There are a naive VHDL implementation of AES-128 encryption and decryption algorithms in this repository. The following softwares have been used to write the codes, and synthesize them:

* [Sigasi](https://www.sigasi.com/) : For writing and edditing the codes
* [ISE Design Suite](https://www.xilinx.com/products/design-tools/ise-design-suite.html) : For synthesis the codes and doing simulations

## What is AES? 
There might be a few people who deal with computers, and hardwares, but have not heared the name of AES which is a famous symmetic block cipher, but If you are not familiar with this algorithm, I invite you to take a look at [1], to understand how this algorithm works. [1] is also used as the main reference for this implementation. 

## Pipelined VS Loop Unrolled
Two famous kinds of implementation techniques, are pipelined, and loop-unrolled techniques. In pipelining, registers are inserted between each combinational processing element, so that data block can be processed simultaneously in each processing element. An overview of a pipelined implementation of AES encryption algorithm is depicted in the following shape, where the round-i depicts the i'th round of AES encryption algorithm. The architecture is called fully pipelined when all data blocks of 10 rounds can be processed simultaneously. In other words for a fully pipelined implementation of the AES-128, ten 128-bit data registers are used. 
[ASE-pipelined-picture]

The more data block we want to process simultaneously, the more registers, and therefore the more area is required. In contrast to pipelined, in a loop-unrolled technique, one, or multiple rounds of the algorithm are processed in the same clock cycle. In the smallest case of a loop-unrolled implementation of AES, only one round of the algorithm is implemented as a combinational processing element, and a data register is also used to store the result obtained in the previous clock cycle. Therefore 10 clock cycles it would take to obtain a ciphertext in each encryption, since the number of rounds of AES-128 is 10. An overview of this technique which is also used for our implementation is depicted in the following shape. Although this technique needs more clock cycles to obtain the ciphertext, but it uses less area than the pipelined implementation. By the way, converting the code of this loop-unrolled implementation, to it's pipelined alternative is pretty easy. 

## Encryption

### Architecture

![AES-Encryption-Architecture](/Images/aes_enc.svg)

### Synthesis Report (Spartan6-xc6slx75-3fgg676)
You can find the details here : [report](https://github.com/hadipourh/AES-VHDL/blob/master/AES-ENC/SynthesisReports/Spartan6/Spartan6-xc6slx75-3fgg676.txt). 
```
Timing Summary:
---------------
Speed Grade: -3

   Minimum period: 5.813ns (Maximum Frequency: 172.031MHz)
   Minimum input arrival time before clock: 4.823ns
   Maximum output required time after clock: 5.588ns
   Maximum combinational path delay: No path found
```
### Throughput
According to the synthesis report produced by the ISE Designe Suite, The minimum clock period for our implementation when Spartan6-xc6slx75-3fgg676 is used as the target device, is 5.813 nano seconds. Therefore the throughput is equal to 128 bits/(10*5.813 ns) = 2.2 Gb/s.

### Synthesis Report (Artix7-xc7a200t-3-ffg1156)
You can find the details here: [report](https://github.com/hadipourh/AES-VHDL/blob/master/AES-ENC/SynthesisReports/Artix7/Artix7-xc7a200t-3-ffg1156.txt)
```
Timing Summary:
---------------
Speed Grade: -3

   Minimum period: 3.397ns (Maximum Frequency: 294.366MHz)
   Minimum input arrival time before clock: 1.649ns
   Maximum output required time after clock: 1.669ns
   Maximum combinational path delay: No path found
```
### Throughput
According to the synthesis report produced by the ISE Designe Suite, The minimum clock period for our implementation when Artix7-xc7a200t-3-ffg1156 is used as the target device, is 3.397 nano seconds. Therefore the throughput is equal to 128 bits/(10*3.397 ns) = 3.77 Gb/s.

### Synthesis Report (Zynq-xc7z100-2-ffg1156)
You can find the details here: [report](https://github.com/hadipourh/AES-VHDL/blob/master/AES-ENC/SynthesisReports/Zynq/Zynq-xc7z100-2-ffg1156.txt)
```
Timing Summary:
---------------
Speed Grade: -2

   Minimum period: 3.369ns (Maximum Frequency: 296.789MHz)
   Minimum input arrival time before clock: 1.653ns
   Maximum output required time after clock: 1.540ns
   Maximum combinational path delay: No path found
```
### Throughput
According to the synthesis report produced by the ISE Designe Suite, The minimum clock period for our implementation when Zynq-xc7z100-2-ffg1156 is used as the target device, is 3.369 nano seconds. Therefore the throughput is equal to 128 bits/(10*3.369 ns) = 3.80 Gb/s. Note that the throughput for a fully pipelined design operating in ECB mode is: 128 bits/(3.369 ns) = 38 Gb/s!

### Simulation
To verify the correctness of the encryption's implementation, a testbech has been prepared, which in the equality of the obtained ciphertext with the refernce values taken from [1], is checked for two different plaintexts, and keys. As you can see in the following picture, this implemetnation passes the verification.

![AES-Encryption Simulation](/Images/capture_simulation_aes_enc.png)

## Decryption
To implement the decryption algorithm of AES-128, one must invert the SubBytes, ShiftRows, and MixColumns operations. Let's depict the inverse of SubBytes, ShiftRows, and MixColumns operations, by InvSubBytes, InvShiftRows, and InvMixColumns respectively. While the area needed for implementation of InvSubBytes, and InvShiftRows, are the same as the area required for implementation of SubBytes, and ShiftRows respectively, the hardware implementation of InvMixColumns is a challenging problem, since it's matrix is more dense than the MixColumn's matrix, and therefore, uses more area than the MixColumns. In this implemenation we use a technique, taken from [1], to overcome this problem. 

### Architecture

![AES-Decryption Architecture](/Images/aes_dec.svg)
### Synthesis Report (Spartan6-xc6slx75-3fgg676)

You can find the details here: [report](https://github.com/hadipourh/AES-VHDL/blob/master/AES-DEC/SynthesisReports/Spartan6/Spartan6-xc6slx75-3fgg676.txt)
```
Timing Summary:
---------------
Speed Grade: -3

   Minimum period: 6.740ns (Maximum Frequency: 148.361MHz)
   Minimum input arrival time before clock: 4.726ns
   Maximum output required time after clock: 5.102ns
   Maximum combinational path delay: No path found
```
### Throughput
According to the synthesis report produced by the ISE Designe Suite, The minimum clock period for our implementation when Spartan6-xc6slx75-3fgg676 is used as the target device, is 6.740 nano seconds. Therefore the throughput is equal to 128 bits/(10*6.740 ns) = 1.90 Gb/s. 

### Synthesis Report (Artix7-xc7a200t-3-ffg1156)
You can find the details here: [report](https://github.com/hadipourh/AES-VHDL/blob/master/AES-DEC/SynthesisReports/Artix7/Artix7-xc7a200t-3-ffg1156.txt)
```
Timing Summary:
---------------
Speed Grade: -3

   Minimum period: 3.940ns (Maximum Frequency: 253.790MHz)
   Minimum input arrival time before clock: 1.177ns
   Maximum output required time after clock: 1.356ns
   Maximum combinational path delay: No path found
```
### Throughput
According to the synthesis report produced by the ISE Designe Suite, The minimum clock period for our implementation when Artix7-xc7a200t-3-ffg1156 is used as the target device, is 3.940 nano seconds. Therefore the throughput is equal to 128 bits/(10*3.940 ns) = 3.25 Gb/s. 

### Synthesis Report (Zynq-xc7z100-2-ffg1156)
You can find the details here: [report](https://github.com/hadipourh/AES-VHDL/blob/master/AES-DEC/SynthesisReports/Zynq/Zynq-xc7z100-2-ffg1156.txt)
```
Timing Summary:
---------------
Speed Grade: -2

   Minimum period: 3.324ns (Maximum Frequency: 300.806MHz)
   Minimum input arrival time before clock: 1.185ns
   Maximum output required time after clock: 1.243ns
   Maximum combinational path delay: No path found
```
### Throughput
According to the synthesis report produced by the ISE Designe Suite, The minimum clock period for our implementation when Zynq-xc7z100-2-ffg1156 is used as the target device, is 3.324 nano seconds. Therefore the throughput is equal to 128 bits/(10*3.324 ns) = 3.85 Gb/s. 

### Simulation
To verify the correctness of the encryption's implementation, a testbech has been prepared, which in the equality of the obtained plaintext with the refernce values taken from [1], is checked for two different ciphertexts, and keys. As you can see in the following picture, this implemetnation passes the verification, and it works correctly.

![AES-Decryption Simulation](/Images/capture_simulation_aes_dec.png)

## References
[1] [The Design of Rijndael: AES - The Advanced Encryption Standard] (https://www.springer.com/gp/book/9783540425809)
