function start(variant, title, description, iconpath, timeout)
	local File = SKIN:GetVariable('SKINSPATH')..'#JaxCore\\Accessories\\Toast\\Main.ini'
    if variant ~= nil then variant = 'Standard' end
	if iconpath ~= nil then iconpath = '#SKINSPATH##JaxCore\\@Resources\\Images\\CoreAssets\\'..SKIN:GetVariable('Set.IconStyle')..'Logo.png' end
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Variant', variant, File)
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Title', title, File)
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Description', description, File)
    SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Icon', iconpath, File)
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Timeout', timeout, File)
	SKIN:Bang('!Activateconfig', '#JaxCore\\Accessories\\Toast')
end