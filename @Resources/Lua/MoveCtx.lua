function Update()
	PosX = (SKIN:GetMeasure('CurPos.X')):GetValue()
	PosY = (SKIN:GetMeasure('CurPos.Y')):GetValue()
	-- if SKIN:GetMeasure('mToggle') ~= nil then print(SKIN:GetMeasure('mToggle')) else print('no') end
	CtxH = (SKIN:GetMeasure('Ctx.H:eX')):GetValue()
	ScrnH = tonumber(SKIN:GetVariable('SCREENAREAHEIGHT', -1))
	if (PosX and (PosY + CtxH) < ScrnH) then
		moveX = PosX
		moveY = PosY
		-- quad 1, 2
	elseif (PosX and (PosY + CtxH) > ScrnH) then
		moveX = PosX
		moveY = PosY - CtxH
		-- quad 3, 4
	else
		error("Invalid Operation")
	end
	SKIN:MoveWindow(moveX, moveY)
	SKIN:Bang('[!CommandMeasure Func "importPosition('..moveX..', '..moveY..')"][!CommandMeasure ActionTimer "Execute 1"]')
end