function Initialize()
    -- SKIN:Bang('[!SetTransparency 20]')
    AniSteps = tonumber(SKIN:GetVariable('Animation_Steps'))
    TweenInterval = 100 / AniSteps
    Offset = SKIN:GetVariable('Animate_Offset')
    AniDir = SKIN:GetVariable('AniDir')
    dofile(SELF:GetOption("ScriptFile"):match("(.*[/\\])") .. "tween.lua")
    subject = {
        TweenNode = 0
    }
    t = tween.new(AniSteps, subject, {TweenNode=100}, SKIN:GetVariable('Easetype'))
    anchorX = 0
    anchorY = 0
end

function importPosition(x, y, ax, ay)
    if ax == nil then ax = 0 end
    if ay == nil then ay = 0 end
    moveX = x
    moveY = y
    anchorX = ax
    anchorY = ay
end


function tweenAnimation(dir)
    if dir == 'in' then 
        local complete = t:update(1)
    else
        local complete = t:update(-1)
    end
    resultantTN = subject.TweenNode
    if resultantTN > 100 then resultantTN = 100 elseif resultantTN < 0 then resultantTN = 0 end
    local bang = ''
    if AniDir == 'Left' then
        bang = bang..'[!SetWindowPosition '..moveX + (resultantTN / 100 - 1) * Offset..' '..moveY..' '..anchorX..' '..anchorY..']'
    elseif AniDir == 'Right' then
        bang = bang..'[!SetWindowPosition '..moveX + (1 - resultantTN / 100) * Offset..' '..moveY..' '..anchorX..' '..anchorY..']'
    elseif AniDir == 'Top' then
        bang = bang..'[!SetWindowPosition '..moveX..' '..moveY + (resultantTN / 100 - 1) * Offset..' '..anchorX..' '..anchorY..']'
    elseif AniDir == 'Bottom' then
        bang = bang..'[!SetWindowPosition '..moveX..' '..moveY + (1 - resultantTN / 100) * Offset..' '..anchorX..' '..anchorY..']'
    end
    bang = bang..'[!UpdateMeasure ActionTimer]'
    SKIN:Bang(bang)
end