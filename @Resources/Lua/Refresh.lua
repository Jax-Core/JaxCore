
function Initialize()
	r = SKIN:GetVariable('ROOTCONFIGPATH')
	if SELF:GetOption("Refreshed", "0") == "0" then
		SKIN:Bang("!WriteKeyValue", SELF:GetName(), "Refreshed", "1", r.."Core\\Info.inc")
		SKIN:Bang("!Refresh")
	else
		SKIN:Bang("!WriteKeyValue", SELF:GetName(), "Refreshed", "0", r.."Core\\Info.inc")
	end
end