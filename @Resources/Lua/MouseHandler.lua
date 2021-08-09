local Events = {
	MouseMove = {},
	LeftMouseDown = {},
	LeftMouseUp = {},
}

function SubscribeMouseEvent(callbackFunc, measureName, eventType)
	if Events[eventType] == nil then
		print("Mouse event type:", eventType, "does not exist")
		return
	end

	if measureName == nil or callbackFunc == nil then
		print("Could not subscribe to event. MeasureName or Callbackfunction was nil")
		return
	end
	Events[eventType][measureName] = callbackFunc
end

function UnsubscribeMouseEvent(measureName, eventType)
	if Events[eventType] == nil then
		print("Mouse event type:", eventType, "does not exist")
		return
	end

	if measureName == nil then
		print("Could not unsubscribe from event. MeasureName was nil")
		return
	end

	if Events[eventType][measureName] == nil then
		print("No callback subscribed to event ", eventType, " for measure ", measureName)
		return
	end
	Events[eventType][measureName] = nil
end

function MouseMove(mouseX, mouseY)
	for measure, callback in pairs(Events["MouseMove"]) do
		bang = "[!CommandMeasure ".. measure .." " .. callback .."(" .. mouseX .. "," .. mouseY .. ")]"
		SKIN:Bang(bang)
	end
end

function LeftMouseReleased(mouseX, mouseY)
	for measure, callback in pairs(Events["LeftMouseUp"]) do
		bang = "[!CommandMeasure ".. measure .." " .. callback .."(" .. mouseX .. "," .. mouseY .. ")]"
		SKIN:Bang(bang)
	end
end

function Initialize()

end