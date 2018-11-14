{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 4,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 100.0, 100.0, 699.0, 662.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 5.0, 5.0 ],
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
		"showrootpatcherontab" : 0,
		"showontab" : 0,
		"boxes" : [ 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 299.0, 205.0, 214.0, 22.0 ],
					"saved_object_attributes" : 					{
						"filename" : "helpstarter.js",
						"parameter_enable" : 0
					}
,
					"style" : "",
					"text" : "js helpstarter.js orchidea.solution.toroll"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-2",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 4,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 100.0, 126.0, 699.0, 636.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
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
						"showontab" : 1,
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-28",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "bang", "" ],
									"patching_rect" : [ 214.0, 224.0, 31.0, 23.0 ],
									"style" : "",
									"text" : "t b l"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-26",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 15.359528, 228.0, 61.0, 23.0 ],
									"saved_object_attributes" : 									{
										"embed" : 0,
										"versionnumber" : 80001
									}
,
									"style" : "",
									"text" : "bach.reg"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"id" : "obj-24",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 460.640472, 244.5, 200.359528, 40.0 ],
									"style" : "",
									"text" : "Import solutions 5 through 10 for 3rd segment"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-23",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 391.5, 253.0, 64.0, 23.0 ],
									"style" : "",
									"text" : "3 ((5 10))"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"id" : "obj-22",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 445.0, 211.0, 200.359528, 40.0 ],
									"style" : "",
									"text" : "Import 4th, 5th and 7th solution for 3rd segment"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-21",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 376.5, 219.5, 59.0, 23.0 ],
									"style" : "",
									"text" : "3 (4 5 7)"
								}

							}
, 							{
								"box" : 								{
									"attr" : "vzoom",
									"id" : "obj-20",
									"maxclass" : "attrui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 495.359528, 303.0, 150.0, 23.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-17",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 199.0, 292.0, 65.0, 23.0 ],
									"style" : "",
									"text" : "exportom"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-11",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 123.0, 292.0, 70.0, 23.0 ],
									"style" : "",
									"text" : "exportmidi"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-10",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 42.0, 292.0, 73.0, 23.0 ],
									"style" : "",
									"text" : "exportpwgl"
								}

							}
, 							{
								"box" : 								{
									"bwcompatibility" : 80001,
									"clefs" : [ "G", "G", "G", "G", "G", "G", "F", "F", "F", "F", "G", "G", "Tenor", "F", "F", "G", "G", "Alto", "Alto", "F", "F", "G8vb", "G8vb" ],
									"defaultnoteslots" : [ "null" ],
									"enharmonictable" : [ "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default" ],
									"fontface" : 0,
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"hidevoices" : [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ],
									"id" : "obj-18",
									"keys" : [ "C", "C", "C", "C", "C", "C", "C", "C", "C", "C", "C", "C", "C", "C", "C", "C", "C", "C", "C", "C", "C", "C", "C" ],
									"loop" : [ 0.0, 1000.0 ],
									"maxclass" : "bach.roll",
									"midichannels" : [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 ],
									"numinlets" : 6,
									"numoutlets" : 8,
									"numparts" : [ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ],
									"numvoices" : 23,
									"out" : "nnnnnnn",
									"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
									"patching_rect" : [ 15.359528, 334.0, 635.0, 288.833374 ],
									"pitcheditrange" : [ "null" ],
									"stafflines" : [ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 ],
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"versionnumber" : 80001,
									"voicenames" : [ "Fl", "Fl", "Ob", "Ob", "ClBb", "ClBb", "Bn", "Bn", "Hn", "Hn", "TpC", "TpC", "Tbn", "Tbn", "BTb", "Vn", "Vn", "Va", "Va", "Vc", "Vc", "Cb", "Cb" ],
									"voicespacing" : [ 0.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0 ],
									"vzoom" : 100.0,
									"whole_roll_data_0000000000" : [ "roll", "[", "slotinfo", "[", 1, "[", "name", "velocity envelope", "]", "[", "type", "function", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "auto", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 2, "[", "name", "slot function", "]", "[", "type", "function", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "grid", "]", "[", "ysnap", "]", "[", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "auto", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 3, "[", "name", "slot intlist", "]", "[", "type", "intlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 4, "[", "name", "slot floatlist", "]", "[", "type", "floatlist", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 5, "[", "name", "slot int", "]", "[", "type", "int", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 6, "[", "name", "slot float", "]", "[", "type", "float", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 7, "[", "name", "slot text", "]", "[", "type", "text", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 8, "[", "name", "slot filelist", "]", "[", "type", "filelist", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 9, "[", "name", "slot spat", "]", "[", "type", "spat", "]", "[", "key", 0, "]", "[", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, "]", "[", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "]", "[", "representation", "]", "[", "temporalmode", "relative", "]", "[", "extend", 0, "]", "[", "width", "auto", "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 10, "[", "name", "slot llll", "]", "[", "type", "llll", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 11, "[", "name", "slot 11", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 12, "[", "name", "slot 12", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 13, "[", "name", "slot 13", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 14, "[", "name", "slot 14", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 15, "[", "name", "slot 15", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 16, "[", "name", "slot 16", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 17, "[", "name", "slot 17", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 18, "[", "name", "slot 18", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 19, "[", "name", "slot 19", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 20, "[", "name", "dynamics", "]", "[", "type", "dynamics", "]", "[", "key", "d", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079083008, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 21, "[", "name", "lyrics", "]", "[", "type", "text", "]", "[", "key", "l", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 0, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 22, "[", "name", "articulations", "]", "[", "type", "articulations", "]", "[", "key", "a", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 23, "[", "name", "notehead", "]", "[", "type", "notehead", "]", "[", "key", "h", "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 24, "[", "name", "slot 24", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 25, "[", "name", "slot 25", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 26, "[", "name", "slot 26", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 27, "[", "name", "slot 27", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 28, "[", "name", "slot 28", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 29, "[", "name", "slot 29", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "[", 30, "[", "name", "slot 30", "]", "[", "type", "none", "]", "[", "key", 0, "]", "[", "temporalmode", "none", "]", "[", "extend", 0, "]", "[", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, "]", "[", "height", "auto", "]", "[", "copywhensplit", 1, "]", "[", "access", "readandwrite", "]", "[", "follownotehead", 0, "]", "]", "]", "[", "commands", "[", 1, "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "[", 2, "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "[", 3, "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "[", 4, "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "[", 5, "[", "note", "note", "]", "[", "chord", "chord", "]", "[", "rest", "rest", "]", "[", "key", 0, "]", "]", "]", "[", "groups", "]", "[", "markers", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3119864244, 1079457498, "seg1.sol1", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1083174215, "seg1.sol64", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4123168604, 1084080168, "seg1.sol79", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1084534307, "seg1.sol49", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1546188227, 1084938511, "seg1.sol72", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085297553, "seg1.sol3", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085499665, "seg1.sol72", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1085701767, "seg1.sol47", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 171798692, 1085891991, "seg1.sol56", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1086082209, "seg1.sol90", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1086272419, "seg1.sol46", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1086387745, "seg1.sol33", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1086488798, "seg1.sol76", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1086577958, "seg1.sol79", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1086673075, "seg1.sol75", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1086774118, "seg1.sol68", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1086898956, "seg1.sol78", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087005952, "seg1.sol78", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087095116, "seg1.sol69", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "seg1.sol57", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087285337, "seg1.sol56", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087379852, "seg1.sol92", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087427404, "seg1.sol75", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087477932, "seg1.sol58", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087528454, "seg1.sol19", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087576012, "seg1.sol4", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087629510, "seg1.sol75", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087680038, "seg1.sol7", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087733536, "seg1.sol83", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087787033, "seg1.sol40", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087849452, "seg1.sol77", "none", "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087923750, "seg1.sol16", "none", "]", "]", "[", "midichannels", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, "]", "[", "articulationinfo", "]", "[", "noteheadinfo", "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1083174215, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086071808, "_x_x_x_x_bach_float64_x_x_x_x_", 790273982, 1082888925, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1546188227, 1084938511, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085943808, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085297553, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993728, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085499665, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086302464, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1086272419, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085917696, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1086577958, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085867008, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1086898956, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086302464, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087095116, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085815296, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085867008, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087379852, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085866496, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087427404, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085808384, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087477932, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993728, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087528454, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085833728, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087629510, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737472, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087733536, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737216, "_x_x_x_x_bach_float64_x_x_x_x_", 34359738, 1082793771, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087787033, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086338944, "_x_x_x_x_bach_float64_x_x_x_x_", 1821066134, 1083079143, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087849452, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086301696, "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1083319275, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087923750, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4123168604, 1085336296, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1546188227, 1084938511, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085866240, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087629510, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085774592, "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1083794841, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087849452, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085867008, "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1083319275, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", 0, "]", "[", 0, "]", "[", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3119864244, 1079457498, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 1065151889, 1082983989, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1083174215, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763840, "_x_x_x_x_bach_float64_x_x_x_x_", 790273982, 1082888925, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4123168604, 1084080168, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737472, "_x_x_x_x_bach_float64_x_x_x_x_", 3264175145, 1083699701, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1084534307, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1546188227, 1084938511, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085866240, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085297553, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993728, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085499665, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085610240, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 171798692, 1085891991, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085866496, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1086082209, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763840, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1086272419, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085815040, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1086387745, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1086488798, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507328, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1086673075, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085866752, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1086898956, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085789184, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087005952, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086302208, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086004992, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087427404, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087477932, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086071808, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087576012, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087629510, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1083794841, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087733536, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737216, "_x_x_x_x_bach_float64_x_x_x_x_", 34359738, 1082793771, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087787033, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968896, "_x_x_x_x_bach_float64_x_x_x_x_", 1821066134, 1083079143, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087849452, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1083319275, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3119864244, 1079457498, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763840, "_x_x_x_x_bach_float64_x_x_x_x_", 1065151889, 1082983989, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1546188227, 1084938511, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763840, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085499665, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086068480, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 171798692, 1085891991, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085866496, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1086082209, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086093824, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087787033, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, "_x_x_x_x_bach_float64_x_x_x_x_", 1821066134, 1083079143, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3119864244, 1079457498, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085021696, "_x_x_x_x_bach_float64_x_x_x_x_", 1065151889, 1082983989, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1083174215, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686272, "_x_x_x_x_bach_float64_x_x_x_x_", 790273982, 1082888925, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1084534307, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085175296, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1546188227, 1084938511, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085559296, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085297553, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085866752, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085499665, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1085701767, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084969984, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 171798692, 1085891991, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993728, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1086082209, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085866752, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1086272419, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1083652147, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1086387745, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085918464, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1086577958, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085559040, "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1083699681, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1086673075, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085866752, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1086774118, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686784, "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083079096, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1086898956, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085867008, "_x_x_x_x_bach_float64_x_x_x_x_", 2061584302, 1083699732, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087095116, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686272, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087285337, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507840, "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1083699681, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087379852, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085892096, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087427404, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085867008, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087477932, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085226496, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087528454, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085021184, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087576012, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085275648, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087629510, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085774592, "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1083794841, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087733536, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558528, "_x_x_x_x_bach_float64_x_x_x_x_", 34359738, 1082793771, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087787033, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507328, "_x_x_x_x_bach_float64_x_x_x_x_", 1821066134, 1083079143, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087923750, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686016, "_x_x_x_x_bach_float64_x_x_x_x_", 4123168604, 1085336296, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1083174215, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686272, "_x_x_x_x_bach_float64_x_x_x_x_", 790273982, 1082888925, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1085701767, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086123264, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1086082209, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085019136, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1086272419, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686528, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1086774118, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 515396076, 1083985029, 100, "[", "slots" ],
									"whole_roll_data_0000000001" : [ "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087095116, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085866752, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087285337, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085815552, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087427404, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087528454, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087576012, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085683200, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3119864244, 1079457498, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 1065151889, 1082983989, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1083174215, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763840, "_x_x_x_x_bach_float64_x_x_x_x_", 790273982, 1082888925, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4123168604, 1084080168, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085760256, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1084534307, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737216, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1546188227, 1084938511, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993728, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085297553, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085559040, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085499665, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1085701767, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085815296, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 171798692, 1085891991, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227520, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1086082209, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686528, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1086272419, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085123072, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1086387745, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085815296, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1086488798, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085867008, "_x_x_x_x_bach_float64_x_x_x_x_", 2748779069, 1083604592, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1086673075, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085866752, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1086774118, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083079096, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1086898956, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481984, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087095116, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085072384, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085867008, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087379852, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087427404, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085429248, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087477932, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085866752, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087528454, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085815296, "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083747256, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087629510, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087680038, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085866496, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087733536, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, "_x_x_x_x_bach_float64_x_x_x_x_", 34359738, 1082793771, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087787033, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085224448, "_x_x_x_x_bach_float64_x_x_x_x_", 1821066134, 1083079143, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087849452, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084866048, "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1083319275, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087923750, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084866560, "_x_x_x_x_bach_float64_x_x_x_x_", 4123168604, 1085336296, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3119864244, 1079457498, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993728, "_x_x_x_x_bach_float64_x_x_x_x_", 1065151889, 1082983989, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4123168604, 1084080168, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1084814848, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1084534307, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085866496, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1546188227, 1084938511, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085378048, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1085701767, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1086082209, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085559040, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1086673075, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1086774118, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085866752, "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083079096, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1086898956, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 2061584302, 1083699732, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085635584, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087379852, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085584384, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087477932, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085866752, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087528454, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083747256, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087733536, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558528, "_x_x_x_x_bach_float64_x_x_x_x_", 34359738, 1082793771, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087787033, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085968896, "_x_x_x_x_bach_float64_x_x_x_x_", 1821066134, 1083079143, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087849452, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085225984, "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1083319275, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3119864244, 1079457498, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086093824, "_x_x_x_x_bach_float64_x_x_x_x_", 1065151889, 1082983989, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1546188227, 1084938511, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085636352, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085297553, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086071808, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1086272419, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686528, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1086673075, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1086898956, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087285337, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085892096, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087379852, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085605888, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087427404, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087477932, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085808128, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087528454, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087576012, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086093824, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087680038, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993728, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1546188227, 1084938511, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086093824, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087285337, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085914368, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3119864244, 1079457498, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085687040, "_x_x_x_x_bach_float64_x_x_x_x_", 1065151889, 1082983989, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1083174215, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 790273982, 1082888925, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4123168604, 1084080168, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737472, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1084534307, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085610240, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1546188227, 1084938511, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085227008, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085297553, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686272, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085499665, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1085701767, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 171798692, 1085891991, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085559040, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1086082209, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085228544, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1086387745, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085302272, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1086488798, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085228032, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1086577958, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085969152, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1086673075, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1086774118, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085866752, "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083079096, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1086898956, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085353984, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087005952, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085481728, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087095116, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086004992, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085728512, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087285337, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085686528, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087379852, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085276672, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087427404, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993984, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087477932, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085866752, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087528454, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085524736, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087629510, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085808384, "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1083794841, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087733536, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085429504, "_x_x_x_x_bach_float64_x_x_x_x_", 515396076, 1083985029, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1083174215, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085020672, "_x_x_x_x_bach_float64_x_x_x_x_", 790273982, 1082888925, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1546188227, 1084938511, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085993728, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085499665, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1086577958, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085661184, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1086673075, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085559040, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085267456, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087285337, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085123584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3119864244, 1079457498, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085456384, "_x_x_x_x_bach_float64_x_x_x_x_", 1065151889, 1082983989, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1083174215, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 790273982, 1082888925, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1084534307, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085558784, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1546188227, 1084938511, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763840, "_x_x_x_x_bach_float64_x_x_x_x_", 3264175145, 1083699701, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085499665, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085815296, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 171798692, 1085891991, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085019136, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1086082209, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085866752, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1086272419, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085815040, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1086387745, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085507328, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1086488798, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085605888, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1086577958, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737472, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1086673075, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763840, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1086774118, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085019648, "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083079096, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087005952, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085867008, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085580544, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087285337, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085123584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087427404, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085867008, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087477932, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085429248, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087528454, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085583872, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087576012, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085815296, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087629510, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085867008, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087680038, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085774592, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087787033, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085737216, "_x_x_x_x_bach_float64_x_x_x_x_", 1821066134, 1083079143, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087849452, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085867008, "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1083319275, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087923750, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085226496, "_x_x_x_x_bach_float64_x_x_x_x_", 4123168604, 1085336296, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1083174215, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 790273982, 1082888925, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085297553, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1086488798, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", 0, "]", "[", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1083174215, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 790273982, 1082888925, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4123168604, 1084080168, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1084534307, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085297553, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085499665, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1086082209, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1086272419, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087005952, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087285337, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087379852, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087427404, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087477932, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087528454, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087629510, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087680038, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087733536, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 34359738, 1082793771, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1083174215, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 790273982, 1082888925, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085297553, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087005952, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087427404, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3119864244, 1079457498, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 1065151889, 1082983989, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1083174215, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 790273982, 1082888925, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4123168604, 1084080168, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1084534307, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0 ],
									"whole_roll_data_0000000002" : [ "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1546188227, 1084938511, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085297553, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085499665, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1085701767, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 171798692, 1085891991, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1086272419, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1086387745, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1086488798, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1086577958, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1086673075, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1086774118, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083079096, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1086898956, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087005952, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087095116, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087285337, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087379852, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087427404, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087477932, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087576012, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087629510, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087680038, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087733536, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 515396076, 1083985029, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087849452, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1083319275, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087923750, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 4123168604, 1085336296, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4123168604, 1084080168, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1084534307, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1546188227, 1084938511, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085297553, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 171798692, 1085891991, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1086577958, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1086774118, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083079096, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087005952, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087285337, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 687194767, 1084367836, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087629510, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087680038, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087733536, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 34359738, 1082793771, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3119864244, 1079457498, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 1065151889, 1082983989, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1083174215, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 790273982, 1082888925, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4123168604, 1084080168, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3264175145, 1083699701, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1084534307, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1546188227, 1084938511, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085297553, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085499665, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1085701767, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1086082209, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1086272419, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1086387745, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1086488798, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 2748779069, 1083604592, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1086577958, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1086673075, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 343597384, 1083937454, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1086898956, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1087005952, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087095116, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087285337, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 1202590843, 1083699681, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087427404, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1083747235, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087477932, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087528454, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087576012, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087629510, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087680038, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 1889785610, 1083842365, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087787033, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 1821066134, 1083079143, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087849452, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1083319275, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087923750, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 4123168604, 1085336296, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", 0, "]", "[", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3119864244, 1079457498, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 515396076, 1083985029, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 4123168604, 1084080168, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1546188227, 1084938511, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085297553, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 4054449127, 1082698706, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085499665, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1086272419, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 858993459, 1083652147, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1086488798, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3229815407, 1082508490, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1086898956, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087095116, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3745211482, 1082603599, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087285337, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3813930959, 1082698661, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 1717986918, 1087528454, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 3298534883, 1082603552, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "pp", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087576012, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 274877907, 1082793816, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "mf", "]", "]", 0, "]", 0, "]", "[", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1087787033, "[", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1085763584, "_x_x_x_x_bach_float64_x_x_x_x_", 1821066134, 1083079143, 100, "[", "slots", "[", 7, "ord", "]", "[", 20, "ff", "]", "]", 0, "]", 0, "]", 0, "]" ],
									"whole_roll_data_count" : [ 3 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-27",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 291.359528, 278.5, 157.0, 50.0 ],
									"style" : "",
									"text" : "Optional arguments are: \n• segment number\n• solution number"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"id" : "obj-25",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 131.859528, 143.5, 159.0, 69.0 ],
									"style" : "",
									"text" : "connect the left inlet of orchidea.solution.toroll to the outlet of orchidea.search"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"id" : "obj-15",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 382.859528, 165.0, 226.0, 25.0 ],
									"style" : "",
									"text" : "Import all solutions of 3rd segment"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-16",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 351.359528, 165.0, 29.5, 23.0 ],
									"style" : "",
									"text" : "3"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"id" : "obj-14",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 397.0, 189.5, 264.0, 25.0 ],
									"style" : "",
									"text" : "Import 5th solution found for 3st segment"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-13",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 362.5, 189.5, 29.5, 23.0 ],
									"style" : "",
									"text" : "3 5"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"id" : "obj-12",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 366.109528, 139.0, 150.0, 25.0 ],
									"style" : "",
									"text" : "Import connection"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-8",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 332.609528, 139.0, 29.5, 23.0 ],
									"style" : "",
									"text" : "0"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-6",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 15.359528, 263.5, 229.640472, 23.0 ],
									"style" : "",
									"text" : "orchidea.solution.toroll"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-3",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 83.567627, 506.0, 21.0 ],
									"style" : "",
									"text" : "Imports a specific Orchidea solution, or the global connection, as a bach.roll score",
									"textcolor" : [ 0.501961, 0.501961, 0.501961, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-35",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 60.567627, 242.0, 21.0 ],
									"style" : "",
									"text" : "Display Orchidea solutions in a bach.roll"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-4",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 15.359528, 166.5, 111.0, 23.0 ],
									"style" : "",
									"text" : "r current_solution"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-5",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 10.0, 105.567627, 581.0, 36.0 ],
									"style" : "",
									"text" : "The orchidea.solution.tobuffer module receives the output of orchidea.search and fills the connected bach.roll with the requested solution",
									"textcolor" : [ 0.501961, 0.501961, 0.501961, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"border" : 0,
									"filename" : "helpdetails.js",
									"id" : "obj-2",
									"ignoreclick" : 1,
									"jsarguments" : [ "orchidea.solution.toroll", 80 ],
									"maxclass" : "jsui",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 10.0, 10.0, 660.0, 114.0 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-18", 0 ],
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-18", 0 ],
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-28", 0 ],
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-28", 0 ],
									"source" : [ "obj-16", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-18", 0 ],
									"source" : [ "obj-17", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-18", 0 ],
									"source" : [ "obj-20", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-28", 0 ],
									"source" : [ "obj-21", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-28", 0 ],
									"source" : [ "obj-23", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"source" : [ "obj-26", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-26", 0 ],
									"midpoints" : [ 223.5, 252.0, 100.0, 252.0, 100.0, 222.0, 24.859528, 222.0 ],
									"source" : [ "obj-28", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 1 ],
									"source" : [ "obj-28", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-26", 0 ],
									"source" : [ "obj-4", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-18", 0 ],
									"source" : [ "obj-6", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-28", 0 ],
									"source" : [ "obj-8", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 10.0, 85.0, 50.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"style" : "",
						"tags" : ""
					}
,
					"style" : "",
					"text" : "p basic",
					"varname" : "basic_tab"
				}

			}
, 			{
				"box" : 				{
					"border" : 0,
					"filename" : "helpname.js",
					"id" : "obj-4",
					"ignoreclick" : 1,
					"jsarguments" : [ "orchidea.solution.toroll" ],
					"maxclass" : "jsui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 10.0, 10.0, 488.307037, 57.567627 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-8",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 4,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 0.0, 26.0, 699.0, 636.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 13.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 5.0, 5.0 ],
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
						"showontab" : 1,
						"boxes" : [  ],
						"lines" : [  ]
					}
,
					"patching_rect" : [ 205.0, 205.0, 50.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontsize" : 13.0,
						"globalpatchername" : "",
						"style" : "",
						"tags" : ""
					}
,
					"style" : "",
					"text" : "p ?",
					"varname" : "q_tab"
				}

			}
 ],
		"lines" : [  ],
		"dependency_cache" : [ 			{
				"name" : "helpname.js",
				"bootpath" : "C74:/help/resources",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "helpdetails.js",
				"bootpath" : "C74:/help/resources",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "orchidea.solution.toroll.maxpat",
				"bootpath" : "~/MusicaMia/_RICERCA/orchidea/max/patches",
				"patcherrelativepath" : "../patches",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.prepend.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../../../../../Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.filternull.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../../../../../Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.+.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../../../../../Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.lookup.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"patcherrelativepath" : "../../../../../Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "helpstarter.js",
				"bootpath" : "C74:/help/resources",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "bach.keys.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.length.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.args.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.portal.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.join.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.reg.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.wrap.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.slice.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.pick.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.read.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.iter.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.eq.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.flat.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.nth.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.roll.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.p2mc.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.expr.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.mapelem.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.trans.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.minmax.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
