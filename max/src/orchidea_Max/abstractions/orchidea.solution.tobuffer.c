/**
	@file
	orchidea.solution.tobuffer.c
	
	@name 
	orchidea.solution.tobuffer
	
	@realname 
	orchidea.solution.tobuffer

	@type
	abstraction
	
	@module
	orchidea

	@author
	Daniele Ghisi
	
	@digest 
	Import orchidea solution into a buffer
	
	@description
	Receives the output of <o>orchidea.solve</o> and fills a given buffer 
	with the global connection or with a specific orchidea solution.
	
	@discussion

	@category
	orchidea solutions

	@keywords
	solution, buffer, convert, import, read

	@seealso
	orchidea.solve, orchidea.solution.totext, orchidea.solution.toroll, orchidea.solution.tofile
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method list @digest Import solution to buffer or set indices
// @description Left inlet should be connected to the leftmost output of a <o>orchidea.solve</o> object, that will
// send the need information about all the solutions (prefix, number of segments and number of solutions for each segment). <br />
// Right inlet expects either 0 (meaning: import the connection), or two numbers: a segment number and a solution number. <br />
// When the left inlet list is received, the corresponding solution to the specified segment is imported into the buffer given
// as argument, or changed via the <m>set</m> message. 


// @method int @digest Set indices
// @description See <m>list</m>.

// @method set @digest Change target buffer
// @description A <m>set</m> message followed by a symbol changes the target buffer to the newly specified symbol.


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

// @in 1 @type int/list @digest Segment and solution indices
// @description Second inlet receives a list containing the segment and solution indices. If the number 0 (as a single integer)
// is received instead, the global connection is imported (default).


// ---------------
// OUTLETS
// ---------------

// @out 0 @type bang @digest Bang when import completed
// @description A <m>bang</m> is sent through the outlet when the import operation is completed



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name buffername @optional 0 @type symbol @digest Buffer name
// @description The argument sets the buffer name that should be filled (it can then be changed via the <m>set</m> message).

// @arg 1 @name segmentnumber @optional 1 @type int @digest Segment number
// @description The optional second argument sets the segment number.  Use 0 to output the connection (default).

// @arg 2 @name solutionnumber @optional 1 @type int @digest Solution number
// @description The optional third argument sets the solution number.

