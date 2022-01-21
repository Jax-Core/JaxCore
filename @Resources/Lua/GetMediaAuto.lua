mediaPlayers = {'AIMP', 'CAD', 'WMP', 'iTunes', 'Winamp', 'WebNowPlaying'}
-- -------------------------------------------------------------------------- --
--                                    Media                                   --
-- -------------------------------------------------------------------------- --

function checkMediaAuto()
    currentPlayer = nil
    for i = 1, 6 do
        if SKIN:GetMeasure('state'..mediaPlayers[i]):GetValue() == 1 then
            currentPlayer = mediaPlayers[i]
            break
        end
    end
    if currentPlayer == nil then
        for i = 1, 6 do
            if SKIN:GetMeasure('state'..mediaPlayers[i]):GetValue() == 2 then
                currentPlayer = mediaPlayers[i]
                break
            end
        end
    end
    if currentPlayer == nil then currentPlayer = SKIN:GetVariable('NowPlayingMedia') end

    checkingPlayer = currentPlayer

    checkingPlayerState = SKIN:GetMeasure('state'..checkingPlayer):GetValue()

    -- print(checkingPlayer, checkingPlayerState)
    if checkingPlayerState ~= 0 then
        if checkingPlayer == 'WebNowPlaying' then
            SKIN:Bang('[!EnableMeasureGroup WNP][!DisableMeasureGroup NP]')
            SKIN:Bang('[!SetVariable PlayerType WNP]')

            if SKIN:GetVariable('FetchImage') == 0 then
                SKIN:Bang('[!DisableMeasure wnpCover]')
            end
        else 
            SKIN:Bang('[!EnableMeasureGroup NP][!DisableMeasureGroup WNP]')
            SKIN:Bang('[!SetVariable PlayerType NP]')

            if SKIN:GetVariable('FetchImage') == 0 then
                SKIN:Bang('[!DisableMeasure npCover]')
            end
        end
    else
        SKIN:Bang('[!DisableMeasureGroup NP][!DisableMeasureGroup WNP]')
    end
        
    SKIN:Bang('[!SetVariable NowPlayingMedia '..checkingPlayer..']')
    SKIN:Bang('[!UpdateMeasureGroup Music]')
    
    SKIN:Bang('[!UpdateMeter *][!Redraw]')
end