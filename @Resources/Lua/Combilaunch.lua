posArray = {'100,25' , '125,50' , '150,75' , '75,50' , '100,75' , '125,100' , '50,75' , '75,100' , '100,125'}
posArray2 = {'250,100' , '300,150' , '350,200' , '200,150' , '250,200' , '300,250' , '150,200' , '200,250' , '250,300'}

function exportPath(option, sec)
    local chain = SKIN:GetMeter(sec):GetOption(option)
    local node1 = tonumber(chain:sub(1, 1))
    local initPos = posArray[node1]
    local chainLen = string.len(chain)
    local result = initPos
    for i = 2, chainLen do
        result = result .. ' | LineTo ' .. posArray[tonumber(chain:sub(i, i))]
    end
    return(result)
end

function exportPath2(chain)
    local node1 = tonumber(chain:sub(1, 1))
    local initPos = posArray2[node1]
    local chainLen = string.len(chain)
    local result = initPos
    for i = 2, chainLen do
        result = result .. ' | LineTo ' .. posArray2[tonumber(chain:sub(i, i))]
    end
    return(result)
end

function getOption(option, sec)
    result = SKIN:GetMeter(sec):GetOption(option)
    return(result)
end

function getFix(chain)
    local result = 0
    if string.find(chain, '1') then
        result = 0
    elseif string.find(chain, '4') or string.find(chain, '2') then
        result = 25
    elseif string.find(chain, '3') or string.find(chain, '5') or string.find(chain, '7') then
        result = 50
    else
        result = 75
    end
    print(result)
    return(result)
end

function Start(section)
    local sectionNum = string.gsub(section, 'Shape', '')
    local location = SKIN:GetVariable('SKINSPATH')
    local location = location .. '\\#JaxCore\\Accessories\\Combilaunch\\Main.ini'
    local cfgX = SKIN:GetVariable('CURRENTCONFIGX')
    local cfgY = SKIN:GetVariable('CURRENTCONFIGY')
    local cfgW = SKIN:GetVariable('CURRENTCONFIGWIDTH')
    local cfgH = SKIN:GetVariable('CURRENTCONFIGHEIGHT')
    local scale = SKIN:GetMeasure('Set.S'):GetValue()
    local text = SKIN:GetMeter(sectionNum .. 'Text'):GetOption('Text')
    local chain = SKIN:GetMeter(sectionNum .. 'Shape'):GetOption('Chain')
    local mX = cfgX + cfgW/2 - 500 * scale / 2
    local mY = cfgY + cfgH/2 - 600 * scale / 2
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.Sec', sectionNum, location)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.Text', text, location)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'Sec.Chain', chain, location)
    SKIN:Bang('!ActivateConfig', '#JaxCore\\Accessories\\Combilaunch')
    SKIN:Bang('!Move', mX, mY, '#JaxCore\\Accessories\\Combilaunch')
    return
end