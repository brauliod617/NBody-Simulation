# N-Body Simulation

The N-Body Simulation uses Newton's Law of Universal 
Gravitation to predict the motion of N objects.

## Video Demonstration 
[![NBody Simulation](https://i.ibb.co/dDWfKz2/https-i-ytimg-com-vi-X2stq-Af7-OGc-maxresdefault.jpg)](https://youtu.be/X2stqAf7OGc "NBody Simulation")
## Running the program

The program takes two input parameters: <br/>
1.) A float representing the length of the simulation in seconds <br/>
2.) A float representing the number of seconds each step of the simulation will represent

The program also reads a txt file from standard input giving information about the bodies to be simulated <br/>
Here is an example of what one of these files will look like <br/>
![Text file describing bodies](/bodies_description.png)
<br/>

* Where:<br/> 
    * n = number of bodies 
    * radius= radius of the space in which bodies are contained
    * position= current position of body in a x,y axis
    * velocity = current velocity of body
    * mass = mass of body

<br/>
To run the program, first use make command to build executables

```
$ make
```
 
followed by

```
$ ./NBodySimulation < nbody/planets.txt 31536000 1000 
```
 to simulate one year of motion where each step represents 1000 seconds
 

## What is the science behind it all?

To generate the N-Body Simulation some of Isaac Newton's laws are used. <br/>

1. Newton's Law of Universal Gravitation (1686) <br/>
    "Newton's law of gravity states that every particle in the universe
     attracts every other particle with the force that is directly proportional
     to the product of their masses and inversely proportional to the square
     of the distance between them." <br/>
     https://www.engineering.com/Blogs/tabid/3207/ArticleID/219/Newtons-Law-of-Gravity.aspx
    
    
![Image of Newton's Law of Universal Gravitation](/unigrav.png)

Where G is the gravitational constant <br/>
G = 6.67 x 10 ^ -11 Nm^2 / kg^2 <br/>
m1 and m2 are the masses of the object <br/>
and r is the distance between the centers of their masses <br/>
   
2. Newton's Second Law of Motion (1686): <br/>
    "The acceleration of an object as produced by a net force is 
    directly proportional to the magnitude of the net force, in 
    the same direction as the net force, and inversely proportional 
    to the mass of the object." <br/>
    https://www.physicsclassroom.com/class/newtlaws/Lesson-3/Newton-s-Second-Law

    a = Fnet / m <br/>
    Inversely <br/>
    Fnet = ma <br/>
    
    Where: <br/>
    a = acceleration <br/>
    Fnet = net force <br/>
    M = mass <br/>
    
    Net force on each particle is the superposition of the forces imparted by
    each of the other particles

    Fnet = f1 + f2 + ... + fn 

### Simulating the universe

1. Calculate and set the x,y net force of each body using Pairwise Gravitational Forces
   calculation 
   
   ![Pairwise Gravitaional Forces](/pwgfc.png)
   
2. Calculate and set the x,y acceleration of each body
    a = Fnet / m
    
3. Calculate and set the x,y velocity of each body
    v = v + t * a
    where  t is time interval
   
4. Calculate and set new x,y position of each body
    pos = pos + t * v    


A while loop is used to iterate through the simulation
at each iteration the 4 calculations are made and in the 
final calculate the new position of the bodies are set.