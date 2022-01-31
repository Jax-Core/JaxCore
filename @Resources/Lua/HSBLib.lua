function RGBtoHSB(colorArg)
	
	inRed, inGreen, inBlue = string.match(colorArg, '(%d+),(%d+),(%d+)')
	
	percentR = ( inRed / 255 )
	percentG = ( inGreen / 255 )
	percentB = ( inBlue / 255 )

	colorMin = math.min( percentR, percentG, percentB )
	colorMax = math.max( percentR, percentG, percentB )
	deltaMax = colorMax - colorMin

	colorBrightness = colorMax

	if (deltaMax == 0) then
		colorHue = 0
		colorSaturation = 0
	else
		colorSaturation = deltaMax / colorMax

		deltaR = (((colorMax - percentR) / 6) + (deltaMax / 2)) / deltaMax
		deltaG = (((colorMax - percentG) / 6) + (deltaMax / 2)) / deltaMax
		deltaB = (((colorMax - percentB) / 6) + (deltaMax / 2)) / deltaMax

		if (percentR == colorMax) then
			colorHue = deltaB - deltaG
		elseif (percentG == colorMax) then 
			colorHue = ( 1 / 3 ) + deltaR - deltaB
		elseif (percentB == colorMax) then 
			colorHue = ( 2 / 3 ) + deltaG - deltaR
		end

		if ( colorHue < 0 ) then colorHue = colorHue + 1 end
		if ( colorHue > 1 ) then colorHue = colorHue - 1 end
		
	end

	return colorHue, colorSaturation, colorBrightness

end

function HSBtoRGB(colorHue, colorSaturation, colorBrightness)
	
		degreesHue = colorHue * 6
		if (degreesHue == 6) then degreesHue = 0 end
		degreesHue_int = math.floor(degreesHue)
		percentSaturation1 = colorBrightness * (1 - colorSaturation)
		percentSaturation2 = colorBrightness * (1 - colorSaturation * (degreesHue - degreesHue_int))
		percentSaturation3 = colorBrightness * (1 - colorSaturation * (1 - (degreesHue - degreesHue_int)))
		if (degreesHue_int == 0)  then
			percentR = colorBrightness
			percentG = percentSaturation3
			percentB = percentSaturation1
		elseif (degreesHue_int == 1) then
			percentR = percentSaturation2
			percentG = colorBrightness
			percentB = percentSaturation1
		elseif (degreesHue_int == 2) then
			percentR = percentSaturation1
			percentG = colorBrightness
			percentB = percentSaturation3
		elseif (degreesHue_int == 3) then
			percentR = percentSaturation1
			percentG = percentSaturation2
			percentB = colorBrightness
		elseif (degreesHue_int == 4) then
			percentR = percentSaturation3
			percentG = percentSaturation1
			percentB = colorBrightness
		else
			percentR = colorBrightness
			percentG = percentSaturation1
			percentB = percentSaturation2
		end
 
		outRed = math.floor(percentR * 255)
		outGreen = math.floor(percentG * 255)
		outBlue = math.floor(percentB * 255)
		
		if (outRed < 0 or outGreen < 0 or outBlue < 0)
		or (outRed > 255 or outGreen > 255 or outBlue > 255) then
			return inRed, inGreen, inBlue
		else
			return outRed, outGreen, outBlue
		end
	
end
