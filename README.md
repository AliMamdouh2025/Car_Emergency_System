# Car Emergency System Simulation
![image_2024-05-31_09-51-56](https://github.com/AliMamdouh2025/Car_Emergency_System/assets/144431914/f98a6170-de14-45ab-bc20-c0928da3282e)
## System description: 
### MCU1: 
- Components: Push Button - Temperature sensor - DC motor (as a 
fan).
- Description: 
1. MCU1 reads the state from E2PROM before 
reading temperature to act according to it as an 
abnormal state or not.
2. MCU1 reads temperature and store state as 
normal initially in E2PROM then moves the fan (DC
motor) with acceptable speed according to states
and send temperature to MCU2 using UART.
