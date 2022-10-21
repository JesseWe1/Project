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
		"rect" : [ 300.0, 434.0, 640.0, 480.0 ],
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
					"id" : "obj-10",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 152.5, 22.0, 150.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 147.5, 20.0, 63.0, 20.0 ],
					"text" : "Mic"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 342.0, 24.0, 150.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 328.5, 20.0, 63.0, 20.0 ],
					"text" : "Mic"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 208.5, 22.0, 150.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 210.0, 20.0, 48.0, 20.0 ],
					"text" : "Record"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 283.0, 118.0, 150.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 255.0, 111.0, 71.0, 20.0 ],
					"text" : "Say ahh?!"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-4",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 68.0, 134.0, 150.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 67.5, 111.0, 81.0, 20.0 ],
					"text" : "Say Let's Go!"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 308.0, 260.0, 150.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 38.5, 20.0, 48.0, 20.0 ],
					"text" : "Record"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.2, 0.2, 0.2, 0.0 ],
					"checkedcolor" : [ 0.686274509803922, 0.431372549019608, 0.431372549019608, 1.0 ],
					"id" : "obj-55",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 13.5, 158.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 212.5, 42.0, 43.0, 43.0 ],
					"uncheckedcolor" : [ 0.27843137254902, 0.27843137254902, 0.27843137254902, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.2, 0.2, 0.2, 0.0 ],
					"id" : "obj-57",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"offcolor" : [ 0.333333333333333, 0.333333333333333, 0.333333333333333, 1.0 ],
					"oncolor" : [ 0.796078431372549, 0.549019607843137, 0.549019607843137, 1.0 ],
					"outlettype" : [ "float" ],
					"patching_rect" : [ 57.0, 206.5, 80.0, 13.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 275.5, 72.0, 86.0, 13.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.2, 0.2, 0.2, 0.0 ],
					"color" : [ 0.72156862745098, 0.470588235294118, 0.470588235294118, 1.0 ],
					"elementcolor" : [ 0.298039215686275, 0.294117647058824, 0.294117647058824, 1.0 ],
					"id" : "obj-58",
					"maxclass" : "ezadc~",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "signal" ],
					"patching_rect" : [ 57.0, 137.0, 45.0, 45.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 328.5, 42.5, 26.0, 26.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-59",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 13.5, 225.5, 168.0, 22.0 ],
					"text" : "record~ Vocal_My_Voice_ahh"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.2, 0.2, 0.2, 0.0 ],
					"color" : [ 0.501960784313725, 0.501960784313725, 0.501960784313725, 0.0 ],
					"id" : "obj-60",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"patching_rect" : [ 124.0, 153.5, 187.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 200.5, 87.0, 187.0, 22.0 ],
					"text" : "buffer~ Vocal_My_Voice_ahh 300",
					"textcolor" : [ 0.796078431372549, 0.533333333333333, 0.533333333333333, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.23921568627451, 0.231372549019608, 0.231372549019608, 0.0 ],
					"checkedcolor" : [ 0.72156862745098, 0.466666666666667, 0.474509803921569, 1.0 ],
					"id" : "obj-116",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 18.5, 29.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 38.5, 42.0, 43.0, 43.0 ],
					"uncheckedcolor" : [ 0.27843137254902, 0.274509803921569, 0.274509803921569, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.2, 0.2, 0.2, 0.0 ],
					"id" : "obj-114",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"offcolor" : [ 0.27843137254902, 0.274509803921569, 0.274509803921569, 1.0 ],
					"oncolor" : [ 0.72156862745098, 0.458823529411765, 0.458823529411765, 1.0 ],
					"outlettype" : [ "float" ],
					"patching_rect" : [ 110.0, 67.0, 80.0, 13.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 94.5, 70.0, 86.0, 13.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.2, 0.2, 0.2, 0.0 ],
					"color" : [ 0.741176470588235, 0.466666666666667, 0.466666666666667, 1.0 ],
					"elementcolor" : [ 0.313725490196078, 0.313725490196078, 0.313725490196078, 1.0 ],
					"id" : "obj-113",
					"maxclass" : "ezadc~",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "signal" ],
					"patching_rect" : [ 57.0, 8.0, 45.0, 45.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 148.5, 42.0, 26.0, 26.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-112",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 57.0, 85.5, 141.0, 22.0 ],
					"text" : "record~ Vocal_My_Voice"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.2, 0.2, 0.2, 0.0 ],
					"color" : [ 0.890196078431372, 0.811764705882353, 0.811764705882353, 0.0 ],
					"id" : "obj-111",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"patching_rect" : [ 143.5, 16.0, 161.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 27.5, 87.0, 161.0, 22.0 ],
					"text" : "buffer~ Vocal_My_Voice 500",
					"textcolor" : [ 0.76078431372549, 0.470588235294118, 0.470588235294118, 1.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-112", 0 ],
					"midpoints" : [ 66.5, 54.0, 66.5, 54.0 ],
					"order" : 1,
					"source" : [ "obj-113", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-114", 0 ],
					"midpoints" : [ 66.5, 63.0, 119.5, 63.0 ],
					"order" : 0,
					"source" : [ "obj-113", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-112", 0 ],
					"midpoints" : [ 28.0, 72.0, 66.5, 72.0 ],
					"source" : [ "obj-116", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-59", 0 ],
					"midpoints" : [ 23.0, 183.0, 23.0, 183.0 ],
					"source" : [ "obj-55", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-57", 0 ],
					"midpoints" : [ 66.5, 183.0, 66.5, 183.0 ],
					"order" : 0,
					"source" : [ "obj-58", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-59", 0 ],
					"midpoints" : [ 66.5, 192.0, 23.0, 192.0 ],
					"order" : 1,
					"source" : [ "obj-58", 0 ]
				}

			}
 ],
		"dependency_cache" : [  ],
		"autosave" : 0
	}

}
