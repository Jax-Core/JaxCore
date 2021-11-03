function Initialize()
    ini = ReadIni(SKIN:GetVariable('SETTINGSPATH') .. 'Rainmeter.ini')
    local skin = SKIN:GetVariable('Skin.name')
    print(ini.INI[skin..'\\Main']['ClickThrough'])
end

function ReadIni(inputfile)
    local file = assert(io.open(inputfile, 'r'), 'Unable to open ' .. inputfile)
    local tbl, section = {}
    local sectionReadOrder, keyReadOrder = {}, {}
    local num = 0
    for line in file:lines() do
        --print(line)
        num = num + 1
        if not line:match('^%s-;') then
            local key, command = line:match('^([^=]+)=(.+)')
            if line:match('^%s-%[.+') then
                section = line:match('^%s-%[([^%]]+)')
                if not tbl[section] then
                    tbl[section]={}
                    table.insert(sectionReadOrder, section)
                    if not keyReadOrder[section] then keyReadOrder[section]={} end
                end
            elseif key and command and section then
                tbl[section][key:match('^%s*(%S*)%s*$')] = command:match('^%s*(.-)%s*$')
                if not tbl[section]['keys'] then tbl[section]['keys']={} end
                if not tbl[section]['values'] then tbl[section]['values']={} end
                table.insert(tbl[section]['keys'], key:match('^%s*(%S*)%s*$'))
                table.insert(tbl[section]['values'], command:match('^%s*(.-)%s*$'))
            elseif #line > 0 and section and not key or command then
                print(num .. ': Invalid property or value.')
            end
        end
    end
    file:close()

    if not section then print('No sections found in ' .. inputfile) return end

    local finalTable={}
    finalTable.INI=tbl
    finalTable.SectionOrder=sectionReadOrder
    finalTable.KeyOrder=keyReadOrder
    return finalTable
end

function WriteIni(inputtable, filename)
	assert(type(inputtable) == 'table', ('WriteIni must receive a table. Received %s instead.'):format(type(inputtable)))

	local file = assert(io.open(filename, 'w'), 'Unable to open ' .. filename)
	local lines = {}

	for section, contents in pairs(inputtable) do
		table.insert(lines, ('\[%s\]'):format(section))
		for key, value in pairs(contents) do
			table.insert(lines, ('%s=%s'):format(key, value))
		end
		table.insert(lines, '')
	end

	file:write(table.concat(lines, '\r\n'))
	file:close()
end

function tablelength(T)
    local count = 0
    for _ in pairs(T) do count = count + 1 end
    -- print(count)
    return count
  end

-- function ChangeTo(theme)
--     Skinpath = SKIN:GetVariable('SKINSPATH')
--     SkinName = SKIN:GetVariable('Skin.Name')
--     ini = ReadIni(Skinpath..SkinName..'\\@Resources\\Presets\\'..theme..'.inc')
--     saveLocation = Skinpath..SkinName..'\\@Resources\\Vars.inc'
--     for i = 1, tablelength(ini.INI['Values']['keys']) do
--         SKIN:Bang('!WriteKeyValue', 'Variables', ini.INI['Values']['keys'][i], ini.INI['Values']['values'][i], saveLocation)
--     end
-- end