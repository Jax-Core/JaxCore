function Initialize()

	dofile(SKIN:GetVariable('SKINSPATH')..'#JaxCore\\@Resources\\Lua\\HSBLib.lua')
	
	hue = 0.0
    delta = 0.005 * SKIN:GetVariable('RGBSpeed')
	
end

function Update()

	red, green, blue = HSBtoRGB(hue, 1, 1)
	
	hue = Clamp(hue + delta, 0.0, 1.0)
	if hue == 1.0 then hue = 0.0 end	
	
	return red..','..green..','..blue
	
end

function Clamp(num, lower, upper)

	return math.max(lower, math.min(upper, num))
	
end

