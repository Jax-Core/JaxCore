function secVLocalGroup(SectionExtract, Option)
	Option = Option or 'SecVar'
	config = SectionExtract:match("(.+:).*")
	Meter = SKIN:GetMeter(config)
	GetVar = Meter:GetOption(Option, 'Error')
	return GetVar
end

function secVCurrentSec(Section, Option)
	Meter = SKIN:GetMeter(Section)
	GetVar = Meter:GetOption(Option, 'Error')
	return GetVar
end