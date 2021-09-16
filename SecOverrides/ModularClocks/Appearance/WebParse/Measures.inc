[StartActions]
Measure=calc
OnUpdateAction=[!CommandMeasure mParseTimer "Execute 1"]

[Variables]
Parse=1

[mParseTimer]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Repeat Enable,500,7 | Done
Enable=[!EnableMeasure Image000[#Parse]][!SetVariable Parse (#Parse#+1)][!UpdateMeasureGroup Parsers][!Log "Parsed #Parse#"]
DynamicVariables=1
Group=Parsers
Done=[!Log "Finished parsing [#Parse]-1 items."][!UpdateMeterGroup ParsedDisplay][!Redraw]

; ---------------------------------- Parser ---------------------------------- ;

[Image0001]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image0002]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image0003]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image0004]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image0005]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image0006]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image0007]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image0008]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image0009]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[10]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[11]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[12]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[13]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[14]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[15]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[16]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[17]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[18]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[19]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1