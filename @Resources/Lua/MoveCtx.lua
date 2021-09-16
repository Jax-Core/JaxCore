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

function openSub(handler)
	if handler == nil then print('no handler found') end
	local PosX = SKIN:GetX()
	local PosY = SKIN:GetY()
	local Skin = SKIN:GetVariable('Sec.Skin')
	SKIN:Bang('!ActivateConfig', '#JaxCore\\Ctx\\Submenu', 'Pos.ini')
	SKIN:Bang('!Move', PosX, PosY, '#JaxCore\\Ctx\\Submenu')
	SKIN:Bang('!SetVariable', 'Sec.Skin', Skin, '#JaxCore\\Ctx\\Submenu')
	SKIN:Bang('!SetVariable', 'CCW', SKIN:GetVariable('CCW'), '#JaxCore\\Ctx\\Submenu')
	SKIN:Bang('!SetVariable', 'CCH', SKIN:GetVariable('CCH'), '#JaxCore\\Ctx\\Submenu')
end