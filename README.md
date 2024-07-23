This work follows a proposed exercise from the out-of-equilibrium thermodynamics subject from the Physics degree at UCM, which full solution can be found on: https://www.overleaf.com/read/bnbrcrpfxtmf#504ee0. 

This code runs a heat equation simulation in a cylindrical coordinates system. 

![image](https://github.com/user-attachments/assets/d48d9224-87d1-4402-83bd-941e4c333aa1)

It works by manually evaluating the first and second numerical derivatives needed:

![image](https://github.com/user-attachments/assets/8594882b-bc60-49d2-b973-13b359caeef1)

And by definition the derivatives can be evaluated as:

![image](https://github.com/user-attachments/assets/72f2dfcc-e6b3-4e85-81f6-34d1b4913158)

Also, entropy is studied for the 1D case (3D case is evaluated and then 1D line is outputed for exercise porpouses) which is definde as:

![image](https://github.com/user-attachments/assets/1158dc29-08de-446b-95a8-8f76e3f4a7ca)

And gradient operator in cylindrical:

![image](https://github.com/user-attachments/assets/a98cd5be-0ebe-4e5c-a851-3e417b816115)

The Overleaf documents follows a deeper study on the topic together with the results drawn from the code.

Variables used:

- The 3D mesh is defined by NZ, NR and NRHO which is the number of points used (lines 9, 10 and 11)

- deltaT defines the numerical time jump it needs t be small enough to allow a good derivation (line 70). 

- extremR, extremz and extremRHO define the units used (lines 60, 65 and 67).

- deltaR, deltaZ and deltaRHO set the jump in coordinates inbetween derivation steeps.

- T2 and tmount are used to set the boundary temperatures (lines 34 and 35).

- s sets the number of derivation steps, it could happen that if the deltaT variable is small it won't reach the thermalized state that is why this parameter plays an important role (line 101 inside for definition, not best practices)

- From lines 75 to 90 the initial conditions are first called, and from 93 to 98 the continuity conditions are applied to the matrix to mimic the cylinder this will be repeated in the loop.


Four files are generated: 

- "output1_animation_temp_cylinder_extra2.txt" Allows us to plot the thermalized state of the cylinder once the simulation ends. T=20:

![image](https://github.com/user-attachments/assets/87a81883-4955-414a-bafb-b0d912b43754)

![image](https://github.com/user-attachments/assets/7589ab4a-9f56-429d-a502-b0a60e264b43)


- "output1_animation_temp_lineal_cylinder_extra2.txt" Is responsible for outputting the evolution in time of a single 1D coordinate. T=10:

![image](https://github.com/user-attachments/assets/2e9ab7a4-4830-49bc-a615-e9d3a802fb64)

- "output1_animation_entro_lineal_cylinder_extra2.txt" Which outputs the linear evolution in time of the entropy. T=10:

![image](https://github.com/user-attachments/assets/b61eef6f-a6c8-43a1-9310-93f413f20767)

- "output1_animation_entro_total_cylinder_extra2.txt" Shows the total entropy of the 1D case. T=10:

![image](https://github.com/user-attachments/assets/40dfe413-7c1f-4243-8369-ddf8fd2ab787)

The Matlab files:

- temperature_plot.m plots the 3D case of the temperature last time steep

- entropy_plot.m plots the linear evolution and total entropy together with the linear temperature evolution

STEPS:
- Change parameters as desired
- Execute cylinder_heat_diff.c
- Execute temperature_plot.m and entropy_plot.m for plots making sure to be on the same repository as the output from the c program
