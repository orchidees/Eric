/**
	@file
	orchidea.solution.tofile.c
	
	@name 
	orchidea.solution.tofile
	
	@realname 
	orchidea.solution.tofile

	@type
	abstraction
	
	@module
	orchidea

	@author
	Daniele Ghisi
	
	@digest 
	Get filenames for a specific orchidea solution
	
	@description
	Receives the output of <o>orchidea.solve</o> and returns the audio and text
	filenames of the solutions.
	
	@discussion

	@category

	@keywords
	solution, text, file, obtain, filename, audiofile

	@seealso
	orchidea.solve, orchidea.solution.totext, orchidea.solution.toroll, orchidea.solution.tobuffer
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method list @digest Import solution to buffer or set indices
// @description Left inlet should be connected to the leftmost output of a <o>orchidea.solve</o> object, that will
// send the need information about all the solutions (prefix, number of segments and number of solutions for each segment). <br />
// Right inlet expects either 0 (meaning: get files for the connection, default), or a single number (meaning: get all files for a given segment)
// or two numbers: a segment number and a solution number (meaning: get a specific solution for a specific segment). <br />
// When the left inlet list is received, the full path to the text and audio files is output respectively from right and left inlet.


// @method int @digest Set indices
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

// @in 1 @type int/list @digest Segment and solution indices
// @description Second inlet receives a list containing the segment and solution indices. If the number 0 (as a single integer)
// is received instead, the global connection is imported (default). If a single number greater than 0 is received, it is considered
// as a segment number and all solutions for that segment are output.


// ---------------
// OUTLETS
// ---------------

// @out 0 @type bang @digest Audio File(s)
// @description Outputs the solution audio file(s)

// @out 1 @type bang @digest Text File
// @description Outputs the solution text file (this file will contain information on all solutions for a given segment, or for the connection)



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name segmentnumber @optional 1 @type int @digest Segment number
// @description The optional second argument sets the segment number. Use 0 to output the connection (default).

// @arg 1 @name solutionnumber @optional 1 @type int @digest Solution number
// @description The optional third argument sets the solution number.

