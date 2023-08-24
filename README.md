# Dual_Programming
Repo contains C++ code for Kinematic analysis of 4 bar mechanism

The Utility and Importance of Dual-Number Programming
The advantage of formulating analysis of mechanical systems in terms of dual number is the simplicity which 
is obtained in the expressions. The expressions relating dual-angle dimensions, dual-angle displacements, dual 
velocities, and dual forces are relatively simple and easily managed. Due to this simplicity they are less prone 
to errors. However, when the resulting expression is obtained, the simple terms obtained are lost, when it must 
be expanded to yield an expression for the dual component, we get a complex equation. Considering that a 
multiplication of two duplex numbers requires three scalar multiplications and an addition, or that a division 
of two duplex numbers involves two multiplications, one subtraction and two scalar divisions. Considering 
this it is readily realized that expansion to obtain the dual component of an expression so that translations, 
linear velocities and torques can be calculated is a hard and complex process. 

The amount of work required to evaluate the dual component of even an expression of moderate or larger size 
is intimidating, arduous and there is ample opportunity for errors to occur in calculations. Symbolicmanipulator software can be helpful with the labour involved, but it is expensive and requires effort to learn 
its use. Very often the expressions which are obtained are too large to be useful for interpreting the influences 
of variables. This is particularly so in dynamics problems where expressions for the inertia loads in 
mechanisms with several links can occupy a page or more. Due to these large expressions finding required 
terms becomes difficult task.

The ability of dual-number programming very much simplifies the analysis of mechanical systems. Besides 
getting programs running quickly, the chance of errors is greatly reduced when the dual components are 
evaluated transparent to the programmer.


The DH parameter method for calculating forward kinematics of robots involves computing the transformation 
matrix for each joint of a robotic system using a set of parameters that describe the geometric relationship 
between adjacent links. The computational complexity of this method is O(n), where n is the number of joints 
in the system. Here it is assumed that calculation at each joint are less for large value of n, but in practice for 
smaller n these multiplication and addition operations becomes comparable. Thus, we can say as the number 
of joints increases, the computational complexity of the DH parameter method increases linearly.
