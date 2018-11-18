/**
	@file
	orchidea.solution.toroll.c
	
	@name 
	orchidea.solution.toroll
	
	@realname 
	orchidea.solution.toroll

	@type
	abstraction
	
	@module
	orchidea

	@author
	Daniele Ghisi
	
	@digest 
	Import orchidea solutions into a <o>bach.roll</o>
	
	@description
	Receives the output of <o>orchidea.solve</o> and fills a given <o>bach.roll</o>
	object with the global connection or with a set of orchidea solutions.
	
	@discussion
	This module only work if the bach library is installed (www.bachproject.net).

	@category

	@keywords
	solution, roll, score, import, symbolic, read

	@seealso
	orchidea.solve, orchidea.solution.totext, orchidea.solution.tobuffer, orchidea.solution.tofile
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method list/llll @digest Import solution to buffer or set which solutions are to be imported
// @description Left inlet should be connected to the leftmost output of a <o>orchidea.solve</o> object, that will
// send the need information about all the solutions (prefix, number of segments and number of solutions for each segment). <br />
// Right inlet expects either 0 (meaning: import the connection), or a single number <m>N</m> (meaning: import all 
// solutions for the <m>N</m>-th segment), or two numbers: a segment number and a solution number (in order to import
// a single solution). <br />
// The bach range syntax is also supported; e.g. use <b>3 (4 5 7)</b> to import 
// solutions 4, 5 and 7 for segment 3; use <b>3 ((5 10))</b>
// to import solutions 5 through 10 for the same segment. 


// @method int @digest Set segment
// @description See <m>list</m>.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

// (none)

}

// ---------------
// INLETS
// ---------------

// @in 0 @type list @digest Solution information
// @description The first inlet receives the solution information coming from <o>orchidea.solve</o>'s first outlet.

// @in 1 @type int/list/llll @digest Segment and solution indices
// @description Second inlet receives a list containing either a single number (the segment whose solutions
// should be displayed; 0 = global connection, default), or two numbers (the segment number and the solution number),
// or a bach range syntax (see <m>list</m>).


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest Solution(s) in <o>bach.roll</o> form
// @description The outlet outputs the specified solution(s) in <o>bach.roll</o>'s <m>llll</m> form



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name segmentnumber @optional 1 @type int @digest Segment number
// @description The optional first argument sets the segment number. Use 0 to output the connection (default).

// @arg 1 @name solutionnumber @optional 1 @type int @digest Solution number
// @description The optional second argument sets the solution number.

