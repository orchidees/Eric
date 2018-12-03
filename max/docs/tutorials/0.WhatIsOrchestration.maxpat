{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 1,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 59.0, 79.0, 1587.0, 937.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 13.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"boxes" : [ 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-9",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 626.666626, 2116.615234, 286.0, 40.0 ],
					"style" : "",
					"text" : "Tip: follow other tutorials to learn more about static and dynamic orchestrations!"
				}

			}
, 			{
				"box" : 				{
					"autofit" : 1,
					"forceaspect" : 1,
					"id" : "obj-2",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "jit_matrix" ],
					"patching_rect" : [ 18.666668, 1836.797974, 538.999939, 319.817168 ],
					"pic" : "model.png"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-1",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 18.666668, 1763.733398, 890.333313, 50.0 ],
					"style" : "",
					"text" : "An important aspect of the current algorithm is the possibility of orchestrate sounds that evolve in time, to produce dynamic orchestrations. Before each orchestration, a segmentation step divides the original dynamic target into a set of static targets to optimize. Finally, a specific model tries to connect the generated solution into a single score."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-40",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 15.666667, 1701.733398, 893.333313, 50.0 ],
					"style" : "",
					"text" : "The current solution to this problem, as implemented in this toolbox, is based on a mono-objective optimization algorithm that is able to integrate soft symbolic constraints as cost parameters. The starting situation for the optimization is computed by means of a relaxed matching pursuit algorithm that finds the candidate orchestrations to further optimize."
				}

			}
, 			{
				"box" : 				{
					"autofit" : 1,
					"forceaspect" : 1,
					"id" : "obj-38",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "jit_matrix" ],
					"patching_rect" : [ 742.733337, 1584.799927, 166.266663, 92.370368 ],
					"pic" : "multidim.png"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-29",
					"linecount" : 6,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 15.666667, 1584.799927, 707.0, 94.0 ],
					"style" : "",
					"text" : "How an orchestra can be used to reproduce a target timbre within a compositional context? How can we find a combination of instruments that, at the same time best matches a given target sound and fits writing constraints specified by the composer?  More formally, the target-based assisted orchestration problem can be split into two joint problem:\n\n1. a combinatorial optimization problem defined on a multidimensional timbre description;\n2. a constraint solving problem on the variables of musical writing."
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-24",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 626.666626, 1431.033325, 95.0, 23.0 ],
					"style" : "",
					"text" : "loadmess start"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-22",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 626.666626, 1485.690674, 45.0, 45.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 2,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-18",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 626.666626, 1353.533447, 282.333344, 69.0 ],
					"style" : "",
					"text" : "Tip: try to play the following bell sound and then listen to a possible version for orchestra of it"
				}

			}
, 			{
				"box" : 				{
					"data" : 					{
						"clips" : [ 							{
								"filename" : "archeos_solution_0.wav",
								"filekind" : "audiofile",
								"loop" : 0,
								"content_state" : 								{
									"originallengthms" : [ 0.0 ],
									"pitchshift" : [ 1.0 ],
									"quality" : [ "basic" ],
									"pitchcorrection" : [ 0 ],
									"play" : [ 0 ],
									"mode" : [ "basic" ],
									"basictuning" : [ 440 ],
									"followglobaltempo" : [ 0 ],
									"speed" : [ 1.0 ],
									"originaltempo" : [ 120.0 ],
									"originallength" : [ 0.0, "ticks" ],
									"slurtime" : [ 0.0 ],
									"formant" : [ 1.0 ],
									"timestretch" : [ 0 ],
									"formantcorrection" : [ 0 ]
								}

							}
 ]
					}
,
					"id" : "obj-16",
					"maxclass" : "playlist~",
					"numinlets" : 1,
					"numoutlets" : 5,
					"outlettype" : [ "signal", "signal", "signal", "", "dictionary" ],
					"patching_rect" : [ 809.666626, 1427.533325, 99.333344, 30.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"data" : 					{
						"clips" : [ 							{
								"filename" : "archeos-bell.wav",
								"filekind" : "audiofile",
								"loop" : 0,
								"content_state" : 								{
									"originallengthms" : [ 0.0 ],
									"pitchshift" : [ 1.0 ],
									"quality" : [ "basic" ],
									"pitchcorrection" : [ 0 ],
									"play" : [ 0 ],
									"mode" : [ "basic" ],
									"basictuning" : [ 440 ],
									"followglobaltempo" : [ 0 ],
									"speed" : [ 1.0 ],
									"originaltempo" : [ 120.0 ],
									"originallength" : [ 0.0, "ticks" ],
									"slurtime" : [ 0.0 ],
									"formant" : [ 1.0 ],
									"timestretch" : [ 0 ],
									"formantcorrection" : [ 0 ]
								}

							}
 ]
					}
,
					"id" : "obj-11",
					"maxclass" : "playlist~",
					"numinlets" : 1,
					"numoutlets" : 5,
					"outlettype" : [ "signal", "signal", "signal", "", "dictionary" ],
					"patching_rect" : [ 626.666626, 1427.533325, 99.333344, 30.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-7",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 604.900024, 1146.190918, 304.099945, 69.0 ],
					"style" : "",
					"text" : "Note: this is not equivalent to transcription; the original sound indeed could be just a recording of a natural sound and not the recording of a score"
				}

			}
, 			{
				"box" : 				{
					"autofit" : 1,
					"forceaspect" : 1,
					"id" : "obj-6",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "jit_matrix" ],
					"patching_rect" : [ 15.666667, 1146.190918, 585.666687, 384.49981 ],
					"pic" : "induction.png"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-43",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 12.5, 525.5, 95.0, 23.0 ],
					"style" : "",
					"text" : "loadmess start"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-36",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 439.333344, 974.083679, 472.0, 55.0 ],
					"style" : "",
					"text" : "Orchids is the first version where there has been an attempt orchestrate sounds evolving in time"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-35",
					"linecount" : 8,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 274.5, 774.0, 141.666656, 127.0 ],
					"style" : "",
					"text" : "With Orchis/Orchidée, Johnatan Harvey composed his masterpiece 'Spekings' for large orchestra and live electronics"
				}

			}
, 			{
				"box" : 				{
					"autofit" : 1,
					"forceaspect" : 1,
					"id" : "obj-34",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "jit_matrix" ],
					"patching_rect" : [ 9.0, 774.0, 260.666687, 255.675197 ],
					"pic" : "Orchis.png"
				}

			}
, 			{
				"box" : 				{
					"autofit" : 1,
					"forceaspect" : 1,
					"id" : "obj-33",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "jit_matrix" ],
					"patching_rect" : [ 439.333344, 774.0, 469.666656, 192.522681 ],
					"pic" : "Orchids.png"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"id" : "obj-32",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 15.666667, 1058.466675, 120.0, 21.0 ],
					"style" : "",
					"text" : "Problem statemnt"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"id" : "obj-31",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 9.0, 429.666626, 102.0, 21.0 ],
					"style" : "",
					"text" : "A bit of history"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"id" : "obj-30",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 9.0, 119.0, 87.0, 21.0 ],
					"style" : "",
					"text" : "Introduction"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-28",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 15.666667, 1099.06665, 893.333313, 36.0 ],
					"style" : "",
					"text" : "By playing a score, you can convert (project) a representation existing in the symbolic space into a representation in the signal space. Is it possible to perform the inverse operation? Should we call this 'induction'?"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-27",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 9.0, 707.333313, 900.0, 50.0 ],
					"style" : "",
					"text" : "Since then, the problem has been researched at Ircam for more than 15 years and several outcomes have been produced: different tools (Matlab frameworks, Max/MSP interfaces, C++ standalone command line tools, etc.), several PhD thesis including G. Carpentier, D. Tardieu and P. Esling and several journal papers."
				}

			}
, 			{
				"box" : 				{
					"fontface" : 2,
					"id" : "obj-25",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 9.0, 657.999939, 900.0, 36.0 ],
					"style" : "",
					"text" : "In 2003, I presented to Ircam a proposal for a long-term research project on the subject of computer-assisted orchestration. The results of this research project lead to the prototype softwares, ‘Orchidee’."
				}

			}
, 			{
				"box" : 				{
					"fontface" : 2,
					"id" : "obj-23",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 338.666656, 559.0, 570.333374, 50.0 ],
					"style" : "",
					"text" : "Mortuos Plango, Vivos Voco is notable both within and without Harvey's career: \"it showed that IRCAM institute's apparently esoteric research programme could yield music capable of appealing to a wider audience”\n"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-21",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 338.666656, 522.0, 341.0, 21.0 ],
					"style" : "",
					"text" : "About this research, Curtis Roads commented as follows:"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-17",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 9.0, 564.0, 45.0, 45.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-4",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 163.166672, 522.0, 167.0, 40.0 ],
					"style" : "",
					"text" : "Tip: listen to the original sound used by Harvey"
				}

			}
, 			{
				"box" : 				{
					"data" : 					{
						"clips" : [ 							{
								"filename" : "WinchesterBell.wav",
								"filekind" : "audiofile",
								"loop" : 0,
								"content_state" : 								{
									"originallengthms" : [ 0.0 ],
									"pitchshift" : [ 1.0 ],
									"quality" : [ "basic" ],
									"pitchcorrection" : [ 0 ],
									"play" : [ 0 ],
									"mode" : [ "basic" ],
									"basictuning" : [ 440 ],
									"followglobaltempo" : [ 0 ],
									"speed" : [ 1.0 ],
									"originaltempo" : [ 120.0 ],
									"originallength" : [ 0.0, "ticks" ],
									"slurtime" : [ 0.0 ],
									"formant" : [ 1.0 ],
									"timestretch" : [ 0 ],
									"formantcorrection" : [ 0 ]
								}

							}
 ]
					}
,
					"id" : "obj-14",
					"maxclass" : "playlist~",
					"numinlets" : 1,
					"numoutlets" : 5,
					"outlettype" : [ "signal", "signal", "signal", "", "dictionary" ],
					"patching_rect" : [ 9.0, 522.0, 150.0, 30.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-12",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 9.0, 461.333313, 900.0, 50.0 ],
					"style" : "",
					"text" : "The first ante-litteram version of this problem has been investigated by the English composer Johnatan Harvey, in his work \"Mortuos plango, vivos voco\" (1981), where he tried to simulate the sound of a bell by a specific model of sound synthesis. It is not by chance that this problem found fertile terrain at Ircam, in Paris, where the influences of the spectralist music were very strong around that period."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-10",
					"linecount" : 5,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 9.0, 148.0, 894.0, 79.0 ],
					"style" : "",
					"text" : "The relation between signals and symbols is a central problem for acoustic signal processing. Among different kind of signals, musical signals are specific examples in which there is some information regarding the underlying symbolic structure. While an impressive amount of research has been done in this domain in the past thirty years, the symbolic processing of acoustic and musical signals is still only partially possible.\n\nWhich connections can we make between the symbolic space and the signal space?"
				}

			}
, 			{
				"box" : 				{
					"autofit" : 1,
					"forceaspect" : 1,
					"id" : "obj-8",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "jit_matrix" ],
					"patching_rect" : [ 226.833328, 239.0, 465.333344, 97.647671 ],
					"pic" : "symbols_signals.png"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-5",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 9.0, 619.999939, 900.0, 36.0 ],
					"style" : "",
					"text" : "A more systematic approach developed in 2003, when the French composer Yan Maresz proposed a more formalized statement of the problem:\n\n"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-3",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 9.0, 349.000031, 900.0, 65.0 ],
					"style" : "",
					"text" : "Assisted orchestration finds its root in this context and can be considered as a possible answer to the previous question. Generally speaking, target-based assisted orchestration can be thought as the process of searching for the best combinations of orchestral sounds to match a target sound under specified metric and constraints. Although a solution to this problem has been a long-standing request from many composers, it remains relatively unexplored because of its high complexity, requiring knowledge and understanding of both mathematical formalization and musical writing."
				}

			}
, 			{
				"box" : 				{
					"angle" : 270.0,
					"bgcolor" : [ 0.878431, 0.878431, 0.843137, 1.0 ],
					"id" : "obj-20",
					"maxclass" : "panel",
					"mode" : 0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 9.0, 62.0, 131.0, 35.235489 ],
					"proportion" : 0.39,
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.878431, 0.878431, 0.843137, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 45.0,
					"id" : "obj-67",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 142.0, 20.735489, 636.0, 57.0 ],
					"style" : "",
					"text" : "What is assisted orchestration?",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"border" : 3.0,
					"id" : "obj-15",
					"linecolor" : [ 0.011765, 0.396078, 0.752941, 1.0 ],
					"maxclass" : "live.line",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 9.0, 59.0, 894.0, 16.442019 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.878431, 0.878431, 0.843137, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 79.949177,
					"id" : "obj-19",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 9.0, 1.235489, 77.0, 96.0 ],
					"style" : "",
					"text" : "0",
					"textcolor" : [ 0.011765, 0.396078, 0.752941, 1.0 ],
					"textjustification" : 1
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-11", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-14", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-16", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-43", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "symbols_signals.png",
				"bootpath" : "~/Elementi/Dati/Elettronica/Lavori/IRCAM_17_18/Orchids/orchidea/max/media",
				"type" : "PNG ",
				"implicit" : 1
			}
, 			{
				"name" : "WinchesterBell.wav",
				"bootpath" : "~/Elementi/Dati/Elettronica/Lavori/IRCAM_17_18/Orchids/orchidea/max/media",
				"type" : "WAVE",
				"implicit" : 1
			}
, 			{
				"name" : "Orchids.png",
				"bootpath" : "~/Elementi/Dati/Elettronica/Lavori/IRCAM_17_18/Orchids/orchidea/max/media",
				"type" : "PNG ",
				"implicit" : 1
			}
, 			{
				"name" : "Orchis.png",
				"bootpath" : "~/Elementi/Dati/Elettronica/Lavori/IRCAM_17_18/Orchids/orchidea/max/media",
				"type" : "PNG ",
				"implicit" : 1
			}
, 			{
				"name" : "induction.png",
				"bootpath" : "~/Elementi/Dati/Elettronica/Lavori/IRCAM_17_18/Orchids/orchidea/max/media",
				"type" : "PNG ",
				"implicit" : 1
			}
, 			{
				"name" : "archeos-bell.wav",
				"bootpath" : "~/Elementi/Dati/Elettronica/Lavori/IRCAM_17_18/Orchids/orchidea/max/media",
				"type" : "WAVE",
				"implicit" : 1
			}
, 			{
				"name" : "archeos_solution_0.wav",
				"bootpath" : "~/Elementi/Dati/Elettronica/Lavori/IRCAM_17_18/Orchids/orchidea/max/media",
				"type" : "WAVE",
				"implicit" : 1
			}
, 			{
				"name" : "multidim.png",
				"bootpath" : "~/Elementi/Dati/Elettronica/Lavori/IRCAM_17_18/Orchids/orchidea/max/media",
				"type" : "PNG ",
				"implicit" : 1
			}
, 			{
				"name" : "model.png",
				"bootpath" : "~/Elementi/Dati/Elettronica/Lavori/IRCAM_17_18/Orchids/orchidea/max/media",
				"type" : "PNG ",
				"implicit" : 1
			}
 ],
		"autosave" : 0
	}

}
