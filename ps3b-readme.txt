/**********************************************************************
 *  N-Body Simulation ps3b-readme.txt template
 **********************************************************************/

Name: Braulio Duarte
Hours to complete assignment: 5

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
In this part of the assingment I use Newtons Laws to simulate the movement
of n-bodies. I use sfml to display the results of the simluated movements of the first
four planets of our solar system, and the sun.

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
I would say Newton's Law were absolutely vital in this program.
The pairwise force, the principle of superpositin and Newton's second
law of motion. I never studied physics but these formulas were not very hard
to figure out. I guess that is the genius of Newton, to beable to explain something
so extremely complex in such a simple way.




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
The role the smart pointers play in this code is the same as in previous
assingment. My implementation was pretty straight foward, I just followed
the steps given in the assignment. first thing is to calculate the sum of the
netforce for each body, then calculate Acceleration, Velocity, and position, in
that order. I had a easy a time with this program. I codeed almost everything with
out running it, of course when I build I had some small errors. I was surprised
to find that my first implementation worked right away, aside from silly mistakes
like setting the position variables inside the class, but forgetting to set the
position of the sprite being represented by that class. 



/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
Really no help this time, a few reference searches for syntax verification.
The slide that was posted about N-body simulation was very helpful.
I used that to figure out the formula.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
No serious problems just silly things like mentioned previously.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
Fun program it would be cool if we could do it in 3d space
