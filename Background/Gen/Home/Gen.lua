function Update()
    local file = io.open(SKIN:GetVariable('SKINSPATH')..'#JaxCore\\Background\\Gen\\Home\\List.txt','r')
    local filewrite = io.open(SKIN:GetVariable('SKINSPATH')..'#JaxCore\\Core\\#Home.inc','w')
    local count = 0
    for line in file:lines() do
        local name = string.gsub(line, "%s|.*$", "")
        local tags = string.gsub(line, "^.*|", "")
        if count == 0 then
            count = 1
            filewrite:write(
            '['.. name ..']\n'
            ,'Meter=Image\n'
            ,'X=r\n'
            ,'Y=(10*[Set.S])R\n'
            ,'ImageName=#@#Images\\Cards\\'.. name ..'.png\n'
            ,'MeterStyle=SkinIcon:S\n'
            ,'['.. name ..'Des]\n'
            ,'Meter=String\n'
            ,'MeterStyle=Set.String:S | SkinText:S\n'
            ,'Text='.. name ..'#CRLF#'.. tags ..'\n')
        elseif count < 3 or count > 3 and count < 6 then
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
        elseif count == 3 then
            count = count + 1
            filewrite:write(
            '[All]\n'
            ,'Meter=String\n'
            ,'Text=All Skins\n'
            ,'MeterStyle=Set.String:S\n'
            ,'X=(#Set.P#)\n'
            ,'Y=(35*[Set.S])R\n'
            ,'FontSize=(15*[Set.S])\n'
            ,'StringAlign=LeftTop\n'
            ,'FontFace=Poppins SemiBold\n'
            )
            filewrite:write(
            '['.. name ..']\n'
            ,'Meter=Image\n'
            ,'X=r\n'
            ,'Y=(10*[Set.S])R\n'
            ,'ImageName=#@#Images\\Cards\\'.. name ..'.png\n'
            ,'MeterStyle=SkinIcon:S\n'
            ,'['.. name ..'Des]\n'
            ,'Meter=String\n'
            ,'MeterStyle=Set.String:S | SkinText:S\n'
            ,'Text='.. name ..'#CRLF#'.. tags ..'\n')
        elseif count == 6 then
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
    


    file:close()
    filewrite:close()
  end