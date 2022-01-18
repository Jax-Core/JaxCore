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

function openSub()
	SKIN:Bang('[!WriteKeyvalue Variables Sec.Skin '..SKIN:GetVariable('Ctx.Parent')..' "#ROOTCONFIGPATH#Ctx\\Submenu\\Pos.ini"][!WriteKeyvalue Variables Ctx.LastX '..moveX..' "#ROOTCONFIGPATH#Ctx\\Submenu\\Pos.ini"][!WriteKeyvalue Variables Ctx.LastY '..moveY..' "#ROOTCONFIGPATH#Ctx\\Submenu\\Pos.ini"][!ActivateConfig "#JaxCore\\Ctx\\Submenu"]')
	SKIN:Bang('!SetVariable', 'CCW', SKIN:GetVariable('CCW'), '#JaxCore\\Ctx\\Submenu')
	SKIN:Bang('!SetVariable', 'CCH', SKIN:GetVariable('CCH'), '#JaxCore\\Ctx\\Submenu')
	SKIN:Bang('!SetVariable', 'SKINX', SKIN:GetVariable('SKINX'), '#JaxCore\\Ctx\\Submenu')
	SKIN:Bang('!SetVariable', 'SKINY', SKIN:GetVariable('SKINY'), '#JaxCore\\Ctx\\Submenu')
end