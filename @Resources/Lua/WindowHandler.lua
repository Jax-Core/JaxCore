local savedW = 0
local savedH = 0
local savedX = 0
local savedY = 0

-- function ToggleMaximize()
-- 	SKIN:Bang("[!AutoSelectScreen 1]")
-- 	local isMaximized = tonumber(SKIN:GetVariable("WindowMaximized"))
-- 	local WindowPosX = tonumber(SKIN:GetVariable("CURRENTCONFIGX"))
-- 	local WindowPosY = tonumber(SKIN:GetVariable("CURRENTCONFIGY"))
-- 	local windowWidth = tonumber(SKIN:GetVariable("Set.W"))
-- 	local windowHeight = tonumber(SKIN:GetVariable("Set.H"))

-- 	local workAreaX = tonumber(SKIN:GetVariable("WORKAREAX"))
-- 	local workAreaY = tonumber(SKIN:GetVariable("WORKAREAY"))
-- 	local dragMargin = tonumber(SKIN:GetVariable("WindowDragMarginSize"))

-- 	isMaximized = math.abs(-isMaximized + 1) -- switch maximized


-- 	local bang = ""
-- 	bang = bang .. "[!SetVariable WindowMaximized " .. isMaximized .. "]"
-- 	bang = bang .. "[!WriteKeyValue Variables WindowMaximized " .. isMaximized .. "]"
-- 	if isMaximized == 1 then
-- 		bang = bang .. "[!SetVariable WindowPosX (#WORKAREAX# - #WindowDragMarginSize#)][!SetVariable WindowPosY (#WORKAREAY# - #WindowDragMarginSize#)]" 
-- 		bang = bang .. "[!SetVariable WindowW (#WORKAREAWIDTH#)][!SetVariable WindowH (#WORKAREAHEIGHT#)]"
-- 		bang = bang .. "[!WriteKeyValue Variables WindowPosX " .. WindowPosX .. "]" 
-- 		bang = bang .. "[!WriteKeyValue Variables WindowPosY " .. WindowPosY .. "]" 
-- 		bang = bang .. "[!WriteKeyValue Variables WindowW " .. windowWidth .. "]"
-- 		bang = bang .. "[!WriteKeyValue Variables WindowH " .. windowHeight .. "]"
-- 		bang = bang .. "[!HideMeterGroup WindowDragMargin][!UpdateMeter *][!Redraw]"
-- 		bang = bang .. "[!Move ".. (workAreaX - dragMargin) .." ".. (workAreaY - dragMargin).."]"
-- 		bang = bang .. "[!Draggable 0]"

-- 		-- Store positions for future use
-- 		savedX = WindowPosX
-- 		savedY = WindowPosY
-- 		savedW = windowWidth 
-- 		savedH = windowHeight
-- 	else
-- 		bang = bang .. "[!SetVariable WindowPosX " .. savedX .. "][!SetVariable WindowPosY " .. savedY .. "]"
-- 		bang = bang .. "[!SetVariable WindowW " .. savedW .. "][!SetVariable WindowH " .. savedH .. "]"
-- 		bang = bang .. "[!ShowMeterGroup WindowDragMargin][!UpdateMeter *][!Redraw]"
-- 		bang = bang .. "[!Move " .. (savedX) .. " " .. (savedY) .. "]"	
-- 		bang = bang .. "[!Draggable 1]"
-- 	end

-- 	SKIN:Bang(bang)
-- 	print(bang)
-- end

--[[

	Called when the skin refreshes to set the maximize and size variables

]]
-- local function RefreshMaximize()
-- 	local isMaximized = tonumber(SKIN:GetVariable("WindowMaximized"))
-- 	local WindowPosX = tonumber(SKIN:GetVariable("WindowPosX"))
-- 	local WindowPosY = tonumber(SKIN:GetVariable("WindowPosY"))
-- 	local windowWidth = tonumber(SKIN:GetVariable("Set.W"))
-- 	local windowHeight = tonumber(SKIN:GetVariable("Set.H"))

-- 	local workAreaX = tonumber(SKIN:GetVariable("WORKAREAX"))
-- 	local workAreaY = tonumber(SKIN:GetVariable("WORKAREAY"))
-- 	local dragMargin = tonumber(SKIN:GetVariable("WindowDragMarginSize"))

-- 	savedX = WindowPosX
-- 	savedY = WindowPosY
-- 	savedW = windowWidth
-- 	savedH = windowHeight

-- 	if isMaximized == 1 then

-- 		local bang = ""
-- 		bang = bang .. "[!SetVariable WindowPosX #WORKAREAX#][!SetVariable WindowPosY #WORKAREAY#]" 			   			-- Set position variables
-- 		bang = bang .. "[!SetVariable WindowW #WORKAREAWIDTH#][!SetVariable WindowH #WORKAREAHEIGHT#]" 			-- Set size variables
-- 		bang = bang .. "[!UpdateMeter *][!Redraw]"																-- Update and Redraw meters
-- 		bang = bang .. "[!Move ".. (workAreaX - dragMargin) .." " .. (workAreaY - dragMargin) .."]"  			-- Move Window
-- 		bang = bang .. "[!Draggable 0]"
-- 		SKIN:Bang(bang)								
-- 		print(bang)															-- Execute

-- 	else
-- 		local WindowPosX = tonumber(SKIN:GetVariable("CURRENTCONFIGX"))
-- 		local WindowPosY = tonumber(SKIN:GetVariable("CURRENTCONFIGY"))
-- 		savedX = WindowPosX
-- 		savedY = WindowPosY
-- 		SKIN:Bang("[!Move " .. WindowPosX .. " " .. WindowPosY .. "][!SetVariable WindowPosX " .. WindowPosX .. "][!SetVariable WindowPosY " .. WindowPosY .. "][!Draggable 1]")
-- 	end
-- end

local Resizing = false
local ResizeBorder = nil
local offsetX = 0
local offsetY = 0

function round(num, numDecimalPlaces)
	local mult = 10^(numDecimalPlaces or 0)
	return math.floor(num * mult + 0.5) / mult
  end

function MouseMovedCallback(mouseX, mouseY)
	if not Resizing then 
		print("Error, MouseMovedCallback called when not resizing")
		return
	end

	local skinPosX = tonumber(SKIN:GetVariable("CURRENTCONFIGX"))
	local skinPosY = tonumber(SKIN:GetVariable("CURRENTCONFIGY"))
	local windowWidth = tonumber(SKIN:GetVariable("Set.W"))
	local windowHeight = tonumber(SKIN:GetVariable("Set.H"))
	local resolution = 4 / 3
	local scaleWindowWidth = tonumber(SKIN:GetVariable("ScaleWindowW"))
	local minWindowWidth = tonumber(SKIN:GetVariable("MinWindowW"))
	local minWindowHeight = tonumber(SKIN:GetVariable("MinWindowH"))
	local maxWindowWidth = tonumber(SKIN:GetVariable("MaxWindowW"))
	local maxWindowHeight = tonumber(SKIN:GetVariable("MaxWindowH"))
	-- local dragMargin = tonumber(SKIN:GetVariable("WindowDragMarginSize"))
	local dragMargin = 0

	local newWindowX = nil
	local newWindowY = nil
	local newWindowWidth = nil
	local newWindowHeight = nil

	if ResizeBorder == "DragMarginRight" or ResizeBorder == "DragMarginTopRight" or ResizeBorder == "DragMarginBottomRight" then
		newWindowWidth = (mouseX - skinPosX - dragMargin - offsetX)
	end

	if ResizeBorder == "DragMarginBottom" or ResizeBorder == "DragMarginBottomRight" or ResizeBorder == "DragMarginBottomLeft" then
		newWindowHeight = (mouseY - skinPosY - dragMargin - offsetY)
	end

	if ResizeBorder == "DragMarginLeft" or ResizeBorder == "DragMarginBottomLeft" or ResizeBorder == "DragMarginTopLeft" then
		newWindowX = mouseX - offsetX
		newWindowWidth = windowWidth + skinPosX - newWindowX 
	end

	if ResizeBorder == "DragMarginTop" or ResizeBorder == "DragMarginTopLeft" or ResizeBorder == "DragMarginTopRight" then
		newWindowY = mouseY - offsetY
		newWindowHeight = windowHeight + skinPosY - newWindowY 
	end

	local bang = ""

	if newWindowWidth ~= nil then -- if Width is changed then
		if newWindowX ~= nil then
			if newWindowWidth < minWindowWidth then
				newWindowX = newWindowX - minWindowWidth + newWindowWidth
			end
			if newWindowWidth > maxWindowWidth then 
				newWindowX = newWindowX - maxWindowWidth + newWindowWidth
			end
		end
		-- ------------------- make boundaries with min max check ------------------- --
		if newWindowWidth < minWindowWidth then newWindowWidth = minWindowWidth end
		if newWindowWidth > maxWindowWidth then newWindowWidth = maxWindowWidth end
		-- --------------------------------- scalingW -------------------------------- --
		-- if true then
		-- when hori
			-- if newWindowWidth < scaleWindowWidth then
			-- 	-- when < sW
			-- 	local scaling = newWindowWidth / scaleWindowWidth
			-- 	bang = bang .. "[!SetOption Set.S Formula " .. scaling .. "][!UpdateMeasure Set.S]" 
			-- 	-- When hori & >= sW & W exclusive movement : 1
			-- 	-- When hori & >= sW & WH movement : H
			-- elseif newWindowWidth >= scaleWindowWidth and newWindowHeight == nil then
			-- 	bang = bang .. "[!SetOption Set.S Formula 1][!UpdateMeasure Set.S]" 
			-- end
		-- elseif windowHeight > newWindowWidth then
		-- -- when vert
		-- 	if 
		-- end
		if newWindowWidth < (windowHeight * resolution) then
			local scaling = round((newWindowWidth / scaleWindowWidth), 2)
			if scaling > 1 then scaling = 1 end
			bang = bang .. "[!SetOption Set.S Formula " .. scaling .. "][!UpdateMeasure Set.S]" 
		end
		-- ------------------------- set variable for width ------------------------- --
		bang = bang .. "[!SetVariable Set.W " .. newWindowWidth .. "]" 
	end

	if newWindowHeight ~= nil then -- if Height is changed then
		if newWindowY ~= nil then
			if newWindowHeight < minWindowHeight then
				newWindowY = newWindowY - minWindowHeight + newWindowHeight
			end
			if newWindowHeight > maxWindowHeight then 
				newWindowY = newWindowY - maxWindowHeight + newWindowHeight
			end
		end
		-- ------------------- make boundaries with min max check ------------------- --
		if newWindowHeight < minWindowHeight then newWindowHeight = minWindowHeight end
		if newWindowHeight > maxWindowHeight then newWindowHeight = maxWindowHeight end
		-- --------------------------------- scalingH -------------------------------- --
		if newWindowHeight < (windowWidth / resolution) then
			local scaling = round((newWindowHeight / (scaleWindowWidth / resolution)), 2)
			if scaling > 1 then scaling = 1 end
			bang = bang .. "[!SetOption Set.S Formula " .. scaling .. "][!UpdateMeasure Set.S]"
		end
		-- ------------------------- set variable for height ------------------------- --
		bang = bang .. "[!SetVariable Set.H " .. newWindowHeight .. "]" 
	end
	
	if bang ~= "" then
		--bang = bang .. "[!UpdateMeterGroup Window][!Redraw]" TODO When clip is implemented?
		bang = bang .. "[!UpdateMeter *][!Redraw]"

	end

	if newWindowX ~= nil and newWindowY ~= nil then
		bang = bang .. "[!Move " .. newWindowX .. " " .. newWindowY .. "]"
	elseif newWindowX ~= nil then
		bang = bang .. "[!Move " .. newWindowX .. " " .. skinPosY .. "]"
	elseif newWindowY ~= nil then
		bang = bang .. "[!Move " .. skinPosX .. " " .. newWindowY .. "]"
	end

	SKIN:Bang(bang)	
end

function LeftMouseUpCallback(mouseX, mouseY)
	bang = "[!CommandMeasure ScriptMouseHandler UnsubscribeMouseEvent('WindowHandler','MouseMove')]"
	bang = bang .. "[!CommandMeasure ScriptMouseHandler UnsubscribeMouseEvent('WindowHandler','LeftMouseUp')]"
	local skinPosX = tonumber(SKIN:GetVariable("CURRENTCONFIGX"))
	local skinPosY = tonumber(SKIN:GetVariable("CURRENTCONFIGY"))
	local windowWidth = tonumber(SKIN:GetVariable("Set.W"))
	local windowHeight = tonumber(SKIN:GetVariable("Set.H"))
	local currentScale = tonumber((SKIN:GetMeasure("Set.S")):GetValue())
	bang = bang .. "[!WriteKeyValue Variables WindowPosX " .. skinPosX .. ' "#@#Includes\\Window.ini"]' 							   			-- Write X pos in case of refresh
	bang = bang .. "[!WriteKeyValue Variables WindowPosY " .. skinPosY .. ' "#@#Includes\\Window.ini"]' 							   			-- Write Y pos in case of refresh
	bang = bang .. "[!WriteKeyValue Variables Set.W " .. windowWidth .. ' "#@#Includes\\Window.ini"]' 					   			-- Write Width in case of refresh
	bang = bang .. "[!WriteKeyValue Variables Set.H " .. windowHeight .. ' "#@#Includes\\Window.ini"]' 					   			-- Write Height in case of refresh
	bang = bang .. "[!WriteKeyValue Set.S Formula " .. currentScale .. ' "#@#Vars.inc"]' 					   			-- Write Scale in case of refresh
	bang = bang .. "[!UpdateMeter *][!Redraw]"

	SKIN:Bang(bang)
	ResizeBorder = nil
	Resizing = false
end

function ResizeWindow(border, mouseX, mouseY)
	local mouseHandler = SKIN:GetMeasure("ScriptMouseHandler")
	if mouseHandler == nil then
		print("Mouse handler not found, include module ScriptMouseHandler")
		return
	end
	ResizeBorder = border
	Resizing = true
	bang = "[!CommandMeasure ScriptMouseHandler SubscribeMouseEvent('MouseMovedCallback','WindowHandler','MouseMove')]"
	bang = bang .. "[!CommandMeasure ScriptMouseHandler SubscribeMouseEvent('LeftMouseUpCallback','WindowHandler','LeftMouseUp')]"
	SKIN:Bang(bang)
	offsetX = mouseX
	offsetY = mouseY
end

function Initialize()
end