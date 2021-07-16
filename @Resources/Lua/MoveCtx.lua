function Update()
	PosX = (SKIN:GetMeasure('CurPos.X')):GetValue()
	PosY = (SKIN:GetMeasure('CurPos.Y')):GetValue()
	-- CtxW = (SKIN:GetMeasure('Ctx.W:eX')):GetValue()
	CtxH = (SKIN:GetMeasure('Ctx.H:eX')):GetValue()
	ScrnH = tonumber(SKIN:GetVariable('SCREENAREAHEIGHT', -1))
	if (PosX and (PosY + CtxH) < ScrnH) then
		SKIN:MoveWindow(PosX,PosY)
		-- quad 1, 2
	elseif (PosX and (PosY + CtxH) > ScrnH) then
		SKIN:MoveWindow(PosX,(PosY - CtxH))
		-- quad 3, 4
	else
		error("Invalid Operation")
	end
end