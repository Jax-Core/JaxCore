
function GenClip(MaxClips)
	local File = io.open(SKIN:GetVariable('SKINSPATH')..'Clipify\\Main\\Slots.inc','w')
	SkinFile = SKIN:GetVariable('SKINSPATH')..'Clipify\\Main\\Main.ini','w'
	Scale = SKIN:GetVariable('Scale')
	MaxScroll = ((70 * Scale) * (MaxClips - 4) + (5 * Scale) * (MaxClips - 4)) * -1
	-- /////////////////////////////////////////////////////////
	-- /////////////////////////////////////////////////////////
	File:write('[Box:1]\n'
	,'Meter=Shape\n'
	,'X=0\n'
	,'Y=#Scroll#\n'
	,'DynamicVariables=1\n'
	,'MeterStyle=Clip.Box:S\n')

	for i=1,(MaxClips - 1) do
		File:write('[Box:'..(i+1)..']\n'
		,'Meter=Shape\n'
		,'MeterStyle=Clip.Box:S\n')
	end

	File:write('[:1]\n'
	,'Meter=String\n'
	,'X=(5*#Scale#+4)\n'
	,'MeterStyle=Clip.Text:S\n')

	for i=1,(MaxClips - 1) do
		File:write('[:'..(i+1)..']\n'
		,'Meter=String\n'
		,'MeterStyle=Clip.Text:S\n')
	end

	File:write('[Image:1]\n'
	,'Meter=Image\n'
	,'X=(5*#Scale#+4)\n'
	,'Y=([Box:1:Y]+5*#Scale#-[Contents:Y])\n'
	,'MeterStyle=Clip.Image:S\n')

	for i=1,(MaxClips - 1) do
		File:write('[Image:'..(i+1)..']\n'
		,'Meter=Image\n'
		,'Y=([Box:'..(i+1)..':Y]+5*#Scale#-[Contents:Y])\n'
		,'MeterStyle=Clip.Image:S\n')
	end

	File:write('[MeasureLine:1]\n'
	,'Measure=Plugin\n'
	,'Plugin=PluginClipboard\n'
	,'OnChangeAction=[!CommandMeasure PSR:M MoveClip][!Delay 100][!CommandMeasure RunCommand:M "Run"][!Delay 2500][!Refresh]\n'
	,'UpdateDivider=1\n'
	,'RegexpSubstitute=1\n'
	,'IfMatch=\\[IMG\\].*$\n'
	,'IfMatchAction=[!SetOption Image:1 ImageName "#@#PowerShell\\Images\\1.png"][!ShowMeter Image:1]\n'
	,'IfNotMatchAction=[!SetOption Image:1 ImageName ""][!HideMeter Image:1]\n'
	,'IfMatch2=^\\[((?!IMG).)*\\].*$\n'
	,'IfMatchAction2=[!CommandMeasure "MeasureLine:1" "Delete"]\n'
	,'Substitute=#ClipSub#\n')

	for i=1,(MaxClips-1) do
		File:write('[MeasureLine:'..(i+1)..']\n'
		,'Measure=Plugin\n'
		,'Plugin=PluginClipboard\n'
		,'OnChangeAction=[!UpdateMeter *][!Redraw]\n'
		,'UpdateDivider=1\n'
		,'RegexpSubstitute=1\n'
		,'IfMatch=\\[IMG\\].*$\n'
		,'IfMatchAction=[!SetOption Image:'..(i+1)..' ImageName "#@#PowerShell\\Images\\'..(i+1)..'.png"][!ShowMeter Image:1]\n'
		,'IfNotMatchAction=[!SetOption Image:'..(i+1)..' ImageName ""][!HideMeter Image:'..(i+1)..']\n'
		,'IfMatch2=^\\[((?!IMG).)*\\].*$\n'
		,'IfMatchAction2=[!CommandMeasure "MeasureLine:'..(i+1)..'" "Delete"]\n'
		,'Substitute=#ClipSub#\n')
	end
	print('written' .. MaxClips)
	SKIN:Bang('!WriteKeyValue', 'Variables', 'MaxScroll', MaxScroll, SkinFile)
	File:close()
end
