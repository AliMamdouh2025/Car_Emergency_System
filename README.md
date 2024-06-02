# Car Emergency System Simulation
![image_2024-05-31_09-51-56](https://github.com/AliMamdouh2025/Car_Emergency_System/assets/144431914/f98a6170-de14-45ab-bc20-c0928da3282e)
## System description: 
### MCU1: 
- Components: Push Button - Temperature sensor - DC motor(as a fan).
- Description: 
1. MCU1 reads the state from E2PROM before 
reading temperature to act according to it as an 
abnormal state or not.
2. MCU1 reads temperature and store state as 
normal initially in E2PROM then moves the fan (DC
motor) with acceptable speed according to states
and send temperature to MCU2 using UART.
3. If the user presses the push button and the 
temperature is between 40◦C and 50◦C, MCU1 sends 
to MCU2 code as shutting down the machine using 
UART.
### MCU2: 
- Components: Servo motor - 3 Leds - potentiometer - Dc motor (as 
machine) - Buzzer.
- Description:                                                                                                                                 
1. MCU2 receives massages using UART from MCU1
and acts according it.
2. The potentiometer controls the speed of the 
machine (DC motor).
### States:
- Normal state
1. If the temperature is lower than 20◦C, MCU1 will stop fan and MCU2 will 
lighten green led.
2. Between 20◦C and 40◦C, the Fan in MCU1 is moved with speed increasing
according to increasing temperature which has max speed at 40◦C and 
MCU2 lightens yellow led.
3. Between 40◦C and 50◦C, MCU1 moves the fan with max speed and MCU2 
lights a red LED and stops the machine by pressing the push button.
4. Greater than 50◦C, MCU1 and MCU2 enter in emergency state.
- Emergency state:
1. Begin counting time.
2. MCU1 moves the fan with max speed.
3. MCU2 lightens red LED and runs buzzer.
- Abnormal state: 
1. MCU1 moves the fan with max speed.
2. MCU2 lighten red LED, open servo with 90 degrees, stop the machine and run the buzzer.
- if the emergency state is activated for 7 seconds (We use the timer with overflow mode to check on temperature 14 times with a period of 500ms) the following steps happens:
1. Writing abnormal state in E2PROM.
2. MCU1 activates the watchdog timer with the smallest time to reset MCU1.
3. MCU2 follow the abnormal condition for 5 seconds.  
