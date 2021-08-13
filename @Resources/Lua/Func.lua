-- ScrollTiming,LastScroll,ScrollTiming2 = 0,0,0
-- ScrollSpeed=200
-- ScrollDur=20
-- Result is Speed * Duration

-- function Update()
-- 	pos = tonumber(SKIN:GetVariable('Scroll'))
-- 	PageHeight = tonumber(SKIN:GetVariable('Set.Home.PageH'))
-- 	if ScrollTiming > 0 and ScrollTiming < ScrollDur then
-- 		if (LastScroll + ScrollTiming/ScrollDur*ScrollSpeed*ScrollDirection) >= (PageHeight) then
-- 			SKIN:Bang('!SetVariable Scroll '..(PageHeight))
-- 			LastScroll = PageHeight
-- 			ScrollTiming = 11
-- 		elseif (LastScroll + ScrollTiming/ScrollDur*ScrollSpeed*ScrollDirection) <= 0 then
-- 			SKIN:Bang('!SetVariable Scroll 0')
-- 			LastScroll = 0
-- 			ScrollTiming = 11
-- 		else
-- 			ScrollTiming = ScrollTiming + 1
-- 			SKIN:Bang('!SetVariable Scroll '..(LastScroll + ScrollTiming/ScrollDur*ScrollSpeed*ScrollDirection))
-- 		SKIN:Bang('!UpdateMeterGroup Scroll')
-- 		SKIN:Bang('!Redraw')
-- 		end
-- 	elseif ScrollTiming == ScrollDur then
-- 		ScrollTiming=ScrollDur + 1
-- 	end
-- end

function GroupVar(SectionExtract, Option)
	Option = Option or 'SecVar'
	config = SectionExtract:match("(.+:).*")
	Meter = SKIN:GetMeter(config)
	GetVar = Meter:GetOption(Option, 'Error')
	return GetVar
end

function LocalVar(Section, Option)
	Meter = SKIN:GetMeter(Section)
	GetVar = Meter:GetOption(Option, 'Error')
	return GetVar
end