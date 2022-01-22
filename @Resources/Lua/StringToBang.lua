function parse(banginput)
    print(banginput)
    local bang = SKIN:ReplaceVariables(banginput)
    print(bang)
    SKIN:Bang(bang)
end