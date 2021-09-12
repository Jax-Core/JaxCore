r = 255
g = 0
b = 0
function Update()
    local spd = 5
    if r >= 0 and g >= 0 and g < 255 and b <= 0 then
        b = 0
        r = r - spd
        g = g + spd
    elseif r <= 0 and g and b >= 0 and b < 255 then
        r = 0
        g = g - spd
        b = b + spd
    elseif r >= 0 and r < 255 and g <= 0 and b >= 0 then
        g = 0
        b = b - spd
        r = r + spd
    end
    return (r .. ',' .. g .. ',' .. b)
end