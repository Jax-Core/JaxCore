function Update()
    local function indexOf(array, value)
        for i, v in ipairs(array) do
            if v == value then
                return i
            end
        end
        return nil
    end
    local file = io.open(SKIN:GetVariable('SKINSPATH')..'#JaxCore\\Accessories\\Gen\\Home\\List.txt','r')
    local filewrite = io.open(SKIN:GetVariable('SKINSPATH')..'#JaxCore\\Core\\Home\\Generated.inc','w')
    totalLines = 0
    row = {}
    for line in file:lines() do
        totalLines = totalLines + 1
        row[totalLines] = line
    end
    numberModules = indexOf(row, '===') - 1
    local count = 0
    for i = 1, numberModules do
        local name = string.gsub(row[i], "%s|.*$", "")
        local tags = string.gsub(row[i], "^.*|", "")
        if count == 0 then
            count = 1
            filewrite:write(
            '['.. name ..']\n'
            ,'Meter=Image\n'
            ,'X=r\n'
            ,'Y=([RecommendedSkins:H]*([Set.S]-1)+10*[Set.S])R\n'
            ,'ImageName=#@#Images\\Cards\\'.. name ..'.png\n'
            ,'MeterStyle=SkinIcon:S\n'
            ,'['.. name ..'Des]\n'
            ,'Meter=String\n'
            ,'MeterStyle=Set.String:S | SkinText:S\n'
            ,'Text='.. name ..'#CRLF#'.. tags ..'\n')
        elseif count < 3 or count > 3 and count < 6 or count > 6 then
            count = count + 1
            filewrite:write(
            '['.. name ..']\n'
            ,'Meter=Image\n'
            ,'ImageName=#@#Images\\Cards\\'.. name ..'.png\n'
            ,'MeterStyle=SkinIcon:S\n'
            ,'['.. name ..'Des]\n'
            ,'Meter=String\n'
            ,'MeterStyle=Set.String:S | SkinText:S\n'
            ,'Text='.. name ..'#CRLF#'.. tags ..'\n')
        elseif count == 3 or count == 6 then
            count = count + 1
            filewrite:write(
            '['.. name ..']\n'
            ,'Meter=Image\n'
            ,'X=(#Set.P#)\n'
            ,'Y=(10*[Set.S])R\n'
            ,'ImageName=#@#Images\\Cards\\'.. name ..'.png\n'
            ,'MeterStyle=SkinIcon:S\n'
            ,'['.. name ..'Des]\n'
            ,'Meter=String\n'
            ,'MeterStyle=Set.String:S | SkinText:S\n'
            ,'Text='.. name ..'#CRLF#'.. tags ..'\n')
        end
    end
    filewrite:close()
    local filewrite2 = io.open(SKIN:GetVariable('SKINSPATH')..'#JaxCore\\Core\\Home\\Generated2.inc','w')
    local count = 0
    print(count, numberModules, totalLines)
    for i = numberModules + 2, totalLines do
        local name = string.gsub(row[i], "%s|.*$", "")
        local tags = string.gsub(row[i], "^.*|", "")
        if count == 0 then
            count = 1
            filewrite2:write(
            '['.. name ..']\n'
            ,'Meter=Image\n'
            ,'X=r\n'
            ,'Y=([RecommendedSkins:H]*([Set.S]-1)+10*[Set.S])R\n'
            ,'ImageName=#@#Images\\Cards\\'.. name ..'.png\n'
            ,'MeterStyle=SkinIcon:S\n'
            ,'['.. name ..'Des]\n'
            ,'Meter=String\n'
            ,'MeterStyle=Set.String:S | SkinText:S\n'
            ,'Text='.. name ..'#CRLF#'.. tags ..'\n')
        elseif count < 3 or count > 3 and count < 6 or count > 6 then
            count = count + 1
            filewrite2:write(
            '['.. name ..']\n'
            ,'Meter=Image\n'
            ,'ImageName=#@#Images\\Cards\\'.. name ..'.png\n'
            ,'MeterStyle=SkinIcon:S\n'
            ,'['.. name ..'Des]\n'
            ,'Meter=String\n'
            ,'MeterStyle=Set.String:S | SkinText:S\n'
            ,'Text='.. name ..'#CRLF#'.. tags ..'\n')
        elseif count == 3 or count == 6 then
            count = count + 1
            filewrite2:write(
            '['.. name ..']\n'
            ,'Meter=Image\n'
            ,'X=(#Set.P#)\n'
            ,'Y=(10*[Set.S])R\n'
            ,'ImageName=#@#Images\\Cards\\'.. name ..'.png\n'
            ,'MeterStyle=SkinIcon:S\n'
            ,'['.. name ..'Des]\n'
            ,'Meter=String\n'
            ,'MeterStyle=Set.String:S | SkinText:S\n'
            ,'Text='.. name ..'#CRLF#'.. tags ..'\n')
        end
    end
    filewrite2:close()
    


    file:close()
  end