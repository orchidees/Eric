/**
	@file
	orchidea.solution.totext.c
	
	@name 
	orchidea.solution.totext
	
	@realname 
	orchidea.solution.totext

	@type
	abstraction
	
	@module
	orchidea

	@author
	Daniele Ghisi
	
	@digest 
	Import orchidea solution into a text object
	
	@description
	Receives the output of <o>orchidea.solve</o> and fills a given text object 
	with the global connection or with a specific orchidea solution, in textual form.
	
	@discussion

	@category

	@keywords
	solution, text, convert, import, read

	@seealso
	orchidea.solve, orchidea.solution.tobuffer, orchidea.solution.toroll, orchidea.solution.tofile
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method list @digest Import solution to text
// @description Left inlet should be connected to the leftmost output of a <o>orchidea.solve</o> object, that will
// send the need information about all the solutions (prefix, number of segments and number of solutions for each segment).
// When such list is received, the solutions for the desired segment (see <m>int</m> message) 
// is imported into the text object connected to the object's outlet.


// @method int @digest Set segment
// @description An integer in the right inlet sets the segment for which the solutions should be imported (0 = global connection, default).



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

// @in 1 @type int @digest Segment number
// @description Second inlet receives the number of the segment whose solutions are to be imported. If the number 0 (as a single integer)
// is received instead, the global connection is imported (default).


// ---------------
// OUTLETS
// ---------------

// @out 0 @type bang @digest Messages for text object
// @description The outlet should be connected to a <o>text</o> object (it will output the proper read message in order to fill it).



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name segmentnumber @optional 1 @type int @digest Segment number
// @description The argument sets the the number of the segment whose solutions are to be imported. If the number 0 (as a single integer)
// is received instead, the global connection is imported (default).
