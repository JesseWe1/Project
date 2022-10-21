{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 1,
			"revision" : 8,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 105.0, 119.0, 1052.0, 929.0 ],
		"bglocked" : 0,
		"openinpresentation" : 1,
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
		"assistshowspatchername" : 0,
		"boxes" : [ 			{
				"box" : 				{
					"fontsize" : 25.0,
					"id" : "obj-11",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 325.0, 402.0, 297.0, 35.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 59.5, 0.0, 161.0, 35.0 ],
					"text" : "FM Synthesis",
					"textcolor" : [ 1.0, 0.968627450980392, 0.968627450980392, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 189.5, 56.0, 32.0, 22.0 ],
					"text" : "mtof"
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"id" : "obj-2",
					"index" : 0,
					"maxclass" : "outlet",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 231.5, 404.0, 30.0, 30.0 ]
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"id" : "obj-1",
					"index" : 0,
					"maxclass" : "inlet",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 189.5, 14.0, 30.0, 30.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-87",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 231.5, 353.5, 34.0, 22.0 ],
					"text" : "*~ 0."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-77",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 84.0, 128.5, 58.0, 34.0 ],
					"presentation" : 1,
					"presentation_linecount" : 2,
					"presentation_rect" : [ 105.0, 32.0, 58.0, 34.0 ],
					"text" : "Harmonicity ratio"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-78",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 16.0, 128.5, 75.0, 34.0 ],
					"presentation" : 1,
					"presentation_linecount" : 2,
					"presentation_rect" : [ 35.5, 32.0, 75.0, 34.0 ],
					"text" : "Carrier frequency"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-17",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 312.0, 44.0, 64.0, 34.0 ],
					"presentation" : 1,
					"presentation_linecount" : 2,
					"presentation_rect" : [ 186.5, 32.0, 64.0, 34.0 ],
					"text" : "Note length"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-15",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 527.0, 174.5, 56.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 206.5, 131.0, 56.0, 20.0 ],
					"text" : "Release"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-79",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 479.0, 174.5, 52.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 145.5, 131.0, 52.0, 20.0 ],
					"text" : "Sustain"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 439.0, 174.5, 45.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 82.5, 131.0, 45.0, 20.0 ],
					"text" : "Decay"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-4",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 397.0, 174.5, 45.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 14.5, 131.0, 45.0, 20.0 ],
					"text" : "Attack"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "dial",
					"mult" : 10.0,
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 312.0, 80.0, 40.0, 40.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 181.5, 72.0, 53.0, 53.0 ],
					"size" : 501.0
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-22",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 176.5, 172.5, 78.0, 22.0 ],
					"text" : "pipe 0 0. 500"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-80",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "float", "float", "float" ],
					"patching_rect" : [ 189.5, 108.5, 76.0, 22.0 ],
					"text" : "trigger 0. f 1."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-81",
					"maxclass" : "dial",
					"mult" : 0.009999999776483,
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 485.0, 196.5, 40.0, 40.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 145.5, 156.0, 53.0, 53.0 ],
					"size" : 100.0
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-19",
					"maxclass" : "dial",
					"mult" : 10.0,
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 531.0, 196.5, 40.0, 40.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 206.5, 156.0, 53.0, 53.0 ],
					"size" : 101.0
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-18",
					"maxclass" : "dial",
					"mult" : 10.0,
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 441.5, 196.5, 40.0, 40.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 78.5, 156.0, 53.0, 53.0 ],
					"size" : 101.0
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"maxclass" : "dial",
					"mult" : 10.0,
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 399.5, 196.5, 40.0, 40.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 10.5, 156.0, 53.0, 53.0 ],
					"size" : 101.0
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "newobj",
					"numinlets" : 5,
					"numoutlets" : 4,
					"outlettype" : [ "signal", "signal", "", "" ],
					"patching_rect" : [ 399.5, 290.5, 109.0, 22.0 ],
					"text" : "adsr~ 40 40 0.5 40"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"maxclass" : "dial",
					"mult" : 0.05,
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 93.0, 164.5, 40.0, 40.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 107.5, 72.0, 53.0, 53.0 ],
					"size" : 200.0
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"maxclass" : "dial",
					"mult" : 0.05,
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 26.0, 164.5, 40.0, 40.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 35.5, 72.0, 53.0, 53.0 ],
					"size" : 200.0
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-5",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 108.0, 290.5, 131.0, 22.0 ],
					"text" : "Frequency_Modulation"
				}

			}
, 			{
				"box" : 				{
					"angle" : 270.0,
					"bordercolor" : [ 0.317647058823529, 0.674509803921569, 0.72156862745098, 1.0 ],
					"grad1" : [ 0.341176470588235, 0.862745098039216, 0.870588235294118, 1.0 ],
					"grad2" : [ 0.905882352941176, 0.552941176470588, 0.552941176470588, 1.0 ],
					"id" : "obj-31",
					"maxclass" : "panel",
					"mode" : 1,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ -1.0, -1.0, 615.0, 473.0 ],
					"presentation" : 1,
					"presentation_rect" : [ -2.0, 0.0, 295.0, 240.0 ],
					"proportion" : 0.5
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-80", 0 ],
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-87", 1 ],
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 1 ],
					"midpoints" : [ 409.0, 265.0, 431.5, 265.0 ],
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 2 ],
					"midpoints" : [ 451.0, 265.0, 454.0, 265.0 ],
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 4 ],
					"midpoints" : [ 540.5, 265.0, 499.0, 265.0 ],
					"source" : [ "obj-19", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"midpoints" : [ 186.0, 244.5, 409.0, 244.5 ],
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 2 ],
					"midpoints" : [ 321.5, 149.0, 245.0, 149.0 ],
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-87", 0 ],
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 1 ],
					"midpoints" : [ 35.5, 247.0, 173.5, 247.0 ],
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 2 ],
					"midpoints" : [ 102.5, 247.0, 229.5, 247.0 ],
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"midpoints" : [ 256.0, 256.5, 409.0, 256.5 ],
					"source" : [ "obj-80", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-80", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"midpoints" : [ 227.5, 211.5, 117.5, 211.5 ],
					"source" : [ "obj-80", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 3 ],
					"midpoints" : [ 494.5, 265.0, 476.5, 265.0 ],
					"source" : [ "obj-81", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"source" : [ "obj-87", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "Frequency_Modulation.maxpat",
				"bootpath" : "~/Desktop/wbb",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
 ],
		"autosave" : 0
	}

}
