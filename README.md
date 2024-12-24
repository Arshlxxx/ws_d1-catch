!!!

1. in main programming, publish the flag node ros with 2 parameters, reach and catch. defualt are both zero.

2. when control robot node has finished, modify the reach to 1.(if[reach == 0] to reach the ee point) (if[reach == 1 && catch = 1] reset the arm)

3. in joint-angle control, when reach ==1 and catch = 0 , control the claw to catch the object.
