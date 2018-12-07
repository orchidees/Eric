# Orchidea

Assisted orchestration can be thought as the process of searching for the best combinations 
of orchestral sounds to match a target sound under specified metric and constraints. 
Although a solution to this problem has been a long-standing request from many composers, 
it remains relatively unexplored because of its high complexity, 
requiring knowledge and understanding of both mathematical formalisation and musical writing.

Orchidea is an evolution of the **Orch*** tools and performs assisted orchestration.
The design principle is the Pareto rule of 80/20: we wanted to have a tool that 
is able to solve the 80% of the problem but takes the 20% of the development time.

Orchidea performs mono-objective optimization on multi-dimensional features and r
equires a little number of parameters for orchestration. 

To compile, from root folder type:

`mkdir build`
`cd build`
`cmake ..`
`make`

For other tools for assisted orchestration see https://github.com/CarmineCella/liborchidea.

(c) 2018, www.carminecella.com/orchidea, www.ircam.fr, www.hesge.ch/hem/
 

