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
		"default_fontsize" : 12.0,
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
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-18",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 2,
					"outlettype" : [ "", "int" ],
					"patching_rect" : [ 1417.571411, 897.0, 104.0, 23.0 ],
					"style" : "",
					"text" : "bach.ezmidiplay"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-26",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 537.0, 55.0, 35.0, 23.0 ],
					"style" : "",
					"text" : "stop"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-24",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 459.0, 55.0, 46.0, 23.0 ],
					"style" : "",
					"text" : "pause"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-23",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 380.0, 55.0, 34.0, 23.0 ],
					"style" : "",
					"text" : "play"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-3",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 228.0, 75.0, 37.0, 22.0 ],
					"style" : "",
					"text" : "clear"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 69.0, 41.0, 35.0, 22.0 ],
					"style" : "",
					"text" : "read"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-89",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 537.0, 98.5, 66.0, 22.0 ],
					"style" : "",
					"text" : "exportmidi"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-88",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 459.0, 98.5, 69.0, 22.0 ],
					"style" : "",
					"text" : "exportpwgl"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-87",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 380.0, 98.5, 61.0, 22.0 ],
					"style" : "",
					"text" : "exportom"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-85",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 1,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 109.0, 154.0, 971.0, 567.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
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
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-6",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "bang", "", "G" ],
									"patching_rect" : [ 543.0, 788.0, 43.0, 22.0 ],
									"style" : "",
									"text" : "t b l G"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-5",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 543.0, 891.0, 40.0, 22.0 ],
									"style" : "",
									"text" : "zl.reg"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-4",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 634.0, 773.0, 29.5, 22.0 ],
									"style" : "",
									"text" : "foo"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-82",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 586.5, 853.5, 79.0, 22.0 ],
									"style" : "",
									"text" : "route symbol"
								}

							}
, 							{
								"box" : 								{
									"bubble" : 1,
									"id" : "obj-80",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 683.0, 821.5, 150.0, 37.0 ],
									"style" : "",
									"text" : "Set Instrument2clef conversions here"
								}

							}
, 							{
								"box" : 								{
									"coll_data" : 									{
										"count" : 12,
										"data" : [ 											{
												"key" : "Fl",
												"value" : [ "G" ]
											}
, 											{
												"key" : "Ob",
												"value" : [ "G" ]
											}
, 											{
												"key" : "ClBb",
												"value" : [ "G" ]
											}
, 											{
												"key" : "Bn",
												"value" : [ "auto" ]
											}
, 											{
												"key" : "Hn",
												"value" : [ "auto" ]
											}
, 											{
												"key" : "TpC",
												"value" : [ "G" ]
											}
, 											{
												"key" : "Tbn",
												"value" : [ "F" ]
											}
, 											{
												"key" : "BTb",
												"value" : [ "F" ]
											}
, 											{
												"key" : "Vn",
												"value" : [ "G" ]
											}
, 											{
												"key" : "Va",
												"value" : [ "G" ]
											}
, 											{
												"key" : "Vc",
												"value" : [ "auto" ]
											}
, 											{
												"key" : "Cb",
												"value" : [ "`F8vb" ]
											}
 ]
									}
,
									"id" : "obj-76",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 4,
									"outlettype" : [ "", "", "", "" ],
									"patching_rect" : [ 586.5, 825.5, 90.0, 22.0 ],
									"saved_object_attributes" : 									{
										"embed" : 1
									}
,
									"style" : "",
									"text" : "coll instr2clef 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-75",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 365.5, 809.5, 128.0, 22.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"style" : "",
									"text" : "bach.mapelem @out t"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-74",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 223.5, 841.5, 161.0, 22.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"style" : "",
									"text" : "bach.pack voicenames clefs"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-69",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 7,
											"minor" : 3,
											"revision" : 1,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"rect" : [ 84.0, 129.0, 640.0, 480.0 ],
										"bglocked" : 0,
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
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
										"boxes" : [ 											{
												"box" : 												{
													"id" : "obj-14",
													"maxclass" : "message",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 134.0, 208.0, 29.5, 22.0 ],
													"style" : "",
													"text" : "0c"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-11",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 35.0, 236.0, 122.0, 22.0 ],
													"saved_object_attributes" : 													{
														"versionnumber" : 80001
													}
,
													"style" : "",
													"text" : "bach.insert -2 @out t"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-10",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patching_rect" : [ 35.0, 164.0, 44.0, 22.0 ],
													"style" : "",
													"text" : "gate 2"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-9",
													"maxclass" : "newobj",
													"numinlets" : 1,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 107.0, 126.0, 109.0, 22.0 ],
													"style" : "",
													"text" : "expr ($i1 == 7) + 1"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-1",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patching_rect" : [ 107.0, 93.0, 39.0, 22.0 ],
													"style" : "",
													"text" : "zl.len"
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-39",
													"maxclass" : "inlet",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 50.0, 40.0, 30.0, 30.0 ],
													"style" : ""
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-40",
													"maxclass" : "outlet",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 60.0, 314.385254, 30.0, 30.0 ],
													"style" : ""
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-9", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-1", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-11", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-10", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-14", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-10", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-40", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-10", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-40", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-11", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-11", 2 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-14", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-1", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-39", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-10", 1 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-39", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-10", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-9", 0 ]
												}

											}
 ]
									}
,
									"patching_rect" : [ 195.0, 510.5, 191.0, 22.0 ],
									"saved_object_attributes" : 									{
										"description" : "",
										"digest" : "",
										"globalpatchername" : "",
										"style" : "",
										"tags" : ""
									}
,
									"style" : "",
									"text" : "p make_all_list_have_7_elements"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-67",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 195.0, 544.5, 169.0, 22.0 ],
									"style" : "",
									"text" : "zl.join 0"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-66",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 510.25, 756.5, 111.0, 22.0 ],
									"style" : "",
									"text" : "bach.filternull none"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-65",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 510.25, 660.5, 66.0, 22.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"style" : "",
									"text" : "bach.flat 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-64",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 510.25, 725.5, 67.0, 22.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"style" : "",
									"text" : "bach.nth 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-61",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 510.25, 691.5, 122.0, 22.0 ],
									"style" : "",
									"text" : "bach.sieve () @op !="
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-60",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 223.5, 729.5, 167.0, 22.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"style" : "",
									"text" : "bach.mapelem @maxdepth 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-59",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "float", "int" ],
									"patching_rect" : [ 183.0, 387.5, 31.0, 22.0 ],
									"style" : "",
									"text" : "t f 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-58",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 228.0, 629.5, 29.5, 22.0 ],
									"style" : "",
									"text" : "-1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-55",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"patching_rect" : [ 71.5, 349.5, 40.0, 22.0 ],
									"style" : "",
									"text" : "t l l 0"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-54",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 136.0, 422.5, 29.5, 22.0 ],
									"style" : "",
									"text" : "1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-50",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 61.5, 463.203125, 34.0, 22.0 ],
									"style" : "",
									"text" : "gate"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-38",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 223.5, 695.5, 67.0, 22.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"style" : "",
									"text" : "bach.trans"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-36",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 704.5, 67.0, 22.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"style" : "",
									"text" : "bach.trans"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-34",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 195.0, 448.5, 81.0, 22.0 ],
									"style" : "",
									"text" : "bach.filternull"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-33",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "bang", "dump" ],
									"patching_rect" : [ 50.0, 134.5, 57.0, 22.0 ],
									"style" : "",
									"text" : "t b dump"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-27",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 91.0, 421.5, 29.5, 22.0 ],
									"style" : "",
									"text" : "()"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-20",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 3,
									"outlettype" : [ "bang", "bang", "" ],
									"patching_rect" : [ 91.0, 387.5, 63.0, 22.0 ],
									"style" : "",
									"text" : "sel - bang"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-19",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 183.0, 359.5, 49.0, 22.0 ],
									"style" : "",
									"text" : "zl.nth 2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-17",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 207.0, 319.5, 173.0, 20.0 ],
									"style" : "",
									"text" : "new solution: let's get its onset"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-15",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 91.0, 319.5, 111.0, 22.0 ],
									"style" : "",
									"text" : "gate 2 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-14",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 244.0, 293.5, 116.0, 22.0 ],
									"style" : "",
									"text" : "expr ($i1 == 62) + 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-12",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 244.0, 263.5, 49.0, 22.0 ],
									"style" : "",
									"text" : "zl.nth 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-11",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "list" ],
									"patching_rect" : [ 244.0, 235.5, 40.0, 22.0 ],
									"style" : "",
									"text" : "atoi"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-10",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 339.0, 176.5, 34.0, 22.0 ],
									"style" : "",
									"text" : "print"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "bang", "int" ],
									"patching_rect" : [ 297.0, 141.5, 40.0, 22.0 ],
									"style" : "",
									"text" : "text"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-2",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 254.0, 200.5, 445.0, 20.0 ],
									"style" : "",
									"text" : "onset strumento tecnica nota dinamica sord_ottoni sord_corde midicent nome_file"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-46",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 183.0, 629.5, 29.5, 22.0 ],
									"style" : "",
									"text" : "$2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-37",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 186.0, 199.5, 61.0, 22.0 ],
									"style" : "",
									"text" : "route set"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-42",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 7,
											"minor" : 3,
											"revision" : 1,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"rect" : [ 84.0, 129.0, 640.0, 480.0 ],
										"bglocked" : 0,
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
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
										"boxes" : [ 											{
												"box" : 												{
													"id" : "obj-38",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 230.0, 153.598145, 66.0, 22.0 ],
													"style" : "",
													"text" : "bach.+ C1"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-37",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patching_rect" : [ 226.5, 81.598145, 73.0, 22.0 ],
													"style" : "",
													"text" : "bach.filter p"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-36",
													"maxclass" : "newobj",
													"numinlets" : 2,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patching_rect" : [ 50.0, 126.598145, 128.0, 22.0 ],
													"saved_object_attributes" : 													{
														"versionnumber" : 80001
													}
,
													"style" : "",
													"text" : "bach.mapelem @out t"
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-39",
													"maxclass" : "inlet",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 50.0, 40.0, 30.0, 30.0 ],
													"style" : ""
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-40",
													"maxclass" : "outlet",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 50.0, 223.385254, 30.0, 30.0 ],
													"style" : ""
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-37", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-36", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-40", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-36", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-36", 1 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-37", 1 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-38", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-37", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-36", 1 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-38", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-36", 0 ],
													"disabled" : 0,
													"hidden" : 0,
													"source" : [ "obj-39", 0 ]
												}

											}
 ]
									}
,
									"patching_rect" : [ 195.0, 475.203125, 123.0, 22.0 ],
									"saved_object_attributes" : 									{
										"description" : "",
										"digest" : "",
										"globalpatchername" : "",
										"style" : "",
										"tags" : ""
									}
,
									"style" : "",
									"text" : "p make_middleC_C5"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-31",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 886.703125, 192.5, 22.0 ],
									"style" : "",
									"text" : "bach.prepend"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-24",
									"maxclass" : "newobj",
									"numinlets" : 4,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 50.0, 664.703125, 192.5, 22.0 ],
									"saved_object_attributes" : 									{
										"versionnumber" : 80001
									}
,
									"style" : "",
									"text" : "bach.collect 2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-13",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 133.5, 592.703125, 242.0, 22.0 ],
									"style" : "",
									"text" : "( $8 ( $4 $1 100 ( slots ( 1 $3 ) ( 20 $5 ) ) ) )"
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-83",
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 297.0, 40.0, 30.0, 30.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-84",
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 50.0, 968.703125, 30.0, 30.0 ],
									"style" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-10", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-33", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"midpoints" : [ 317.0, 168.5, 227.0, 168.5, 227.0, 101.5, 59.5, 101.5 ],
									"source" : [ "obj-1", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-37", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-12", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-14", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-12", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-24", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-15", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-14", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-15", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-55", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-15", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-59", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-19", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-27", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-20", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-54", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-20", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-58", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-20", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-36", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-24", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-38", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-24", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-24", 2 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-24", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-84", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-31", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-33", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-24", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-33", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-42", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-34", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-31", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-36", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-11", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-37", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-15", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-37", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-60", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-38", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-69", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-42", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-24", 2 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-46", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-75", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-34", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-50", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-50", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-54", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-55", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-50", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"midpoints" : [ 102.0, 375.5, 71.0, 375.5 ],
									"source" : [ "obj-55", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-50", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-55", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-24", 3 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-58", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-24", 3 ],
									"disabled" : 0,
									"hidden" : 0,
									"midpoints" : [ 204.5, 418.5, 481.0, 418.5, 481.0, 631.5, 233.0, 631.5 ],
									"source" : [ "obj-59", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-67", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"midpoints" : [ 192.5, 423.5, 354.5, 423.5 ],
									"source" : [ "obj-59", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-6", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-6", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-76", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-6", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-65", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-60", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-74", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-60", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-75", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-60", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-64", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-61", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-66", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-64", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-61", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-65", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-60", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-66", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-60", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-66", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-13", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-67", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-46", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-67", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-67", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-69", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-31", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-74", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-75", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-74", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-75", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-82", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-76", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-82", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-83", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 69.0, 79.5, 121.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"globalpatchername" : "",
						"style" : "",
						"tags" : ""
					}
,
					"style" : "",
					"text" : "p convert_file_to_roll"
				}

			}
, 			{
				"box" : 				{
					"bgslotfontsize" : 12.0,
					"bwcompatibility" : 80001,
					"clefs" : [ "G", "G", "G", "G", "G", "G", "G", "G", "G", "G", "G", "G", "F", "F", "F", "G", "G", "G", "G", "G", "G", "`f8vb", "`f8vb" ],
					"defaultnoteslots" : [ "null" ],
					"enharmonictable" : [ "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default", "default" ],
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidevoices" : [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ],
					"id" : "obj-51",
					"keys" : [ "CM", "CM", "CM", "CM", "CM", "CM", "CM", "CM", "CM", "CM", "CM", "CM", "CM", "CM", "CM", "CM", "CM", "CM", "CM", "CM", "CM", "CM", "CM" ],
					"linkannotationtoslot" : 1,
					"loop" : [ 0.0, 1000.0 ],
					"maxclass" : "bach.roll",
					"midichannels" : [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 ],
					"numinlets" : 6,
					"numoutlets" : 8,
					"numparts" : [ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ],
					"numvoices" : 23,
					"out" : "nnnnnnn",
					"outlettype" : [ "", "", "", "", "", "", "", "bang" ],
					"patching_rect" : [ 69.0, 132.203125, 1280.0, 771.0 ],
					"pitcheditrange" : [ "null" ],
					"showplayhead" : 1,
					"stafflines" : [ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"versionnumber" : 80001,
					"voicenames" : [ "Fl", "Fl", "Ob", "Ob", "ClBb", "ClBb", "Bn", "Bn", "Hn", "Hn", "TpC", "TpC", "Tbn", "Tbn", "BTb", "Vn", "Vn", "Va", "Va", "Vc", "Vc", "Cb", "Cb" ],
					"voicespacing" : [ 0.0, 35.0, 35.0, 35.0, 35.0, 35.0, 35.0, 35.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0, 17.0 ],
					"vzoom" : 70.0,
					"whole_roll_data_0000000000" : [ "roll", "(", "slotinfo", "(", 1, "(", "name", "playing style", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "temporalmode", "relative", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 0, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 2, "(", "name", "slot function", ")", "(", "type", "function", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "grid", ")", "(", "ysnap", ")", "(", "domain", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "domainslope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "temporalmode", "relative", ")", "(", "extend", 0, ")", "(", "width", "auto", ")", "(", "height", "auto", ")", "(", "copywhensplit", 0, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 3, "(", "name", "slot intlist", ")", "(", "type", "intlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 4, "(", "name", "slot floatlist", ")", "(", "type", "floatlist", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 5, "(", "name", "slot int", ")", "(", "type", "int", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080016896, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1078984704, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 6, "(", "name", "slot float", ")", "(", "type", "float", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1072693248, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "default", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 7, "(", "name", "slot text", ")", "(", "type", "text", ")", "(", "key", 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 0, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 8, "(", "name", "slot filelist", ")", "(", "type", "filelist", ")", "(", "key", 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1080213504, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 9, "(", "name", "slot spat", ")", "(", "type", "spat", ")", "(", "key", 0, ")", "(", "range", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1076101120, ")", "(", "slope", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, ")", "(", "representation", ")", "(", "temporalmode", "relative", ")", "(", "extend", 0, ")", "(", "width", "auto", ")", "(", "height", "auto", ")", "(", "copywhensplit", 0, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 10, "(", "name", "slot llll", ")", "(", "type", "llll", ")", "(", "key", 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 0, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 11, "(", "name", "slot 11", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 12, "(", "name", "slot 12", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 13, "(", "name", "slot 13", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 14, "(", "name", "slot 14", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 15, "(", "name", "slot 15", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 16, "(", "name", "slot 16", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 17, "(", "name", "slot 17", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 18, "(", "name", "slot 18", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 19, "(", "name", "slot 19", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 20, "(", "name", "dynamics", ")", "(", "type", "dynamics", ")", "(", "key", "d", ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079083008, ")", "(", "height", "auto", ")", "(", "copywhensplit", 0, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 21, "(", "name", "lyrics", ")", "(", "type", "text", ")", "(", "key", "l", ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 0, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 22, "(", "name", "articulations", ")", "(", "type", "articulations", ")", "(", "key", "a", ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 23, "(", "name", "notehead", ")", "(", "type", "notehead", ")", "(", "key", "h", ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079738368, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 24, "(", "name", "slot 24", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 25, "(", "name", "slot 25", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 26, "(", "name", "slot 26", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 27, "(", "name", "slot 27", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 28, "(", "name", "slot 28", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 29, "(", "name", "slot 29", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", "(", 30, "(", "name", "slot 30", ")", "(", "type", "none", ")", "(", "key", 0, ")", "(", "temporalmode", "none", ")", "(", "extend", 0, ")", "(", "width", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1079574528, ")", "(", "height", "auto", ")", "(", "copywhensplit", 1, ")", "(", "access", "readandwrite", ")", "(", "follownotehead", 0, ")", ")", ")", "(", "commands", "(", 1, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 2, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 3, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 4, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", "(", 5, "(", "note", "note", ")", "(", "chord", "chord", ")", "(", "rest", "rest", ")", "(", "key", 0, ")", ")", ")", "(", "groups", ")", "(", "markers", ")", "(", "midichannels", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, ")", "(", "articulationinfo", ")", "(", "noteheadinfo", ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, "(", "C6", "_x_x_x_x_bach_float64_x_x_x_x_", 1889785610, 1084320317, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3264175145, 1086369909, "(", "B5", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1084248985, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1086637401, "(", "B5", "_x_x_x_x_bach_float64_x_x_x_x_", 3779571220, 1084272762, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086910848, "(", "E5", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1084296524, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "E6", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, "(", "F#5", "_x_x_x_x_bach_float64_x_x_x_x_", 1889785610, 1084320317, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1085333219, "(", "G5", "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1084272747, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3264175145, 1086369909, "(", "E6", "_x_x_x_x_bach_float64_x_x_x_x_", 2920577761, 1085309447, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086910848, "(", "B4", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1084296524, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "(", "D#5", "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083390648, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "E5", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, "(", "C6", "_x_x_x_x_bach_float64_x_x_x_x_", 1889785610, 1084320317, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3264175145, 1086369909, "(", "A#6", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1084248985, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1086637401, "(", "E6", "_x_x_x_x_bach_float64_x_x_x_x_", 3779571220, 1084272762, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "A5", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1085880094, "(", "E4", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3264175145, 1086369909, "(", "A#5", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1084248985, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086910848, "(", "A4", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1084296524, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "(", "B5", "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083390648, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, "(", "A5", "_x_x_x_x_bach_float64_x_x_x_x_", 1889785610, 1084320317, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1085880094, "(", "E5", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085297553, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1086637401, "(", "G4", "_x_x_x_x_bach_float64_x_x_x_x_", 3779571220, 1084272762, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086910848, "(", "F#5", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1084296524, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "C5", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, "(", "E5", "_x_x_x_x_bach_float64_x_x_x_x_", 1889785610, 1084320317, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1085333219, "(", "F#5", "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1084272747, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1085880094, "(", "E5", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1086637401, "(", "E3", "_x_x_x_x_bach_float64_x_x_x_x_", 3779571220, 1084272762, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086910848, "(", "D#5", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1084296524, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "(", "E5", "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083390648, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "C5", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1085880094, "(", "C5", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3264175145, 1086369909, "(", "C#5", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1084248985, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1086637401, "(", "E4", "_x_x_x_x_bach_float64_x_x_x_x_", 3779571220, 1084272762, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086910848, "(", "C5", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1084296524, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "A5", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, "(", "F#4", "_x_x_x_x_bach_float64_x_x_x_x_", 1889785610, 1084320317, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1085333219, "(", "F#5", "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1084272747, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1085880094, "(", "A5", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3264175145, 1086369909, "(", "E3", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1084248985, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1086637401, "(", "D#3", "_x_x_x_x_bach_float64_x_x_x_x_", 3779571220, 1084272762, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086910848, "(", "B4", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1084296524, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "C5", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, "(", "A5", "_x_x_x_x_bach_float64_x_x_x_x_", 1889785610, 1084320317, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1085333219, "(", "B4", "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1084272747, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1085880094, "(", "G4", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3264175145, 1086369909, "(", "E3", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1084248985, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1086637401, "(", "F#3", "_x_x_x_x_bach_float64_x_x_x_x_", 3779571220, 1084272762, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "(", "G#3", "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083390648, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "E5", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "E5", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1085333219, "(", "F#5", "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1084272747, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "C5", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1085333219, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1085333219, "(", "E5", "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1084272747, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1085880094, "(", "G4", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3264175145, 1086369909, "(", "E5", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1084248985, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1086637401, "(", "F#3", "_x_x_x_x_bach_float64_x_x_x_x_", 3779571220, 1084272762, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086910848, "(", "E5", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1084296524, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "A5", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1085333219, "(", "E5", "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1084272747, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3264175145, 1086369909, "(", "E3", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1084248985, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086910848, "(", "A5", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1084296524, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "(", "G#3", "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083390648, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "E5", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1085333219, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1085333219, "(", "B4", "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1084272747, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1085880094, "(", "E4", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1085844428, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "(", "G#3", "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083390648, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "A5", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1085333219, "(", "G5", "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1084272747, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086910848, "(", "B5", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1084296524, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, "(", "C5", "_x_x_x_x_bach_float64_x_x_x_x_", 1889785610, 1084320317, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086910848, "(", "D#5", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1084296524, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1085333219, "(", "E5", "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1084272747, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1085880094, "(", "A5", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3264175145, 1086369909, "(", "E6", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1084248985, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1086637401, "(", "E5", "_x_x_x_x_bach_float64_x_x_x_x_", 3779571220, 1084272762, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086910848, "(", "C5", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1084296524, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "(", "B5", "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083390648, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "A5", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1085333219, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1085333219, "(", "B4", "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1084272747, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1085880094, "(", "A5", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3264175145, 1086369909, "(", "E6", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1084248985, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1086637401, "(", "D4", "_x_x_x_x_bach_float64_x_x_x_x_", 3779571220, 1084272762, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086910848, "(", "B5", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1084296524, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "(", "E5", "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083390648, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1085880094, "(", "E4", "_x_x_x_x_bach_float64_x_x_x_x_", 3951369912, 1085297553, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1086637401, "(", "D#3", "_x_x_x_x_bach_float64_x_x_x_x_", 3779571220, 1084272762, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086910848, "(", "E5", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1084296524, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "(", "E4", "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083390648, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 0, "(", "C5", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, "(", "F#5", "_x_x_x_x_bach_float64_x_x_x_x_", 1889785610, 1084320317, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1085333219, "(", "E4", "_x_x_x_x_bach_float64_x_x_x_x_", 2233382994, 1084272747, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3092376453, 1085880094, "(", "A6", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086910848, "(", "E5", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1084296524, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "(", "B6", "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083390648, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, "(", "F#5", "_x_x_x_x_bach_float64_x_x_x_x_", 1889785610, 1084320317, 100, "(", "slots", "(", 1, "ord", ")", "(", 20 ],
					"whole_roll_data_0000000001" : [ "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3607772529, 1085333219, "(", "E4", "_x_x_x_x_bach_float64_x_x_x_x_", 1889785610, 1085309437, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1087190220, "(", "D#5", "_x_x_x_x_bach_float64_x_x_x_x_", 1374389535, 1083390648, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", 0, ")", "(", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 1030792151, 1084248970, "(", "C6", "_x_x_x_x_bach_float64_x_x_x_x_", 1889785610, 1084320317, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "ff", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 2576980378, 1086637401, "(", "B3", "_x_x_x_x_bach_float64_x_x_x_x_", 3779571220, 1084272762, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "pp", ")", ")", 0, ")", 0, ")", "(", "_x_x_x_x_bach_float64_x_x_x_x_", 0, 1086910848, "(", "A5", "_x_x_x_x_bach_float64_x_x_x_x_", 3435973837, 1084296524, 100, "(", "slots", "(", 1, "ord", ")", "(", 20, "mf", ")", ")", 0, ")", 0, ")", 0, ")" ],
					"whole_roll_data_count" : [ 2 ],
					"zoom" : 104.359375
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-85", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-51", 6 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-85", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-87", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-88", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-89", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "bach.prepend.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.filter.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.+.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.filternull.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.sieve.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.ezmidiplay.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.gcd.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.approx.maxpat",
				"bootpath" : "~/Documents/Max 7/Packages/bach/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "bach.roll.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.collect.mxo",
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
				"name" : "bach.mapelem.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.is.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.neq.mxo",
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
				"name" : "bach.pick.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.expr.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.trans.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.lt.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.leq.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.geq.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.gt.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.depth.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.nth.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.flat.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.insert.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.pack.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.playkeys.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.length.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.print.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.keys.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "bach.slice.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
