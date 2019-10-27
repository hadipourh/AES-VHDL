# AES-VHDL

VHDL Implementation of AES Algorithm

There are simple VHDL implementations of AES-128 encryption, and decryption algorithms, in this repository. This is actually my first experience in VHDL implementation! 

## What is AES? 
There might be a few people who deal with computers, and hardwares, but have not heared the name of AES, which is a famous symmetic block cipher. If you are not familiar with this algorithm, [1] is a good reference, to understand how this algorithm works. [1] is also used as the main reference for this implementation. 

## Pipelined VS Loop Unrolled
Two famous kinds of hardware implementation techniques, are pipelining, and loop-unrolling techniques. In pipelining, registers are inserted between each combinational processing element, so that each input data block can be processed simultaneously in each processing element. An overview of a pipelined implementation of AES encryption algorithm is depicted in the following shape, where the round-i depicts the i'th round of AES encryption algorithm.


![AES-pipelined-picture](/Images/pipelined_aes.svg)


The number of rounds of AES-128 encryption is 10, and an architecture implementing this cipher, is called fully pipelined, when all data blocks of 10 rounds can be processed simultaneously. For a fully pipelined implementation of AES-128, ten 128-bit data register is needed. The more data block we want to process simultaneously, the more registers, and therefore the more area we need for implementation. 

In contrast to pipelining, in a loop-unrolling technique, one, or multiple rounds of the algorithm are processed in the same clock cycle. In the smallest case of a loop-unrolled implementation of AES, which is depicted in the following shape, only one round of the algorithm is implemented as a combinational processing element, and a data register is also used to store the result obtained in the previous clock cycle.


![AES-loop-unrolled-picture](/Images/loop_unrolled_aes.svg)


Therefore the next plaintext must be entered after 10 clock cycles, while in a fully pipelined architecture, in each clock cycle one new plaintext can be entered to the process of encryption. Although pipelined architecture has more throughput than the loop-unrolled architecture, it uses more area than the loop-unrolled onw. Therefore fully pipelined architecture offer the highest performance, and is suitable for the cases which in the area is not constrained. In contrast to fully pipelined architecture, the smalles case of loop-unrolled, which is sometimes called the round based implementation, uses the lowest area, and is suitable for area constrained applications. This implementation is a loop-unrolled one, however, converting this loop-unrolled implementation, to it's pipelined alternative is not too hard. 

## Encryption
For each round of AES encryption, a different subkey is used as the round key, which is produced by the keyschedule algorithm on the fly. The following shape represents one round of keyschedule algorithm.


![keyschedule-aes](/Images/keyschedule_round_function.svg)


If someone wants to use a fixed key, it is preferable to calculate all subkeys once, and use a lookup table to store subkeys, instead of implementing keyschedule algorithm, and recalculate the subkeys frequently. However, in this repository, the keyschedule is implemented based on the loop-unrolled techniques to calculate the subkeys on the fly. 

### Architecture


![AES-Encryption-Architecture](/Images/aes_enc.svg)


### Synthesis Report (Spartan6-xc6slx75-3fgg676)
You can find the details here : [report](https://github.com/hadipourh/AES-VHDL/blob/master/AES-ENC/SynthesisReports/Spartan6/Spartan6-xc6slx75-3fgg676.txt).

#### Design Summary
</HTML>
<BODY TEXT='#000000' BGCOLOR='#FFFFFF' LINK='#0000EE' VLINK='#551A8B' ALINK='#FF0000'>
<TABLE BORDER CELLSPACING=0 CELLPADDING=3 WIDTH='100%'>
<TR ALIGN=CENTER BGCOLOR='#99CCFF'>
<TD ALIGN=CENTER COLSPAN='4'><B>aes_enc Project Status (10/25/2019 - 14:06:42)</B></TD></TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Project File:</B></TD>
<TD>aes-enc.xise</TD>
<TD BGCOLOR='#FFFF99'><b>Parser Errors:</b></TD>
<TD> No Errors </TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Module Name:</B></TD>
<TD>aes_enc</TD>
<TD BGCOLOR='#FFFF99'><B>Implementation State:</B></TD>
<TD>Synthesized</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Target Device:</B></TD>
<TD>xc6slx75-3fgg676</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Errors:</B></LI></UL></TD>
<TD>
No Errors</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Product Version:</B></TD><TD>ISE 14.7</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Warnings:</B></LI></UL></TD>
<TD ALIGN=LEFT>No Warnings</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Design Goal:</B></dif></TD>
<TD>Balanced</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Routing Results:</B></LI></UL></TD>
<TD>
&nbsp;</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Design Strategy:</B></dif></TD>
<TD><A HREF_DISABLED='Xilinx Default (unlocked)?&DataKey=Strategy'>Xilinx Default (unlocked)</A></TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Timing Constraints:</B></LI></UL></TD>
<TD>&nbsp;</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Environment:</B></dif></TD>
<TD>
<A HREF_DISABLED='C:/Users/Hosein/Documents/MyUniverse/Mathematics/E-Books/Cryptography/Alim/AES-VHDL/AES-ENC/XilinxProject/aes-enc\aes_enc_envsettings.html'>
System Settings</A>
</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Final Timing Score:</B></LI></UL></TD>
<TD>&nbsp;&nbsp;</TD>
</TR>
</TABLE>



&nbsp;<BR><TABLE BORDER CELLSPACING=0 CELLPADDING=3 WIDTH='100%'>
<TR ALIGN=CENTER BGCOLOR='#99CCFF'><TD ALIGN=CENTER COLSPAN='4'><B>Device Utilization Summary (estimated values)</B></TD><TD ALIGN=RIGHT WIDTH='10%'COLSPAN=1> <A HREF_DISABLED="?&ExpandedTable=DeviceUtilizationSummary(estimatedvalues)"><B>[-]</B></a></TD></TR>
<TR ALIGN=CENTER BGCOLOR='#FFFF99'>
<TD ALIGN=LEFT><B>Logic Utilization</B></TD><TD><B>Used</B></TD><TD><B>Available</B></TD><TD COLSPAN='2'><B>Utilization</B></TD></TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of Slice Registers</TD>
<TD ALIGN=RIGHT>264</TD>
<TD ALIGN=RIGHT>93296</TD>
<TD ALIGN=RIGHT COLSPAN='2'>0%</TD>
</TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of Slice LUTs</TD>
<TD ALIGN=RIGHT>1104</TD>
<TD ALIGN=RIGHT>46648</TD>
<TD ALIGN=RIGHT COLSPAN='2'>2%</TD>
</TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of fully used LUT-FF pairs</TD>
<TD ALIGN=RIGHT>264</TD>
<TD ALIGN=RIGHT>1104</TD>
<TD ALIGN=RIGHT COLSPAN='2'>23%</TD>
</TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of bonded IOBs</TD>
<TD ALIGN=RIGHT>387</TD>
<TD ALIGN=RIGHT>408</TD>
<TD ALIGN=RIGHT COLSPAN='2'>94%</TD>
</TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of Block RAM/FIFO</TD>
<TD ALIGN=RIGHT>1</TD>
<TD ALIGN=RIGHT>172</TD>
<TD ALIGN=RIGHT COLSPAN='2'>0%</TD>
</TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of BUFG/BUFGCTRLs</TD>
<TD ALIGN=RIGHT>1</TD>
<TD ALIGN=RIGHT>16</TD>
<TD ALIGN=RIGHT COLSPAN='2'>6%</TD>
</TR>
</TABLE>
</BODY></HTML>

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
According to the synthesis report produced by the ISE Designe Suite, The minimum clock period for our implementation when Spartan6-xc6slx75-3fgg676 is used as the target device, is 5.813 nano seconds. Therefore the throughput is equal to `128 bits/(10*5.813 ns) = 2.2 Gb/s`.

### Synthesis Report (Artix7-xc7a200t-3-ffg1156)
You can find the details here: [report](https://github.com/hadipourh/AES-VHDL/blob/master/AES-ENC/SynthesisReports/Artix7/Artix7-xc7a200t-3-ffg1156.txt)

### Design Summary

<BODY TEXT='#000000' BGCOLOR='#FFFFFF' LINK='#0000EE' VLINK='#551A8B' ALINK='#FF0000'>
<TABLE BORDER CELLSPACING=0 CELLPADDING=3 WIDTH='100%'>
<TR ALIGN=CENTER BGCOLOR='#99CCFF'>
<TD ALIGN=CENTER COLSPAN='4'><B>aes_enc Project Status (10/25/2019 - 14:06:42)</B></TD></TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Project File:</B></TD>
<TD>aes-enc.xise</TD>
<TD BGCOLOR='#FFFF99'><b>Parser Errors:</b></TD>
<TD> No Errors </TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Module Name:</B></TD>
<TD>aes_enc</TD>
<TD BGCOLOR='#FFFF99'><B>Implementation State:</B></TD>
<TD>Synthesized</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Target Device:</B></TD>
<TD>xc7a200t-3ffg1156</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Errors:</B></LI></UL></TD>
<TD>
No Errors</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Product Version:</B></TD><TD>ISE 14.7</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Warnings:</B></LI></UL></TD>
<TD ALIGN=LEFT>No Warnings</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Design Goal:</B></dif></TD>
<TD>Balanced</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Routing Results:</B></LI></UL></TD>
<TD>
&nbsp;</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Design Strategy:</B></dif></TD>
<TD><A HREF_DISABLED='Xilinx Default (unlocked)?&DataKey=Strategy'>Xilinx Default (unlocked)</A></TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Timing Constraints:</B></LI></UL></TD>
<TD>&nbsp;</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Environment:</B></dif></TD>
<TD>
<A HREF_DISABLED='C:/Users/Hosein/Documents/MyUniverse/Mathematics/E-Books/Cryptography/Alim/AES-VHDL/AES-ENC/XilinxProject/aes-enc\aes_enc_envsettings.html'>
System Settings</A>
</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Final Timing Score:</B></LI></UL></TD>
<TD>&nbsp;&nbsp;</TD>
</TR>
</TABLE>



&nbsp;<BR><TABLE BORDER CELLSPACING=0 CELLPADDING=3 WIDTH='100%'>
<TR ALIGN=CENTER BGCOLOR='#99CCFF'><TD ALIGN=CENTER COLSPAN='4'><B>Device Utilization Summary (estimated values)</B></TD><TD ALIGN=RIGHT WIDTH='10%'COLSPAN=1> <A HREF_DISABLED="?&ExpandedTable=DeviceUtilizationSummary(estimatedvalues)"><B>[-]</B></a></TD></TR>
<TR ALIGN=CENTER BGCOLOR='#FFFF99'>
<TD ALIGN=LEFT><B>Logic Utilization</B></TD><TD><B>Used</B></TD><TD><B>Available</B></TD><TD COLSPAN='2'><B>Utilization</B></TD></TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of Slice Registers</TD>
<TD ALIGN=RIGHT>264</TD>
<TD ALIGN=RIGHT>269200</TD>
<TD ALIGN=RIGHT COLSPAN='2'>0%</TD>
</TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of Slice LUTs</TD>
<TD ALIGN=RIGHT>1104</TD>
<TD ALIGN=RIGHT>134600</TD>
<TD ALIGN=RIGHT COLSPAN='2'>0%</TD>
</TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of fully used LUT-FF pairs</TD>
<TD ALIGN=RIGHT>264</TD>
<TD ALIGN=RIGHT>1104</TD>
<TD ALIGN=RIGHT COLSPAN='2'>23%</TD>
</TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of bonded IOBs</TD>
<TD ALIGN=RIGHT>387</TD>
<TD ALIGN=RIGHT>500</TD>
<TD ALIGN=RIGHT COLSPAN='2'>77%</TD>
</TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of Block RAM/FIFO</TD>
<TD ALIGN=RIGHT>1</TD>
<TD ALIGN=RIGHT>365</TD>
<TD ALIGN=RIGHT COLSPAN='2'>0%</TD>
</TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of BUFG/BUFGCTRLs</TD>
<TD ALIGN=RIGHT>1</TD>
<TD ALIGN=RIGHT>32</TD>
<TD ALIGN=RIGHT COLSPAN='2'>3%</TD>
</TR>
</TABLE>


<br><center><b>Date Generated:</b> 10/25/2019 - 18:40:06</center>
</BODY></HTML>

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
According to the synthesis report produced by the ISE Designe Suite, The minimum clock period for our implementation when Artix7-xc7a200t-3-ffg1156 is used as the target device, is 3.397 nano seconds. Therefore the throughput is equal to `128 bits/(10*3.397 ns) = 3.77 Gb/s`.

### Synthesis Report (Zynq-xc7z100-2-ffg1156)
You can find the details here: [report](https://github.com/hadipourh/AES-VHDL/blob/master/AES-ENC/SynthesisReports/Zynq/Zynq-xc7z100-2-ffg1156.txt)

### Design Summary

<BODY TEXT='#000000' BGCOLOR='#FFFFFF' LINK='#0000EE' VLINK='#551A8B' ALINK='#FF0000'>
<TABLE BORDER CELLSPACING=0 CELLPADDING=3 WIDTH='100%'>
<TR ALIGN=CENTER BGCOLOR='#99CCFF'>
<TD ALIGN=CENTER COLSPAN='4'><B>aes_enc Project Status (10/25/2019 - 14:06:42)</B></TD></TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Project File:</B></TD>
<TD>aes-enc.xise</TD>
<TD BGCOLOR='#FFFF99'><b>Parser Errors:</b></TD>
<TD> No Errors </TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Module Name:</B></TD>
<TD>aes_enc</TD>
<TD BGCOLOR='#FFFF99'><B>Implementation State:</B></TD>
<TD>Synthesized</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Target Device:</B></TD>
<TD>xc7z100-2ffg1156</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Errors:</B></LI></UL></TD>
<TD>
No Errors</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Product Version:</B></TD><TD>ISE 14.7</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Warnings:</B></LI></UL></TD>
<TD ALIGN=LEFT>No Warnings</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Design Goal:</B></dif></TD>
<TD>Balanced</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Routing Results:</B></LI></UL></TD>
<TD>
&nbsp;</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Design Strategy:</B></dif></TD>
<TD><A HREF_DISABLED='Xilinx Default (unlocked)?&DataKey=Strategy'>Xilinx Default (unlocked)</A></TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Timing Constraints:</B></LI></UL></TD>
<TD>&nbsp;</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Environment:</B></dif></TD>
<TD>
<A HREF_DISABLED='C:/Users/Hosein/Documents/MyUniverse/Mathematics/E-Books/Cryptography/Alim/AES-VHDL/AES-ENC/XilinxProject/aes-enc\aes_enc_envsettings.html'>
System Settings</A>
</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Final Timing Score:</B></LI></UL></TD>
<TD>&nbsp;&nbsp;</TD>
</TR>
</TABLE>



&nbsp;<BR><TABLE BORDER CELLSPACING=0 CELLPADDING=3 WIDTH='100%'>
<TR ALIGN=CENTER BGCOLOR='#99CCFF'><TD ALIGN=CENTER COLSPAN='4'><B>Device Utilization Summary (estimated values)</B></TD><TD ALIGN=RIGHT WIDTH='10%'COLSPAN=1> <A HREF_DISABLED="?&ExpandedTable=DeviceUtilizationSummary(estimatedvalues)"><B>[-]</B></a></TD></TR>
<TR ALIGN=CENTER BGCOLOR='#FFFF99'>
<TD ALIGN=LEFT><B>Logic Utilization</B></TD><TD><B>Used</B></TD><TD><B>Available</B></TD><TD COLSPAN='2'><B>Utilization</B></TD></TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of Slice Registers</TD>
<TD ALIGN=RIGHT>264</TD>
<TD ALIGN=RIGHT>554800</TD>
<TD ALIGN=RIGHT COLSPAN='2'>0%</TD>
</TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of Slice LUTs</TD>
<TD ALIGN=RIGHT>1104</TD>
<TD ALIGN=RIGHT>277400</TD>
<TD ALIGN=RIGHT COLSPAN='2'>0%</TD>
</TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of fully used LUT-FF pairs</TD>
<TD ALIGN=RIGHT>264</TD>
<TD ALIGN=RIGHT>1104</TD>
<TD ALIGN=RIGHT COLSPAN='2'>23%</TD>
</TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of bonded IOBs</TD>
<TD ALIGN=RIGHT>387</TD>
<TD ALIGN=RIGHT>400</TD>
<TD ALIGN=RIGHT COLSPAN='2'>96%</TD>
</TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of Block RAM/FIFO</TD>
<TD ALIGN=RIGHT>1</TD>
<TD ALIGN=RIGHT>755</TD>
<TD ALIGN=RIGHT COLSPAN='2'>0%</TD>
</TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of BUFG/BUFGCTRLs</TD>
<TD ALIGN=RIGHT>1</TD>
<TD ALIGN=RIGHT>32</TD>
<TD ALIGN=RIGHT COLSPAN='2'>3%</TD>
</TR>
</TABLE>
<br><center><b>Date Generated:</b> 10/25/2019 - 19:12:53</center>
</BODY></HTML>

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
According to the synthesis report produced by the ISE Designe Suite, The minimum clock period for our implementation when Zynq-xc7z100-2-ffg1156 is used as the target device, is 3.369 nano seconds. Therefore the throughput is equal to `128 bits/(10*3.369 ns) = 3.80 Gb/s`. Note that the throughput for a fully pipelined design operating in ECB mode is: `128 bits/(3.369 ns) = 38 Gb/s`!

### Simulation
To verify the correctness of the encryption's implementation, a testbech has been prepared, which in the equality of the obtained ciphertext with the refernce values taken from [1], is checked for two different plaintexts, and keys. As you can see in the following picture, this implemetnation passes the verification.


![AES-Encryption Simulation](/Images/capture_simulation_aes_enc.png)


## Decryption
To implement the decryption algorithm of AES-128, one must invert the SubBytes, ShiftRows, and MixColumns operations. Let's depict the inverse of SubBytes, ShiftRows, and MixColumns operations, by InvSubBytes, InvShiftRows, and InvMixColumns respectively. While the area required to implement InvSubBytes, and InvShiftRows, are the same as the area required for implementation of SubBytes, and ShiftRows respectively, the hardware implementation of InvMixColumns is a challenging problem, since it's matrix is more dense than the MixColumn's matrix, and therefore, uses more area than the MixColumns. In this implemenation we use a technique, taken from page 55 of [1], to overcome this problem. According to this technique, InvMixColumns can be implemented as a simple preprocessing step, followed by the MixColumn step.

### Architecture


![AES-Decryption Architecture](/Images/aes_dec.svg)


### Synthesis Report (Spartan6-xc6slx75-3fgg676)

You can find the details here: [report](https://github.com/hadipourh/AES-VHDL/blob/master/AES-DEC/SynthesisReports/Spartan6/Spartan6-xc6slx75-3fgg676.txt)
#### Design Summary

<BODY TEXT='#000000' BGCOLOR='#FFFFFF' LINK='#0000EE' VLINK='#551A8B' ALINK='#FF0000'>
<TABLE BORDER CELLSPACING=0 CELLPADDING=3 WIDTH='100%'>
<TR ALIGN=CENTER BGCOLOR='#99CCFF'>
<TD ALIGN=CENTER COLSPAN='4'><B>aes_dec Project Status (10/25/2019 - 18:30:19)</B></TD></TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Project File:</B></TD>
<TD>aes-dec.xise</TD>
<TD BGCOLOR='#FFFF99'><b>Parser Errors:</b></TD>
<TD> No Errors </TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Module Name:</B></TD>
<TD>aes_dec</TD>
<TD BGCOLOR='#FFFF99'><B>Implementation State:</B></TD>
<TD>Synthesized</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Target Device:</B></TD>
<TD>xc6slx75-3fgg676</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Errors:</B></LI></UL></TD>
<TD>
No Errors</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Product Version:</B></TD><TD>ISE 14.7</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Warnings:</B></LI></UL></TD>
<TD ALIGN=LEFT>No Warnings</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Design Goal:</B></dif></TD>
<TD>Balanced</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Routing Results:</B></LI></UL></TD>
<TD>
&nbsp;</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Design Strategy:</B></dif></TD>
<TD><A HREF_DISABLED='Xilinx Default (unlocked)?&DataKey=Strategy'>Xilinx Default (unlocked)</A></TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Timing Constraints:</B></LI></UL></TD>
<TD>&nbsp;</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Environment:</B></dif></TD>
<TD>
<A HREF_DISABLED='C:/Users/Hosein/Documents/MyUniverse/Mathematics/E-Books/Cryptography/Alim/AES-VHDL/AES-DEC/XilinxProject/aes-dec\aes_dec_envsettings.html'>
System Settings</A>
</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Final Timing Score:</B></LI></UL></TD>
<TD>&nbsp;&nbsp;</TD>
</TR>
</TABLE>



&nbsp;<BR><TABLE BORDER CELLSPACING=0 CELLPADDING=3 WIDTH='100%'>
<TR ALIGN=CENTER BGCOLOR='#99CCFF'><TD ALIGN=CENTER COLSPAN='4'><B>Device Utilization Summary (estimated values)</B></TD><TD ALIGN=RIGHT WIDTH='10%'COLSPAN=1> <A HREF_DISABLED="?&ExpandedTable=DeviceUtilizationSummary(estimatedvalues)"><B>[-]</B></a></TD></TR>
<TR ALIGN=CENTER BGCOLOR='#FFFF99'>
<TD ALIGN=LEFT><B>Logic Utilization</B></TD><TD><B>Used</B></TD><TD><B>Available</B></TD><TD COLSPAN='2'><B>Utilization</B></TD></TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of Slice Registers</TD>
<TD ALIGN=RIGHT>264</TD>
<TD ALIGN=RIGHT>93296</TD>
<TD ALIGN=RIGHT COLSPAN='2'>0%</TD>
</TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of Slice LUTs</TD>
<TD ALIGN=RIGHT>1474</TD>
<TD ALIGN=RIGHT>46648</TD>
<TD ALIGN=RIGHT COLSPAN='2'>3%</TD>
</TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of fully used LUT-FF pairs</TD>
<TD ALIGN=RIGHT>260</TD>
<TD ALIGN=RIGHT>1478</TD>
<TD ALIGN=RIGHT COLSPAN='2'>17%</TD>
</TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of bonded IOBs</TD>
<TD ALIGN=RIGHT>387</TD>
<TD ALIGN=RIGHT>408</TD>
<TD ALIGN=RIGHT COLSPAN='2'>94%</TD>
</TR>
<TR ALIGN=RIGHT><TD ALIGN=LEFT>Number of BUFG/BUFGCTRLs</TD>
<TD ALIGN=RIGHT>1</TD>
<TD ALIGN=RIGHT>16</TD>
<TD ALIGN=RIGHT COLSPAN='2'>6%</TD>
</TR>
</TABLE>
<br><center><b>Date Generated:</b> 10/25/2019 - 18:30:19</center>
</BODY></HTML>

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
According to the synthesis report produced by the ISE Designe Suite, The minimum clock period for our implementation when Spartan6-xc6slx75-3fgg676 is used as the target device, is 6.740 nano seconds. Therefore the throughput is equal to 
`128 bits/(10*6.740 ns) = 1.90 Gb/s.`

### Synthesis Report (Artix7-xc7a200t-3-ffg1156)
You can find the details here: [report](https://github.com/hadipourh/AES-VHDL/blob/master/AES-DEC/SynthesisReports/Artix7/Artix7-xc7a200t-3-ffg1156.txt)

#### Design Summary

<BODY TEXT='#000000' BGCOLOR='#FFFFFF' LINK='#0000EE' VLINK='#551A8B' ALINK='#FF0000'>
<TABLE BORDER CELLSPACING=0 CELLPADDING=3 WIDTH='100%'>
<TR ALIGN=CENTER BGCOLOR='#99CCFF'>
<TD ALIGN=CENTER COLSPAN='4'><B>aes_dec Project Status (10/25/2019 - 18:44:28)</B></TD></TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Project File:</B></TD>
<TD>aes-dec.xise</TD>
<TD BGCOLOR='#FFFF99'><b>Parser Errors:</b></TD>
<TD> No Errors </TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Module Name:</B></TD>
<TD>aes_dec</TD>
<TD BGCOLOR='#FFFF99'><B>Implementation State:</B></TD>
<TD>Synthesized</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Target Device:</B></TD>
<TD>xc7a200t-3ffg1156</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Errors:</B></LI></UL></TD>
<TD>
No Errors</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Product Version:</B></TD><TD>ISE 14.7</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Warnings:</B></LI></UL></TD>
<TD ALIGN=LEFT>No Warnings</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Design Goal:</B></dif></TD>
<TD>Balanced</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Routing Results:</B></LI></UL></TD>
<TD>
&nbsp;</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Design Strategy:</B></dif></TD>
<TD><A HREF_DISABLED='Xilinx Default (unlocked)?&DataKey=Strategy'>Xilinx Default (unlocked)</A></TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Timing Constraints:</B></LI></UL></TD>
<TD>&nbsp;</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Environment:</B></dif></TD>
<TD>
<A HREF_DISABLED='C:/Users/Hosein/Documents/MyUniverse/Mathematics/E-Books/Cryptography/Alim/AES-VHDL/AES-DEC/XilinxProject/aes-dec\aes_dec_envsettings.html'>
System Settings</A>
</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Final Timing Score:</B></LI></UL></TD>
<TD>&nbsp;&nbsp;</TD>
</TR>
</TABLE>



&nbsp;<BR><TABLE BORDER CELLSPACING=0 CELLPADDING=3 WIDTH='100%'>
<TR ALIGN=CENTER BGCOLOR='#99CCFF'><TD ALIGN=CENTER width='98%'><B>Device Utilization Summary (estimated values)</B></TD><TD ALIGN=RIGHT width='2%'> <A HREF_DISABLED="?&CollapsedTable=DeviceUtilizationSummary(estimatedvalues)"><B>[+]</B></a></TD></TR></TABLE></TR>
</TR>
</TR>
</TR>
</TR>
</TR>
</TABLE>
<br><center><b>Date Generated:</b> 10/25/2019 - 18:44:28</center>
</BODY></HTML>

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
According to the synthesis report produced by the ISE Designe Suite, The minimum clock period for our implementation when Artix7-xc7a200t-3-ffg1156 is used as the target device, is 3.940 nano seconds. Therefore the throughput is equal to `128 bits/(10*3.940 ns) = 3.25 Gb/s`. 

### Synthesis Report (Zynq-xc7z100-2-ffg1156)
You can find the details here: [report](https://github.com/hadipourh/AES-VHDL/blob/master/AES-DEC/SynthesisReports/Zynq/Zynq-xc7z100-2-ffg1156.txt)

#### Design Summary

<BODY TEXT='#000000' BGCOLOR='#FFFFFF' LINK='#0000EE' VLINK='#551A8B' ALINK='#FF0000'>
<TABLE BORDER CELLSPACING=0 CELLPADDING=3 WIDTH='100%'>
<TR ALIGN=CENTER BGCOLOR='#99CCFF'>
<TD ALIGN=CENTER COLSPAN='4'><B>aes_dec Project Status (10/25/2019 - 19:03:28)</B></TD></TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Project File:</B></TD>
<TD>aes-dec.xise</TD>
<TD BGCOLOR='#FFFF99'><b>Parser Errors:</b></TD>
<TD> No Errors </TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Module Name:</B></TD>
<TD>aes_dec</TD>
<TD BGCOLOR='#FFFF99'><B>Implementation State:</B></TD>
<TD>Synthesized</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Target Device:</B></TD>
<TD>xc7z100-2ffg1156</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Errors:</B></LI></UL></TD>
<TD>
No Errors</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Product Version:</B></TD><TD>ISE 14.7</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Warnings:</B></LI></UL></TD>
<TD ALIGN=LEFT>No Warnings</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Design Goal:</B></dif></TD>
<TD>Balanced</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Routing Results:</B></LI></UL></TD>
<TD>
&nbsp;</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Design Strategy:</B></dif></TD>
<TD><A HREF_DISABLED='Xilinx Default (unlocked)?&DataKey=Strategy'>Xilinx Default (unlocked)</A></TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Timing Constraints:</B></LI></UL></TD>
<TD>&nbsp;</TD>
</TR>
<TR ALIGN=LEFT>
<TD BGCOLOR='#FFFF99'><B>Environment:</B></dif></TD>
<TD>
<A HREF_DISABLED='C:/Users/Hosein/Documents/MyUniverse/Mathematics/E-Books/Cryptography/Alim/AES-VHDL/AES-DEC/XilinxProject/aes-dec\aes_dec_envsettings.html'>
System Settings</A>
</TD>
<TD BGCOLOR='#FFFF99'><UL><LI><B>Final Timing Score:</B></LI></UL></TD>
<TD>&nbsp;&nbsp;</TD>
</TR>
</TABLE>



&nbsp;<BR><TABLE BORDER CELLSPACING=0 CELLPADDING=3 WIDTH='100%'>
<TR ALIGN=CENTER BGCOLOR='#99CCFF'><TD ALIGN=CENTER width='98%'><B>Device Utilization Summary (estimated values)</B></TD><TD ALIGN=RIGHT width='2%'> <A HREF_DISABLED="?&CollapsedTable=DeviceUtilizationSummary(estimatedvalues)"><B>[+]</B></a></TD></TR></TABLE></TR>
</TR>
</TR>
</TR>
</TR>
</TR>
</TABLE>
<br><center><b>Date Generated:</b> 10/25/2019 - 19:09:35</center>
</BODY></HTML>

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

According to the synthesis report produced by the ISE Designe Suite, The minimum clock period for our implementation when Zynq-xc7z100-2-ffg1156 is used as the target device, is 3.324 nano seconds. Therefore the throughput is equal to `128 bits/(10*3.324 ns) = 3.85 Gb/s`. 

### Simulation
To verify the correctness of the decryption's implementation, a testbech has been prepared, which in the equality of the obtained plaintext with the refernce values taken from [1], is checked for two different ciphertexts, and keys. As you can see in the following picture, this implemetnation passes the verification, and it works correctly.


![AES-Decryption Simulation](/Images/capture_simulation_aes_dec.png)


## References


[1] [The Design of Rijndael: AES - The Advanced Encryption Standard] (https://www.springer.com/gp/book/9783540425809)
