
function GenDrive(DriveCount, DriveChar)
	local File = io.open(SKIN:GetVariable('SKINSPATH')..'Plainext\\Main\\@1\\Drives.inc','w')
    t={}
    DriveChar:gsub(".",function(c) table.insert(t,c) end)
	-- /////////////////////////////////////////////////////////
	-- /////////////////////////////////////////////////////////
	for i=1,DriveCount do
		File:write('[ResourceGraphDrives'..t[i]..']\n'
		,'Meter=String\n'
		,"Autoscale=1\n"
		,'MeasureName=Drive'..t[i]..'Free\n'
		,'MeasureNAme2=Drive'..t[i]..'Total\n'
		,'MeasureName3=CalcDrive'..t[i]..'Read\n'
		,'MeasureNAme4=CalcDrive'..t[i]..'Write\n'
		,'Text='..t[i]..': //////////////////// [Drive'..t[i]..'Percent:1]%#CRLF#F: %1B T: %2B | R: %3 W: %4\n'
		,'InlineSetting=Color | #BarColor#\n'
		,'InlinePattern=\\/\n'
		,'InlineSetting2=Color | #Accent#\n'
		,'InlinePattern2='..t[i]..': (\/{[Drive'..t[i]..'Actual:0]}).*\n'
		,'DynamicVariables=1\n'
		,'MEterStyle=Text\n'
		,'\n'
		,'[Drive'..t[i]..'Total]\n'
		,'Measure=FreeDiskSpace\n'
		,'Total=1\n'
		,'Drive='..t[i]..':\n'
		,'UpdateDivider=120\n'
		,'Substitute=^0$":"0.000001"\n'
		,'\n'
		,'[Drive'..t[i]..'Free]\n'
		,'Measure=FreeDiskSpace\n'
		,'Drive='..t[i]..':\n'
		,'UpdateDivider=120\n'
		,'Substitute="^0$":"0.000001"\n'
		,'\n'
		,'[Drive'..t[i]..'Percent]\n'
		,'Measure=Calc\n'
		,'Formula=(Drive'..t[i]..'Total-Drive'..t[i]..'Free)/Drive'..t[i]..'Total*100\n'
		,'UpdateDivider=120\n'
		,'\n'
		,'[Drive'..t[i]..'Actual]\n'
		,'Measure=Calc\n'
		,'Formula=Drive'..t[i]..'Percent/5\n'
		,'UpdateDivider=120\n'
		,'\n'
		,'[MeasureDrive'..t[i]..'Read]\n'
		,'Measure=Plugin\n'
		,'Plugin=UsageMonitor\n'
		,'Category=LogicalDisk\n'
		,'Counter=Disk Read Bytes/sec\n'
		,'Name='..t[i]..':\n'
		,'\n'
		,'[MeasureDrive'..t[i]..'Write]\n'
		,'Measure=Plugin\n'
		,'Plugin=UsageMonitor\n'
		,'Category=LogicalDisk\n'
		,'Counter=Disk Write Bytes/sec\n'
		,'Name='..t[i]..':\n'
		,'\n'	
		,'[CalcDrive'..t[i]..'Read]\n'
		,'Measure=calc\n'
		,'Formula=MeasureDrive'..t[i]..'Read\n'
		,'\n'
		,'[CalcDrive'..t[i]..'Write]\n'
		,'Measure=Calc\n'
		,'Formula=MeasureDrive'..t[i]..'Write\n')
	end

	File:write('[Dot5]\n'
	,'Meter=String\n'
	,'MeterStyle=Dots')

	print('written' .. DriveCount)
	File:close()
end
