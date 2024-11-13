# Actuator_Control
This repo controls various actuator controls

# 1)Actuator_Keyboard_input_3_positions.ino
working on a project to control a motorized actuator based on throttle voltage input and serial commands. 
The actuator moves between specific positions (e.g., 38mm, 42mm, and 50mm), and the program reads the voltage from an analog input to determine the current position of the actuator. 
Then, based on the received serial commands, it adjusts the actuator's position by extending or contracting it.
# Alogorithm
1)Reading the throttle voltage and understanding the current actuator length
2)Mapping throttle voltage (3.36V - 4.25V) to (38mm – 50mm).
3)Three defined cases to maintain the actuator at 3 defined positions, which will be taken as keyboard input from the user 
4)For every input from the user, the algorithm will check the desired user input and compare it with the current stroke length.
      •Current stroke length < desired stroke length | extend (t – ms)
        (t ms- calculated based on the speed of actuator at that load)
      •Current stroke length > desired stroke length | contract (t -ms)
        (t ms- calculated based on the speed of actuator at that load)
